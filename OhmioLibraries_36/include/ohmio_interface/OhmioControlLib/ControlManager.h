#pragma once

#include <vector>
#include <memory>
#include "CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/LocalizationStatus.h"


namespace OhmioControl
{

	//! Create and mange all the parts that are needed for controlling the vehicle
	class ControlManager
	{
	public:

		ControlManager(std::shared_ptr<Ohmio::CommunicationManager> manager, bool emulator = false);

		~ControlManager();

		//! Create the light controller - needs to discover the light hardware used
		//
		//! @return true if got it
		bool CreateLightController(std::shared_ptr<Ohmio::CommunicationManager> manager);

		//! Get the way points source - used to follow the track and WP
		std::shared_ptr<OhmioModel::IWpFlagsSource> GetWpSource();

		//! Get the driving controller
		std::shared_ptr<DriveControl> GetDriveControl();

		//! Get the bus stop controller 
		std::shared_ptr<BusStopController> GetBusStopControl();

		//! Get the emulator controller
		std::shared_ptr<EmulatorControl> GetEmulatorControl();

		//! Get the peripheral controller
		std::shared_ptr<PeripheralControl> GetPeripheralControl();

		//! Get the system controller
		std::shared_ptr<SystemControl> GetSystemControl();

		//! Get the obstacle controller
		std::shared_ptr<ObstacleControl> GetObstacleControl();

		//! Get the trafficLight controller
		std::shared_ptr<TrafficLightController> GetTrafficLightControl();

		//! Get the trafficLight controller
		std::shared_ptr<DrivingLightsControl> GetLightControl();

		//! Get the wipers controller
		std::shared_ptr<WipersControl> GetWiperControl();

		//! Get the remote helper
		std::shared_ptr<RemoteHelper> GetRemote();

		std::shared_ptr<AnnouncementsControl> GetAnnouncementsControl();	

		//! ask if it is ready 
		bool IsReady();


	private:
		std::vector<std::shared_ptr<Threading::RunInThreadForever>> m_threadsWeStrated; //!< list of threads that need to be stopped
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_wpSource;	//!< monitor where we are
		std::shared_ptr<DrivingLightsControl> m_lightControl;	//!< control lights
		std::shared_ptr<DriveControl> m_driveControl;			//!< control the driving
		std::shared_ptr<BusStopController> m_busStopContol;		//!< controls optional stops
		std::shared_ptr<EmulatorControl> m_emulator;			//!< control emulator
		std::shared_ptr<PeripheralControl> m_peripheral;		//!< control peripheral can
		std::shared_ptr<TrafficLightController> m_trafficLight;	//!< control traffic light
		std::shared_ptr<SystemControl> m_systemControl;			//!< control system
		std::shared_ptr<BatteryControl> m_batteryControl;			//!< control system
		std::shared_ptr<ObstacleControl> m_obstacleControl;		//!< obstacle system control
		std::shared_ptr<TrackChanger> m_trackChanger;			//!< change tracks on the fly
		std::shared_ptr<WipersControl> m_wiperControl;			//!< control window wipers 
		std::shared_ptr<VersionResponder> m_versionResponse;	//!< versions 
		std::shared_ptr<RemoteHelper> m_remote;					//!< helper to get remote control buttons
		std::shared_ptr<AnnouncementsControl> m_soundPlayer;	//!< play Announcements
	};
}


