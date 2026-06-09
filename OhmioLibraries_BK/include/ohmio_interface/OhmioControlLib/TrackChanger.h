#pragma once
#include <memory>
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioModelLib/LocalizationStatus.h"
#include "DriveControl.h"
#include "CommonInclude.h"

namespace OhmioControl
{
	//! Automatically switch tracks according to events
	//
	//! Implementing 'Handling an obstacle in a bus stop bay' from
	//! https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/2248409089/Track+deviation+for+static+obstacles
	class TrackChanger : public Threading::RunInThreadForever
	{
	public:
		TrackChanger(std::shared_ptr<IDriveControl> driveControl,
			std::shared_ptr<Ohmio::MessageReceiver> receiver,
			std::shared_ptr<TrafficLightController> trafficLightContrlller,
			std::shared_ptr<OhmioModel::IWpFlagsSource> driveStatus);
		~TrackChanger();


	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! state machine
		enum class state
		{
			idle,			//!< no change needed
			skippingStop,	//!< no need to stop
			needToStop,		//!< we should stop and change track
			stopped,		//!< stopped - switch to idle so that we can change track
			trackChanged,	//!< new track loaded we should go
			drivig,			//!< driving in the new track

			// always add above
			last
		};

		//! Is the vehicle moving?
		bool IsMoving();

		//! Do we need to stop and change?
		bool IsStopNeeded();

		//! Are we under the influence of an event and should potentially switch
		bool IsActiveEvent();

		//! We decided to not stop. Send 'OK' command to the vehicle so that we don't stop
		void SendSkipCommand();

		//! Is the event a 'stop and change track' event
		bool IsEventTrackChange(const OhmioModel::TrackEvent& event);

		//! Decode the event JSON string. return true if indicating track change event
		bool DecodeEventJson(const std::string& json);

		//! whats the current distance to obstacle
		double GetObstacleDistance();

		//! Start driving after we switched to a new track (start and go commands)
		void DriveNewTrack();

		//! Change to a new track (switch to idle and select track)
		void ChangeTrack();

		//! Find the next event to use
		void PerformIdleTasks();

		//! return true if we need to rest - give the drive control time to handle the last command
		bool IsRestTime();

	private:
		std::shared_ptr<IDriveControl> m_driveControl;	//!< the driving controller
		std::shared_ptr<TrafficLightController> m_trafficLightContrlller;	//!< to send 'green light' command
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_driveStatus; //!< to get our current location from
		std::shared_ptr<OhmioModel::ObstacleStatus> m_obstacles;	//!< to get distance to obstacle
		state m_currentState;		//!< our current state
		int m_nextTrackToDrive;		//!< the track to switch to
		double m_obstacleStopCondtion;		//!< stop if obstacle distance below this
		std::chrono::steady_clock::time_point m_lastCommandTime; //!< last time we sent a command
	};

}
