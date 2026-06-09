#pragma once
#include "InterfaceManager.h"
//#include "ohmioModelLib/DriveStatus.h"
#include "OhmioTcpLib/DriveControlClient.h"


namespace OhmioInterfacePy
{
	//! Interface to the driving (stop / go, speed, etc)
	//
	//! this is just an interface. Everything is passed on to the control library to 
	//! do the work
	class DriveInterface
	{
	public:
		DriveInterface(InterfaceManager& manager);
		~DriveInterface();


	
		//! Wait for a change in the lights
		//
		//! Sleeps until a change is notified or timeout passed
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);


		//! Start 
		//
		//! Prepare to drive the current selected track. (does not drive. just start)
		//! Only available when the vehicle is in idle mode. 
		//! @return true if can perform the request, false if cannot for some reason
		bool Start();

		//! Go 
		//
		//! Drive the current selected track. Only available in 'ready' mode 
		//! @return true if can perform the request, false if cannot for some reason
		bool Go();

		//! Stop 
		//
		//! Stop now (at the vehicle default deceleration). Same as pressing the stop button on the UI
		//! @return true if can perform the request, false if cannot for some reason
		bool Stop();

		//! Select the track to drive 
		//
		//! @param[in] trackNumber - 1 or 2
		//! @param[in] forward - true for forward, false for reverse
		//! @return true if can perform the request, false if cannot for some reason
		bool SelectTrack(int trackNumber, bool forward);


		//! Set the maximum speed
		//
		//! @param[in] speed - the maximum speed to drive at (m/sec). The vehicle will 
		//! drive slower if the track settings or road conditions requires
		//! @return true if can perform the request, false if cannot for some reason
		bool SetMaxSpeed(double speed);

		//@{
		//! Stop when the vehicle gets to a location
		//
		//! Monitor the vehicle progress and issue a stop command when it 
		//! arrives at a location.
		//! The location is defined as:
		//! * lat, long, distance. The stop command is issued when the 
		//! vehicle gets within desired distance (meters) of the location. 
		//! * way point index to issue the command. 
		//! @param[in] latitude - latitude of the desired location
		//! @param[in] longitude - longitude of the desired location
		//! @param[in] distance - distance from the location to initiate the stop command
		//! @param[in] wayPointIndex - the way point when the command is issued
		//! @return true if can perform the request, false if cannot for some reason
		bool StopAtLocation(double latitude, double longitude, double distance);
		bool StopAtWP(int wayPointIndex);
		//@}

		
		//! Perform overtake maneuver (future feature)
		//
		//! Go around an obstacle. Move to the next lane (or return). 
		//! @param[in] offset - how much to move sideways (m). Positive value is going to the left
		//! @param[in] revert - if true go back to the main track.
		//! @return true if can perform the request, false if cannot for some reason
		bool Overtake(double offset, bool revert);

		//! Get current mode of the vehicle
		//
		//! @return the mode (idle, ready, auto, manual, etc) from enum SYS_STATES
		int GetCurrentState() const;

		//! Get the maximum speed
		//
		//! @return - the maximum speed to drive at (m/sec)
		double GettMaxSpeed() const;


		//! What track are we driving 
		//
		//! @return trackNumber - 1 or 2
		int GetCurrentPath() const;

		//! What track are we driving 
		//
		//! @return true if forward track, false if reverse track
		bool GetDirection() const;

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::DriveControlClient> m_responseServer;		//!< how we get data from the vehicle

	};

}

