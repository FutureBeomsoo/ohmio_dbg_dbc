#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "ohmioModelLib/commonInclude.h"

namespace OhmioTcp
{
	class DriveControlServer : public IModuleServer
	{
	public:
		DriveControlServer(std::shared_ptr<OhmioControl::ControlManager> manager);
		~DriveControlServer();

		// IModuleServer interface
		std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const override;
		std::string GetModuleName() const override;

	private:
		//! verify the input
		bool CheckArgumaentSize(int command, const std::vector<std::string>& arguments, int expected) const;

		//! @{
		//! Handle specific command
		void HandleGo(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleStop(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleStart(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleSpeedRequest(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleTrackRequest(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleStopAtLocation(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleStopAtWp(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetMode(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetTrack(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetSpeed(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleOvertake(const std::vector<std::string>& arguments, std::string& answer) const;
		//! @}


	private:
		std::shared_ptr<OhmioControl::DriveControl> m_controller;	//! To pass commands to vehicle
	};

}

