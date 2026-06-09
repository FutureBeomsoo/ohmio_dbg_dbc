#pragma once

#include "InterfaceManager.h"
#include "ohmioModelLib/ObstacleStatus.h"
#include "OhmioTcpLib/ObstacleClient.h"
#include <functional>

namespace OhmioInterfacePy
{

	//! The obstacle  API see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1112211506/API+Functions?focusedCommentId=1121419265
	class ObstacleInterface
	{
	public:
		ObstacleInterface(InterfaceManager& manager);
		~ObstacleInterface();

		//! There is an obstacle on the way
		//
		//! @param[in] id  - of the obstacle (so that it can be cleared or moved)
		//! @param[in] latitude - lat of obstacle position (nearest part of the obstacle)
		//! @param[in] longitude - long of obstacle position (nearest part of the obstacle)
		//! @param[in] speed - estimated speed of the obstacle (in m/sec) 
		//! @param[in] heading - compass heading of the obstacle in degrees (i.e. north is 0, east is 90)
		//! @return true if obstacle can be set
		bool SetObstacle(int id, double latitude, double longitude, double speed = 0, double heading = 0);

		//! an obstacle has been removed	
		//! @param[in] id  - of the obstacle. 
		//! @return true if obstacle can be removed
		bool ClearObstacle(int id);


		//! Get a list of the current existing obstacles
		//
		//! Only reports on obstacles created by SetObstacle.
		//! returns just the locations without motion information
		std::map<int, std::pair<double, double>> GetObstacles();

		//! push notification for change in status. This will be called for all registered observers when data is changes
		//
		//! @param[out] topic - name of topic that had changed
		//! @param[out] info - the new topic data
		using ChangeCallback = std::function<void(std::map<int, std::pair<double, double>>& info)>;

		//! Register to get notification about changes
		void RegisterForChange(ChangeCallback observer);

		//! Get called When state changed so that we can call all observers 
		void OnChanged(int param);

	private:
		//! Helper class for getting change notification
		class ChangeObserver : public OhmioModel::IChangeObserver
		{
		public:
			ChangeObserver(ObstacleInterface& target) : m_target(target) {}
			~ChangeObserver() {}

			virtual void OnChanged(int param) override
			{
				m_target.OnChanged(param);
			}

			ObstacleInterface& m_target;
		};

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::ObstacleClient> m_responseServer;		//!< how we get data from the vehicle
		std::shared_ptr<ChangeObserver> m_changeHelper;		//!< to register as observer
		std::vector<ChangeCallback> m_Observers;			//!< observers to update about changes

	};
}

