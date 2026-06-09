#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "OhmioControlLib/TrafficLightController.h"


namespace OhmioTcp
{
	//! The server interface for traffic light handling
	//
	//! Notify the client when the traffic light we use changes
	//! Allows the client to set the traffic light state (red / green)
	class TrafficLightServer : public IModuleServer
	{
	public:
		TrafficLightServer(std::shared_ptr<OhmioControl::ControlManager> manager);
		~TrafficLightServer();

		// IModuleServer interface
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

	protected:
		void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) override;


	private:

		//! @{
		//! Handle specific command
		void HandleGoComand(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleStatusRequest(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleAddComand(const std::vector<std::string>& arguments, std::string& answer) const;
		//! @}


	private:
		std::shared_ptr<OhmioControl::TrafficLightController> m_controller;	//! To pass commands to vehicle
	};

}

