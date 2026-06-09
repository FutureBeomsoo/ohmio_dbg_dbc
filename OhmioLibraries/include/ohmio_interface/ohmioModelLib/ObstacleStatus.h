#pragma once

#include "ohmioInterfaceLib/IMessageObserver.h"
#include <chrono>
#include <mutex>

namespace OhmioModel
{
	//! Data from the lidar based system
	class LidarObstacleData
	{
	public:
		LidarObstacleData()  
			: distanceOnTrack(999), distanceMarginA(999), distanceMarginB(999)
			, dangerZoneDistance(999), dangerZoneTime(999), envelopDistance(999), backDistance(999)
			, active(false), envelop(false), leftSideClear(false), rightSideClear(false)
			, dzStatic(false), dzSideways(false), dzOccluded(false)
		{}

		double distanceOnTrack;		//!< distance to the nearest obstacle on the track. (999 if no obstacle)
		double distanceMarginA;		//!< distance to the nearest obstacle on zone A near the track. (999 if no obstacle)
		double distanceMarginB;		//!< distance to the nearest obstacle on zone B near the track. (999 if no obstacle)
		double dangerZoneDistance;	//!< distance to nearest obstacle on danger zone
		double dangerZoneTime;		//!< estimated time to obstacle crossing our way (seconds)
		double envelopDistance;		//!< distance to nearest obstacle inside envelop 
		double backDistance;		//!< distance behind the vehicle
		bool envelop;				//!< true if there is an obstacle inside the safety envelop
		bool active;				//!< true if the lidar system is on
		bool leftSideClear;			//!< true if no obstacle left of the track
		bool rightSideClear;		//!< true if no obstacle right of the track
		bool dzStatic;				//!< true if the obstacle on DZ is static
		bool dzSideways;			//!< true if the obstacle on DZ is moving sideways (not toward us)
		bool moveAway;				//!< true if the obstacle is detected as moving away
		bool incSpeed;				//!< true if the obstacle is detected as increasing its speed away from us
		bool ignored;				//!< true if the obstacle is ignored (false positive) 
		bool dzOccluded;			//!< true if the vehicle cannot see into the DZ. 
	};

	class ExterlnaObstacle
	{
	public:
		ExterlnaObstacle() : latitude(0), longitude(0), speed(0), heading(0) {};

		double latitude;	//!< location
		double longitude;	//!< location
		double speed;		//!< velocity
		double heading;		//!< compass heading in degrees (0 is north 90 is east)
	};


	//! Monitor the obstacle detection system 
	class ObstacleStatus : public Ohmio::IMessageObserver
	{
	public:
		ObstacleStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~ObstacleStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Get the lidar based obstacles
		void GetLidarData(LidarObstacleData& data);


		//! Get the combined ultra sound distance (m)
		double GetUsDistance();

		//! Get the distance to obstacle from all units (m)
		double GetFinalDistance();

		//! @return true is the obstacle system is on. 
		//! Obstacle is on if we got an obstacle message in the last X mSec.
		bool IsObstacleAlive();

		//! How many seconds till no more shrinking?
		int GetObstackeShrinkEndTime();

		//! Get obstacles from external source 
		void GetExternalObs(std::map<int, ExterlnaObstacle>& obstacles);


		//! helper for tests
		void SetTrackFilesFolder(std::string folder);

		//! Get origin for converting lat long to XY
		void GetOrigin(std::pair<double, double>& trackOrigin);


        //! Get Range of the lidar system
        void GetObstacleRange(double& minRange, double& maxRange);


	private:
		///@{
		//! Receive a specific message and update status
		void ReceiveObstacleErrorMessage(const Ohmio::CAN_MSG& message);
		void ReceiveEnvelopMessage(const Ohmio::CAN_MSG& message);
		void ReceiveDriveMessage(const Ohmio::CAN_MSG& message);
		void ReceiveDriveMessageLongWp(const Ohmio::CAN_MSG& message);
		void ReceiveDebugObsMessage(const Ohmio::CAN_MSG& message);
		void ReceiveLidarDangerZoneMessage(const Ohmio::CAN_MSG& message);
		void ReceiveLidarDangerZoneStopMessage(const Ohmio::CAN_MSG& message);
		void ReceiveLidarTrackDistanceMessage(const Ohmio::CAN_MSG& message);
		void ReceiveShrinkMessage(const Ohmio::CAN_MSG& message);
		void ReceiveExternalObs(const Ohmio::CAN_MSG& message);
		void ReceiveExternalObsSpeed(const Ohmio::CAN_MSG& message);
		void ReceiveTrackValidation(const Ohmio::CAN_MSG& message);
		///@}

		//! Get ultra sound data and replace with error value if error or no data
		double OverrideDistanceWithError(double data, uint8_t asByte);

	private:
		LidarObstacleData m_lidar;				//!< status from lidars
		std::chrono::steady_clock::time_point m_lastObstacleTime;		//!< time of last obstacle message
		std::chrono::steady_clock::time_point m_shrinkMarginTime;		//!< time of last obstacle shrink message
		std::mutex m_mutex;	//!< for locking m_externalObstacles when potentially changing 
		std::map<int, ExterlnaObstacle> m_externalObstacles;	//!< obstacles from external source
		std::pair<double, double> m_trackOrigin;				//!< lat , long of track origin
		std::string m_trackFilesFolder;							//!< where to load track files from (allows tests to set it up)
		double m_minRange;			//!< minimum range of the obstacle system (m)
		double m_maxRange;			//!< maximum range of the obstacle system (m)
	};

}

