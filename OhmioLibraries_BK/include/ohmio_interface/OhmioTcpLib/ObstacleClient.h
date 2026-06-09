#pragma once

#include "IModuleClient.h"
#include "ohmioModelLib/ObstacleStatus.h"
//#include <mutex>

namespace OhmioTcp
{
	class ObstacleClient : public IModuleClient
	{
	public:
		ObstacleClient();
		~ObstacleClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;


		//!@{
		//! Create a command string for sending to the server 
		std::string CreateObstacleLocationCommand(int id, double latitude, double longitude) const;
		std::string CreateRemoveObstacleCommand(int id) const;
		//!@}

		//! Get obstacle system information (distance, envelop, etc)
		void GetObstacleDistances(OhmioModel::LidarObstacleData& data) const;

		//! Get external obstacles (obstacles set with CreateObstacleLocationCommand)
		void GetStaticObstacles(std::map<int, std::pair<double, double>> obstacles) const;

	protected:
		void SendPollingRequests() override;

	};
}
