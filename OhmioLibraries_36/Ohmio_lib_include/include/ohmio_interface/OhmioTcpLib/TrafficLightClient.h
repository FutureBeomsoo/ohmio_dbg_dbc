#pragma once
#include "IModuleClient.h"
//#include <mutex>

namespace OhmioTcp
{
	class TrafficLightClient : public IModuleClient
	{
	public:
		TrafficLightClient();
		~TrafficLightClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

		//!@{
		//! Create a command string for sending to the server 
		std::string CreateGoCommand(int regionId, int intersectionId, const std::string& descriptor, int status, double timeToChange);
		std::string CreateStatusRequest();
		std::string CreateExtraLightCommand(int wpIdx, int regionId, int intersectionId, const std::string& movement, double timeToCross);
		//!@}

		//!@{
		//! Getters
		bool GetLastAnswer();
		int GetDistanceToStop();
		void GetEventName(std::string& descriptor);
		int GeRegionId();
		int GeIntersectionId();
		int GetLightStatus();
		double GetTimeToChange();
		double GetTimeToCross();
		double GetMessageAge();
		//!@}


	protected:
		// IModuleClient interface
		void SendPollingRequests() override;

	private:

		//! handle the response to status request 
		bool HandleStatusRequest(const std::vector<std::string>& arguments);


	private:
		bool m_lastAnswerOK;		//!< was the last request successful
		int m_distanceToStop;				//!< number of WP to stop line
		int m_regionId;						//!< region
		int m_intersectionId;				//!< intersection ID
		int m_lightStatus;					//!< light status (red, green, etc) from enum
		double m_timeToChange;				//!< time (Sec) for change
		double m_timeToCross;				//!< time (Sec) needed to cross
		double m_messageAge;				//!< time (Sec) from last good V2X message
		std::string m_eventName;			//!< name of the movement we are waiting for 

	};


}
