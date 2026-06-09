#pragma once

#include "ohmioInterfaceLib/IMessageObserver.h"
#include <chrono>

namespace OhmioModel
{
	//! Data from the lidar based system
	class LidarObstacleData
	{
	public:
		LidarObstacleData()  
			: distanceOnTrack(999), distanceMarginA(999), distanceMarginB(999)
			, dangerZoneDistance(999), dangerZoneTime(999), envelopDistance(999)
			, active(false), envelop(false)
		{}

		double distanceOnTrack;		//!< distance to the nearest obstacle on the track. (999 if no obstacle)
		double distanceMarginA;		//!< distance to the nearest obstacle on zone A near the track. (999 if no obstacle)
		double distanceMarginB;		//!< distance to the nearest obstacle on zone B near the track. (999 if no obstacle)
		double dangerZoneDistance;	//!< distance to nearest obstacle on danger zone
		double dangerZoneTime;		//!< estimated time to obstacle crossing our way (seconds)
		double envelopDistance;		//!< distance to nearest obstacle inside envelop 
		bool envelop;				//!< true if there is an obstacle inside the safety envelop
		bool active;				//!< true if the lidar system is on
	};

	//! Data from the UltraSound based system
	//
	//! distance < 0 is error, distance > 20 is no obstacle
	class UltraSoundObstacleData
	{
	public:
		UltraSoundObstacleData()
			: distanceFrontDoor(999), distanceFrontMiddle(999), distanceFrontWindow(999),
			distanceRearDoor(999), distanceRearMiddle(999), distanceRearWindow(999), active(false)
		{}

		double distanceFrontDoor;		//!< distance detected by front sensor near door side. 
		double distanceFrontMiddle;		//!< distance detected by front sensor in the middle. 
		double distanceFrontWindow;		//!< distance detected by front sensor near window side. 
		double distanceRearDoor;		//!< distance detected by Rear sensor near door side. 
		double distanceRearMiddle;		//!< distance detected by Rear sensor in the middle. 
		double distanceRearWindow;		//!< distance detected by Rear sensor near window side. 
		bool active;					//!< true if the ultrasound system is on
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

		//! Get the ultrasound based obstacles
		void GetUltrasoundData(UltraSoundObstacleData& data);

		//! Get the combined ultra sound distance (m)
		double GetUsDistance();

		//! Get the distance to obstacle from all units (m)
		double GetFinalDistance();

		//! @return true is the obstacle system is on. 
		//! Obstacle is on if we got an obstacle message in the last X mSec.
		bool IsObstacleAlive();


		//! How many seconds till no more shrinking?
		int GetObstackeShrinkEndTime();

	private:
		///@{
		//! Receive a specific message and update status
		void RecieveObstacleErrorMessage(const Ohmio::CAN_MSG& message);
		void RecieveEnvelopMessage(const Ohmio::CAN_MSG& message);
		void RecieveLidarObstacleMessage(const Ohmio::CAN_MSG& message);
		void RecieveUltrasoundObstacleMessage(const Ohmio::CAN_MSG& message);
		void RecieveDriveMessage(const Ohmio::CAN_MSG& message);
		void RecieveDriveMessageLongWp(const Ohmio::CAN_MSG& message);
		void RecieveDebugObsMessage(const Ohmio::CAN_MSG& message);
		void RecieveLidarDangerZoneMessage(const Ohmio::CAN_MSG& message);
		void RecieveLidarTrackDistanceMessage(const Ohmio::CAN_MSG& message);
		void RecieveShrinkMessage(const Ohmio::CAN_MSG& message);
		///@}

		//! Get ultra sound data and replace with error value if error or no data
		double OverrideDistanceWithError(double data, uint8_t asByte);

	private:
		LidarObstacleData m_lidar;				//!< status from lidars
		UltraSoundObstacleData m_ultraSound;	//!< status from ultrasound
		bool m_lidarUseMessage120;				//!< if true lidar data cames from message 0x120 otherwise 0x122 and 0x123
		std::chrono::steady_clock::time_point m_lastObstacleTime;		//!< time of last obstacle message
		std::chrono::steady_clock::time_point m_shrinkMarginTime;		//!< time of last obstacle shrink message
	};

}

