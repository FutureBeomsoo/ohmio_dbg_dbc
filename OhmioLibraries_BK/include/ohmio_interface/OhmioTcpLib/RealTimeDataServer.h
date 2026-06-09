#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "ohmioModelLib/commonInclude.h"
#include "ohmioInterfaceLib/CommonInclude.h"
#include "RealTimeDataMessageDefinitions.h"


namespace OhmioTcp
{
	//! The server interface for collecting real time status data from the vehicle
	//
	//! Continuously update the client about changes to the vehicle 
	class RealTimeDataServer : public IModuleServer
	{
	public:
		RealTimeDataServer(std::shared_ptr<Ohmio::CommunicationManager> manager);
		~RealTimeDataServer();

		// IModuleServer interface
		std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const override;
		std::string GetModuleName() const override;

	protected:

	private:
		//! Get the data and convert it to a message
		void HandleGetStatus(const std::vector<std::string>& arguments, std::string& answer) const;

		//! Get the error data and convert it to a message
		void HandleGetErrors(const std::vector<std::string>& arguments, std::string& answer) const;

		//! Get the error data and convert it to a message
		void HandleGetVersions(const std::vector<std::string>& arguments, std::string& answer) const;

		//! Build response message from the data
		void ConvertDataToMessage(const RealTimeDataMessageDefinitions::TopicMap& data, 
			std::string& answer) const;

		//! Convert a value (name, value and unit) to a coma separated string
		std::string ValueToString(const RealTimeDataMessageDefinitions::Property& value) const;

		//! Get the current status of the vehicle so that it can be sent to client
		void GetCurrentStatus(std::map<std::string, RealTimeDataMessageDefinitions::PropertyMap>& data) const;

		//! On startup create the descriptors we will need
		void CreateDescriptors();

		//! Get the current errors so that it can be sent to client
		void GetCurrentErrors(std::map<std::string, std::vector<std::string>>& errors) const;

		//! Build response message from the errors
		void ConvertErrorsToMessage(const std::map<std::string, std::vector<std::string>>& errors,
			std::string& answer) const;

		//! Get the current versions
		void GetVersions(std::map<std::string, std::string>& versions) const;

		//! Build response message from the versions
		void ConvertVersionsToMessage(const std::map<std::string, std::string>& versions,
			std::string& answer) const;


		//!@{
		//! Get sub system data
		void GetLocalizationStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetDriveSystemStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetBatteryStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetLightsStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetDrivingStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetObstacleStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetPeripheralsStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		void GetTrafficLightStatus(RealTimeDataMessageDefinitions::PropertyMap& status) const;
		//!@}

	private:
		std::shared_ptr<OhmioModel::LocalizationStatus> m_localization;	//!< Data source for location
		std::shared_ptr<OhmioModel::BatteryStatus> m_battery;			//!< Data source for battery
		std::shared_ptr<OhmioModel::DriveStatus> m_drive;				//!< Data source for drive (state, track, etc)
		std::shared_ptr<OhmioModel::DrivingLightStatus> m_light;		//!< Data source for lights
		std::shared_ptr<OhmioModel::DriveSystemStatus> m_motor;			//!< Data source for motor, break, etc
		std::shared_ptr<OhmioModel::ObstacleStatus> m_obstacle;			//!< Data source for obstacleSystem
		std::shared_ptr<OhmioModel::PeripheralStatus> m_peripherals;	//!< Data source for peripherals (door, air con, etc)
		std::shared_ptr<OhmioModel::TrafficLightStatus> m_trafficLight;	//!< Data source for traffic light
		std::shared_ptr<OhmioModel::ErrorStatus> m_ErrorStatus;			//!< Data source for errors
		std::shared_ptr<Ohmio::VersionsStatus> m_VersionStatus;	//!< Data source for versions
		std::map<std::string, RealTimeDataMessageDefinitions::Description> m_descriptors; //!< Helper for creating descriptors
		std::shared_ptr<Ohmio::NameTranslator> m_nameHelper;			//!< for translating unit IDs to string
	};


}

