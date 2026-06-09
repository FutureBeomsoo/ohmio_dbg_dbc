#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "ohmioModelLib/commonInclude.h"

namespace OhmioTcp
{
	class ObstacleServer : public IModuleServer
	{
	public:
		ObstacleServer(std::shared_ptr<OhmioControl::ControlManager> manager);
		~ObstacleServer();

		// IModuleServer interface
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

	protected:
		void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) override;

	private:

		//! @{
		//! Handle specific command
		void HandleSetObstacle(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleRemoveObstacle(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetObstacle(const std::vector<std::string>& arguments, std::string& answer) const;
		//! @}



	private:
		std::shared_ptr<OhmioControl::ObstacleControl> m_controller;

	};

}
