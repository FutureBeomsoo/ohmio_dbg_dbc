#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "UtilityLib/Timer.h"
#include "commonInclude.h"
#include <mutex>

namespace OhmioModel
{
	//! GPS status
	enum class GpsQuality
	{
		invalid = 0,
		singlePoint = 1,
		pseudoRangeDifferential = 2,
		unused = 3,
		fixedSolution = 4,
		floatingSolution = 5,
		estimating = 6,
		Manual = 7,
		Simulation = 8,
		WAAS = 9,

		// Always add before this point
		last
	};

	//! A location in latitude, longitude
	class LatLong
	{
	public:
		LatLong() : Longitude(0), Latitude(0) {} //! init to (0,0)
		double Longitude;	//!< Longitude (degrees)
		double Latitude;	//!< Latitude (degrees)
	};

	//! A UWB distance - distance from front and rear and time stamp
	class DistanceData
	{
	public:
		DistanceData() : front(0), rear(0), timeMsec(0) {} //! init to (0,0, 0)
		double front;		//!< distance to front unit (meters)
		double rear;		//!< distance to rear unit (meters)
		double timeMsec;	//!< last received time
	};

	//! Data from a GPS unit
	class GpsData
	{
	public:
		GpsData() : Altitude(0), Gps_quality(GpsQuality::last), numSatellites(0), VerticalAccuracy(-1.0), HorizontalAccuracy(-1.0), carrierSolution(-1), goodQuality(false){}
		LatLong Location;		//!< location (lat long) of the unit (degrees)
		double Altitude;		//!< Altitude of the unit (meters)
		double VerticalAccuracy;	//!< accuracy of location (meters)
		double HorizontalAccuracy;	//!<accuracy of Altitude  (meters)
		GpsQuality Gps_quality;	//!< status
		int numSatellites;		//!< how many satellites are visible
		int carrierSolution;	//!< carrierSolution
		bool goodQuality;		//!< should GPS be trusted?
	};


	//! Location from SLAM
	class SlamData
	{
	public:
		SlamData() : Heading(0), forwardStd(-1), lateralStd(-1), headingStd(-1), mse(0), valid(false) {}
		~SlamData() {}
		LatLong Location;	//!< location (lat long) of the unit (degrees)
		double Heading;		//!< Heading direction (degrees)
		double forwardStd;	//!< confidence in forward direction
		double lateralStd;	//!< confidence in sideways direction
		double headingStd;	//!< confidence in heading
		double mse;			//!< MSE of fit
		bool valid;			//!< Is the data indicating valid slam location
	};


	//! location data from both GPS units
	class LocationData
	{
	public:
		LocationData() : Heading(0), CompassAngle(0) {}
		GpsData frontGps;		//!< data of the front GPS unit
		GpsData rearGps;		//!< data of the rear GPS unit
		double Heading;			//!< Heading direction (degrees)
		double CompassAngle;	//!< direction from compass (degrees)
	};

	//! Data from fusion
	class FusionData
	{
	public:
		FusionData() : Heading(0), ForwardConfidence(0), LateralConfidence(0), 
			HeadingConfidence(0), AccelerationLateral(0), AccelerationLongitudinal(0), 
			AntennaDist(0), AntennaDistExpected(0), Pitch(0), Height(0), Speed(0),
			WayPointIndex(0), GpsDisabled(false), GpsFrontInUse(false), GpsRearInUse(false), LidarInIse(false), CameraInIse(false)
		{}
		LatLong LocationFront;	//!< location of the front (degrees)
		LatLong LoncationRear;	//!< location of the rear (degrees)
		double Heading;			//!< Heading direction (degrees)
		double ForwardConfidence;	//!< confidence in forward direction (meters)
		double LateralConfidence;	//!< confidence in sideways direction (meters)
		double HeadingConfidence;	//!< confidence in heading (degrees)
		double AccelerationLongitudinal;	//!< acceleration along the forward direction (m/sec^2)
		double AccelerationLateral;	//!< acceleration perpendicular to the forward direction (m/sec^2)
		double AntennaDist;			//!< distance between front and rear antennas (meters)
		double AntennaDistExpected;			//!< expected distance between front and rear antennas (meters)
		double Pitch;				//!< pitch angle (degrees)
		double Height;				//!< Height above sea level m
		double Speed;				//!< Speed (m/sec)
		int WayPointIndex;			//!< the current way point
		bool GpsDisabled;			//!< true if set to ignore GPS
		bool GpsFrontInUse;			//!< true if using GPS 
		bool GpsRearInUse;			//!< true if using GPS 
		bool LidarInIse;			//!<  true if using Lidar based location 
		bool CameraInIse;			//!<  true if using camera based location 
	};


	//! interface class to enable testing
	class ILocalizationStatus
	{
	public:
		//! Get the current status of GPS location
		virtual void GetLocationData(LocationData& data) = 0;

		//! Get the current status of lidar SLAM location
		virtual void GetLidarSlamData(SlamData& data) = 0;

		//! Get the current status of camera SLAM location
		virtual void GetCameraSlamData(SlamData& data) = 0;

		//! Get the current status of the fusion unit
		virtual void GetFusionData(FusionData& data) = 0;

		//! Get the (fixed) locations of all the known UWB anchors
		virtual void GetUwbAnchorsLocations(std::map<int, LatLong>& locations) = 0;

		//! Get the distances to all current UWB anchors
		virtual void GetUwbAnchorsDistances(std::map<int, DistanceData>& distances) = 0;

		//! Register to get notified when way point changes
		virtual void RegisterToWayPoint(const std::shared_ptr<IChangeObserver>& notify) = 0;
	};

	//! monitor the localization / fusion status
	//
	//! Note that the data is not exactly real time.
	//! The system keeps track of the latest values of localization.
	//! Whenever new message is received the data is updated. When
	//! asking for data user may receive a combination of old and new data
	class LocalizationStatus : public Ohmio::IMessageObserver, public ILocalizationStatus
	{
	public:
		LocalizationStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~LocalizationStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Get the current status of GPS location
		void GetLocationData(LocationData& data) override;

		//! Get the current status of lidar SLAM location
		virtual void GetLidarSlamData(SlamData& data) override;

		//! Get the current status of camera SLAM location
		virtual void GetCameraSlamData(SlamData& data) override;

		//! Get the current status of the fusion unit
		void GetFusionData(FusionData& data) override;

		//! Get the (fixed) locations of all the known UWB anchors
		void GetUwbAnchorsLocations(std::map<int, LatLong>& locations) override;

		//! Get the distances to all current UWB anchors
		void GetUwbAnchorsDistances(std::map<int, DistanceData>& distances) override;

		//! How long do we remember UWB distance data before we ignore it
		static int GetUwbDistanceMaxTime();

		void RegisterToWayPoint(const std::shared_ptr<IChangeObserver>& notify) override;

	private:
		///@{
		//! Receive a specific message and update status
		void RecieveLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveLogitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveGpsLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionStatusMessage(const Ohmio::CAN_MSG& message);
		void RecieveAltitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveAltitudeMessage2(const Ohmio::CAN_MSG& message);
		void RecieveHeadingMessage(const Ohmio::CAN_MSG& message);
		void RecieveUwmDistanceMessage(const Ohmio::CAN_MSG& message);
		void RecieveUwmLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveUwbLogitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveCompassMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionAccelerationMessage(const Ohmio::CAN_MSG& message);
		void RecieveDriveMessage(const Ohmio::CAN_MSG& message);
		void RecieveUbxPart1Message(const Ohmio::CAN_MSG& message);
		void RecieveUbxPart2Message(const Ohmio::CAN_MSG& message);
		void RecieveSlamLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveSlamLongitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveSlamHeadingMessage(const Ohmio::CAN_MSG& message);
		void RecieveGpsOverrideMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionFrontLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionRearLatitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionFrontLogitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionRearLogitudeMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionHeightMessage(const Ohmio::CAN_MSG& message);
		void RecieveFusionFlagsMessage(const Ohmio::CAN_MSG& message);
		///@}

		//! Get the wp index from message
		int GetWpIdxFromMessage(const Ohmio::CAN_MSG& message);


		//! Is a GPS indicating good quality
		bool IsGpsGood(const GpsData& gps);


	private:
		LocationData m_Gps;		//!< data of the front GPS unit
		FusionData m_fusion;	//!< fusion board data
		SlamData m_lidarSlam;	//!< location from lidar SLAM
		SlamData m_cameraSlam;	//!< location from camera SLAM
		std::map<int, LatLong>	m_anchorLocations; //!< fixed locations of UMB anchors
		std::map<int, DistanceData> m_anchorDistances; //!< current distances to anchors
		std::mutex m_mutex;		//!< for locking when data is received  
		NTiming_NS::Timer m_timer; //! to help 'forget' old UWB data
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
	};

}

