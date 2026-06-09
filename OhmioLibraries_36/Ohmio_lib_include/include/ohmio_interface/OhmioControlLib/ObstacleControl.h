#pragma once
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include "CommonInclude.h"
#include <chrono>

namespace OhmioControl
{

	//! General system management (reset, shutdown, etc)
	class ObstacleControl : public Threading::RunInThreadForever
	{
	public:

		ObstacleControl(std::shared_ptr<Ohmio::MessageBuffer> writeBuffer, 
			std::shared_ptr<Ohmio::MessageReceiver> messageReciever, std::shared_ptr<AnnouncementsControl> dingPlayer);

		~ObstacleControl();

		//! Temporary shrink the safety margins to allow passing near static object
		//
		//! @param[in] time - time (seconds) to shrink the margins for
		void ShrinkMargins(int time);

		//! Place an obstacle at a location. Based on data from external sensors
		//
		//! @param[in] id  - of the obstacle (so that it can be cleared or moved)
		//! @param[in] latitude - lat of obstacle position (nearest part of the obstacle)
		//! @param[in] longitude - long of obstacle position (nearest part of the obstacle)
		//! @param[in] speed - estimated speed of the obstacle (in m/sec) 
		//! @param[in] heading - compass heading of the obstacle in degrees (i.e. north is 0, east is 90)
		//! @return true if obstacle can be set
		void SetExternalObstacle(int id, double latitude, double longitude,
			double speed, double heading);

		//! Remove an obstacle from external sensors
		//
		//! @param[in] id  - of the obstacle to remove
		//! @return true if the obstacle was removed
		bool ClearExternalObstacle(int id);

		//! Get obstacles from external source 
		void GetExternalObs(std::map<int, OhmioModel::ExterlnaObstacle>& obstacles);

		//! helper for tests
		void SetTrackFilesFolder(std::string folder);

		//! Enable or disable the envelop beep
		void EnableEnvelopBeep(bool enable);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Sound alarm if obstacle in envelop
		void BeepIfNeeded();

		//! beep
		void SoundAlarm(std::string soundFile);

		//! What should be the time (mSec) between beeps
		int GetDingPeriodForDistance(double distance);

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;		//!< for writing to the vehicle
		std::shared_ptr<Ohmio::MessageReceiver> m_messageReciever;	//!< for feeding back the margin message to model
		std::shared_ptr<OhmioModel::DriveStatus> m_driveStatus;		//!< to know if we are left or right driver
		std::shared_ptr<OhmioModel::ObstacleStatus> m_obstacleStatus;		//!< status of the obstacle system
		std::shared_ptr<AnnouncementsControl> m_dingPlayer;			//!< to play 'ding' when envelop is on
		std::chrono::high_resolution_clock::time_point m_lastDingime; //!< last time we made a warning sound 
		bool m_envelopBeepEnabled;					//!< if true, we will beep when envelop is on
	};
}

