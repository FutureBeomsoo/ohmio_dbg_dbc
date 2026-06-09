#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "OhmioControlLib/ControlManager.h"
#include "OhmioControlLib/BusStopController.h"
#include "ohmioModelLib/commonInclude.h"


namespace OhmioTcp
{
	//! The server interface for bus stop handling
	//
	//! Notify the client about track, location, bus stops locations and mode.
	//! Allows the client to activate stops and to 'go' 
	class BusStopServer : public IModuleServer
	{
	public:
		BusStopServer(std::shared_ptr<OhmioControl::ControlManager> manager);
		~BusStopServer();

		// IModuleServer interface
		std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const override;
		std::string GetModuleName() const override;

	protected:


	private:
		bool CheckArgumaentSize(int command, const std::vector<std::string>& arguments, int expected) const;

		//! @{
		//! Handle specific command
		void HandleSetStopLocation(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleActivateBusStop(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGo(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleHold(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleRelease(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetAllStops(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetTrackId(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetCurrentWp(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleIsStopped(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleIsHold(const std::vector<std::string>& arguments, std::string& answer) const;
		//! @}


	private:
		std::shared_ptr<OhmioControl::BusStopController> m_controller;	//! To pass commands to vehicle
	};

}
