#pragma once
#include <memory>
#include <list>
#include "ohmioModelLib/LocalizationStatus.h"
#include "DriveControl.h"

namespace OhmioControl
{
	//! Manage stopping at optional stops
	//
	//! Holds a list of stop locations and
	//! Issue stop commands when a stop condition is reached
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1225588737/Bus+stop+interface
	class BusStopController : public Threading::RunInThreadForever
	{
	public:
		//! Constructor
		//
		//! @param[in] driveControl - how we stop the vehicle when we get to a stop
		//! @param[in] location - how we know where we are and everything we need about the track
		BusStopController(std::shared_ptr<IDriveControl> driveControl,
			std::shared_ptr<OhmioModel::IWpFlagsSource> location); 
		~BusStopController();

		//@{
		//! Stop when the vehicle gets to a location
		//
		//! Monitor the vehicle progress and issue a stop command when it 
		//! arrives at a location.
		//! The location is defined as:
		//! * lat, long. The stop command is issued when the 
		//! vehicle gets within desired distance (meters) of the location. 
		//! * way point index to issue the command. 
		//! @param[in] latitude - latitude of the desired location
		//! @param[in] longitude - longitude of the desired location
		//! @param[in] distance - max distance from location to track
		//! @param[in] wayPointIndex - the way point to stop at
		//! @return true if can perform the request, false if cannot for some reason
		bool SetStopLocation(double latitude, double longitude, double distance);
		bool SetStopLocation(int wayPointIndex);
		//@}


		//! Get all the stops in the track
		//
		//! @param[out] stops - All the stops. In each stop the first
		//! value is the WP index and the second is true if the stop is enabled 
		//! (we plan to stop there)
		void GetAllStops(std::vector<std::pair<int, bool>>& stops);

		//! enable or disable a stop
		//
		//! Only stops that are ahead of us (and not too close) can be changed
		//! @param[in] wayPointIndex - the way point of the stop. Call GetAllStops
		//! to know where stops are.
		//! @param[in] active - true to activate the stop, false to skip it
		//! @return true if can perform the request, false if cannot for some reason
		bool ActivateBusStop(int wayPointIndex, bool active);

		//! enable or disable the next stop
		//
		//! @param[in] active - true to activate the stop, false to skip it
		//! @return true if can perform the request, false if cannot for some reason
		bool ActivateNextBusStop(bool active);

		//! Are we stopping in the next stop?
		//
		//! @return true if planning to stop, false if skipping
		bool IsNextStopActive();

		//! Get the current track unique ID
		uint64_t GetTrackId();

		//! Get the current location on track (way point number)
		int GetCurrentWp();

		//! Are we stopped at a bus stop?
		bool IsStopped();

		//! Are we waiting for Release() before we can go?
		bool IsHold();

		//! resume driving
		//
		//! If we are not stopped at a bus stop this command is ignored
		//! @return true if can perform the request, false if cannot for some reason
		bool Go();

		//! Disable closing the door and driving
		//
		//! To allow slow passenger to 'hold' the vehicle until they are ready to go.
		//! Ignored if not stopped
		//! @return true if can perform the request, false if cannot for some reason
		bool Hold();

		//! Release from 'hold'. Ignored if not in hold 
		//! @return true if can perform the request, false if cannot for some reason
		bool Release();


	protected:
		// RunInThreadForever interface
		void RunLoopOnce();


		std::string GetDiagnosticName();
		int GetWatchdogPeriod() override;

	private:

		//! load all the bus stops from the current track
		void LoadStopsFromTrack();

		//! Where should we stop next?
		//
		//! @return next stop index or -1 if no stop
		int GetNextStop();

		//! See if it is time to send a stop command
		void SendStopIfNeeded();

		//! Get the WP number for the next bus sop. Return -1 if no stop
		int FindNextStop();

		//! How many WP ahead should we send the stop command. Depends on speed
		int CalculateStopDistance();

	private:
		std::vector<std::pair<int, bool>> m_stops;		//!< All the stops
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_location; //!< to get our current location from
		std::shared_ptr<IDriveControl> m_driveControl;	//!< the driving controller
		std::shared_ptr<OhmioModel::ChangeMonitor> m_TrackChangeDetector;	//!< Get notified when track changes
		int m_currentWP;	//!< index of current way point
		int m_nextSendWp;	//!< Send stop again after this point
		std::mutex m_mutex;	//!< for locking m_whereToStop when potentially changing 
		std::vector<std::pair<double, double>> m_StopsForNextRun;		//!< dynamic stops we missed and are pending for the next time
		int m_goWP;				//!< the way point where we had 'go' clicked
		std::chrono::steady_clock::time_point m_lastGoTime; //!< last time we sent a go related command


		//! state machine for the 'go' button
		enum class goState
		{
			driving,		//!< we are driving no 'go' request
			requested,		//!< user pressed go
			startSent,		//!< send a 'start' command
			goSent,			//!< sent a 'go' command


			// always add above this
			last
		};

		goState m_wantToGo;		//!< if this is true we want to start driving
	};

}

