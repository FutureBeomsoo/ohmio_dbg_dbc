#pragma once
#include <functional>

#include "InterfaceManager.h"
#include "UtilityLib/RunInThreadForever.h"
#include "OhmioTcpLib/BusStopClient.h"

namespace OhmioInterfacePy
{
	//! Handle dynamic bus stop see https://hmitechnologies.atlassian.net/wiki/spaces/OLSP1/pages/2259779585/Suggested+interface
	class BusStopInterface : public Threading::RunInThreadForever
	{
		// not unit tested. This class only forward calls to BusStopController.
		// and testing requires setting up a lot of things to make it work.
		// BusStopController is unit tested.
	public:
		BusStopInterface(InterfaceManager& manager);
		~BusStopInterface();


		//! Get all the stops in the track
		//
		//! @return - All the stops. In each stop the first
		//! value is the WP index and the second is true if the stop is enabled 
		//! (we plan to stop there)
		std::vector<std::pair<int, bool>> GetAllStops();

		//! enable or disable a stop
		//
		//! Only stops that are ahead of us (and not too close) can be changed.
		//! To check the results Call GetAllStops() to get the stops state
		//! @param[in] wayPointIndex - the way point of the stop. Call GetAllStops
		//! to know where stops are.
		//! @param[in] active - true to activate the stop, false to skip it
		void ActivateBusStop(int wayPointIndex, bool active);

		//! Add a bus stop at a way point
		//
		//! Create a temporary bus stop that is not defined in the track file.
		//! The bus stop is forgotten whenever the track is reloaded
		//! @param[in] wayPointIndex - the way point to stop at
		void SetStopLocation(int wayPointIndex);


		//! Get the current track unique ID
		uint64_t GetTrackId();

		//! Get the current location on track (way point number)
		int GetCurrentWp();

		//! Are we stopped at a bus stop?
		bool IsStopped();

		//! Are we waiting for call to Release() before we can go?
		bool IsHold();

		//! resume driving
		//
		//! If we are not stopped at a bus stop this command is ignored
		void Go();

		//! Disable closing the door and driving
		//
		//! To allow slow passenger to 'hold' the vehicle until they are ready to go.
		//! Ignored if not stopped
		void Hold();

		//! Release from 'hold'. Ignored if not in hold 
		void Release();


		//! Wait for a change in the status
		//
		//! Sleeps until a change is notified or timeout passed.
		//! A change is indicated if waypoint or track id or 'IsStop' status changes
		//! When this function returns true the caller should ask for the status to get
		//! the new state
		//! This is an alternative to using the call back option ChangeCallback
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);

		//! push notification for change in status excluding WP. 
		//
		//! Registered units get called whenever the status (track id or IsStopped) changes.
		//! The callback should ask for the status to get the new state
		//! The parameter in the function should tell what had changed but is not implemented yet
		//! This is an alternative to using WaitForChange
		//! @param[out] the event that changed (from enum BusStopChangeEvents). Not implemented yet
		using ChangeCallback = std::function<void (int)>;


		//! push notification for WP change.
		//
		//! @param[out] the new WP number
		using WpChangeCallback = std::function<void (int)>;


		//! Register to get notification when the status changes
		void RegisterForDataChange(ChangeCallback observer);

		//! Register to get notification when the WP changes
		void RegisterForWpChange(ChangeCallback observer);

	protected:
		// RunInThreadForever interface
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		virtual int GetWatchdogPeriod() override;


	private:
		// Find out what had changed since last call. So taht we can notify observer
		int GetWhatChanged();

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::BusStopClient> m_responseServer;		//!< how we get data from the vehicle
		std::vector<ChangeCallback> m_Observers;						//!< observers to update about changes
		std::vector<WpChangeCallback> m_WpObservers;					//!< observers to update about changes
		int m_currentWP;												//!< last known WP

	};


}

