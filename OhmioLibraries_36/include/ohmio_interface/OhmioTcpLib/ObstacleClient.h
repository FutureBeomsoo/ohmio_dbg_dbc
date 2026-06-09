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
		virtual ModuleNames GetModuleId() const override;


		//!@{
		//! Create a command string for sending to the server 
		std::string CreateObstacleLocationCommand(int id, double latitude, double longitude, double speed, double heading) const;
		std::string CreateRemoveObstacleCommand(int id) const;
		std::string CreateGetObstacles() const;
		//!@}


		bool GetLastAnswer() const;

		//! Get external obstacles (obstacles set with CreateObstacleLocationCommand)
		void GetObstacles(std::map<int, std::pair<double, double>>& obstacles);


		void RegisterToChange(std::shared_ptr<OhmioModel::IChangeObserver> observer);


	protected:
		void SendPollingRequests() override;


	private:

		//! Handle 'HandleGetObstacles' request
		bool HandleGetObstacles(const std::vector<std::string>& arguments);


	private:
		bool m_lastAnswerOK;		//!< was the last request successful
		std::map<int, std::pair<double, double>> m_obstacles;	//!< list of obstacle created from outside source 
		std::mutex m_mutex;		//!< for locking the list of stops  
		std::vector<std::shared_ptr<OhmioModel::IChangeObserver>> m_observers; //!< Observers to tell when data change
	};
}
