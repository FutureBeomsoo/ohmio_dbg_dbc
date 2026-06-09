#pragma once
#include "IModuleClient.h"
#include <mutex>

namespace OhmioTcp
{
	//! Events that trigger change
	enum class BusStopChangeEvents
	{
		NoEvent = 0,			//!< no change
		StopLocations,			//!< change number or activation of stops
		TrackId,				//!< track changed
		Wp,						//!< current WP changed
		Stopped,				//!< stopped / not state changed
		Held,					//!< hold / release state changed

		// Always add after this
		LastChangeEvent

	};

	//! Handles the client side of the bus stop interface
	class BusStopClient : public IModuleClient
	{
	public:
		BusStopClient();
		~BusStopClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

		//!@{
		//! Create a command string for sending to the server 
		std::string CreateStopRequest(int wayPointIndex);
		std::string CreateActivateRequest(int wayPointIndex, bool active);
		std::string CreateGoRequest();
		std::string CreateHoldRequest();
		std::string CreateReleaseRequest();
		std::string CreateIsStoppedRequest();
		std::string CreateGetTrackIdRequest();
		std::string CreateGetWayPointRequest();
		std::string CreateGetGetAllStopsRequest();
		std::string CreateIsHoldRequest();
		//!@}

		//!@{
		//! Getters
		bool GetLastAnswer();
		bool IsStopped();
		bool IsHold();
		int GetTrackId();
		int GetWayPoint();
		void GetAllStops(std::vector<std::pair<int, bool>>& stops);
		//!@}



	protected:
		// IModuleClient interface
		void SendPollingRequests() override;

	private:

		//! Handle 'GetAllStops' request
		bool HandleGetAllStops(const std::vector<std::string>& arguments);

		//! Handle 'GetTrackId' request
		bool HandleGetTrackId(const std::vector<std::string>& arguments);

		//! Handle 'GetCurrentWp' request
		bool HandleGetCurrentWp(const std::vector<std::string>& arguments);

		//! Handle 'IsStopped' request
		bool HandleIsStopped(const std::vector<std::string>& arguments);

		//! Handle 'IsHold' request
		bool HandleIsHold(const std::vector<std::string>& arguments);



	private:
		bool m_lastAnswerOK;		//!< was the last request successful
		std::vector<std::pair<int, bool>> m_stops;	//!< the stops
		int m_trackId;			//!< the track
		int m_wpNumber;	//!< current WP
		bool m_stopped;			//!< are we stopped at a stop
		bool m_hold;			//!< are we waiting for call to release() before we can go
		std::mutex m_mutex;		//!< for locking the list of stops  

	};

}

