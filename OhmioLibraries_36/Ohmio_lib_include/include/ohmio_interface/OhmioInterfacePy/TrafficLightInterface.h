#pragma once
#include <functional>
#include <string>
#include "InterfaceManager.h"
#include "UtilityLib/RunInThreadForever.h"
#include "OhmioTcpLib/TrafficLightClient.h"



namespace OhmioInterfacePy
{
	//! definition of an event (motion across an intersection) for the traffic light
	class MotionDescription 
	{
	public:
		int regionId;			//!< where in the world are we
		int intersectionId;		//!< which junction
		std::string eventDescriptor;	//!< what are we trying to do

	};


	class TrafficLightStatus
	{
	public:
		int status;						//!< from TRAFFIC_LIGHT_STATUS enum
		double timeToChange;			//!< time (seconds) before the status will change
		MotionDescription eventName;	//!< the movement we are planning 
		double timeToCross;				//!< time (seconds) needed to cross the junction
		int distance;					//!< number of WP to stop line
		double messageAge;				//!< time (seconds) from last valid V2X message (should typically be under 0.2)
	};

	//! traffic light interface for remote access see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/2421456919/V2X+communication+via+Ohmio+Interface
	class TrafficLightInterface : public Threading::RunInThreadForever
	{
	public:
		TrafficLightInterface(InterfaceManager& manager);
		~TrafficLightInterface();

		//! Get the current state
		TrafficLightStatus GetStatus();


		//! Set the traffic light state
		void Go(TrafficLightStatus status);

		//! Set a temporary light. Mainly for testing
		//
		//! @param[in] wpIdx - stop way point
		//! @param[in] regionId - region from SPAT message
		//! @param[in] intersectionId - intersection from SPAT message
		//! @param[in] movement - some identifying string
		//! @param[in] timeToCross - time (seconds) that it takes the vehicle to cross the junction 
		void SetTrafficLight(int wpIdx, int regionId, int intersectionId, const std::string& movement, double timeToCross);


		//! Wait for a change in the status
		//
		//! Sleeps until a change is notified or timeout passed.
		//! A change is indicated if the traffic light changes states or the intersection changes
		//! When this function returns true the caller should ask for the status to get
		//! the new state
		//! This is an alternative to using the call back option ChangeCallback
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);

		//! push notification for change in status. 
		//
		//! Registered units get called whenever the status (way point, track id or IsStopped) changes.
		//! The callback should ask for the status to get the new state
		//! This is an alternative to using WaitForChange
		using ChangeCallback = std::function<void(TrafficLightStatus& data)>;

		//! Register to get notification when the status changes
		void RegisterForDataChange(ChangeCallback observer);

	protected:
		// RunInThreadForever interface
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		virtual int GetWatchdogPeriod() override;


	private:

		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::TrafficLightClient> m_responseServer;		//!< how we get data from the vehicle
		std::vector<ChangeCallback> m_Observers;			//!< observers to update about changes
	};

}


