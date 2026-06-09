#pragma once
#include "IModuleServer.h"

namespace OhmioTcp
{
	class AnnouncementsServer : public IModuleServer
	{
	public:
		AnnouncementsServer(std::shared_ptr<OhmioControl::ControlManager> manager);
		~AnnouncementsServer();

		// IModuleServer interface
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

	protected:
		void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) override;


	private:

		//! @{
		//! Handle specific command
		void HandleSetSoundRequest(const std::vector<std::string>& arguments, std::string& answer) const;
		//! @}


	private:
		std::shared_ptr<OhmioControl::AnnouncementsControl> m_controller;	//! To pass commands to vehicle
	};


}
