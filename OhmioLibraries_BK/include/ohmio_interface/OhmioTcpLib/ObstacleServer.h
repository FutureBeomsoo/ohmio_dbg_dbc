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
		std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const override;
		std::string GetModuleName() const override;
	};

}
