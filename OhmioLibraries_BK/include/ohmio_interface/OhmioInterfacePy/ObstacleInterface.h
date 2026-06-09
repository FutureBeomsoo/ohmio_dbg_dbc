#pragma once

#include "InterfaceManager.h"
#include "ohmioModelLib/ObstacleStatus.h"
#include "OhmioTcpLib/ObstacleClient.h"

namespace OhmioInterfacePy
{

	//! The obstacle  API see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1112211506/API+Functions?focusedCommentId=1121419265
	class ObstacleInterface
	{
	public:
		ObstacleInterface(InterfaceManager& manager);
		~ObstacleInterface();

		//! Get the lidar based obstacles
		void GetLidarData(OhmioModel::LidarObstacleData& data);


		//! There is a static obstacle on the way
		//
		//! @param[in] id  - of the obstacle (so that it can be cleared or moved)
		//! @param[in] latitude - lat of obstacle position (nearest part of the obstacle)
		//! @param[in] longitude - long of obstacle position (nearest part of the obstacle)
		//! @return true if obstacle can be set
		bool SetStaticObstacle(int id, double latitude, double longitude);

		//! a static obstacle has been removed		//
		//! @param[in] id  - of the obstacle. 
		//! @return true if obstacle can be removed
		bool ClearStaticObstacle(int id);


		//! Get a list of the current existing static obstacles
		//
		//! Only reports on static obstacles  
		std::map<int, std::pair<double, double>> GetStaticObstacles();

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::ObstacleClient> m_responseServer;		//!< how we get data from the vehicle
//		std::vector<ChangeCallback> m_Observers;			//!< observers to update about changes

	};
}

