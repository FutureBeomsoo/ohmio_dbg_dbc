#pragma once
#include "InterfaceManager.h"
#include <string>
#include <functional>
#include "OhmioTcpLib/RealTimeDataClient.h"



namespace OhmioInterfacePy
{

	//! A value with the associated unit
	class ValueUnit
	{
	public:
		ValueUnit(double v = 0) : value(v) {}
		~ValueUnit() {}

		double value;		//!< the value
		std::map<std::string, std::string> unit;	//!< list of properties of the unit
	};

	//! Access to real time data from the vehicle 
	class RealTimeInterface
	{
	public:
		RealTimeInterface(InterfaceManager& manager);
		~RealTimeInterface();

		///@{
		//! push notification for change in status. This will be called for all registered observers when data is changes
		//
		//! @param[out] topic - name of topic that had changed
		//! @param[out] info - the new topic data
		using TopicChangeCallback = std::function<void(const std::string& topic, const std::map<std::string, ValueUnit>& info)>;
		using ErrorChangeCallback = std::function<void(std::map<std::string, std::vector<std::string>>& info)>;
		using VersionChangeCallback = std::function<void(std::map<std::string, std::string>& info)>;
		///@}

		//! Get all the real time data
		//
		//! @return - All the data.
		//! The map keys are the 'topics' that are monitored.
		//! the values are maps of named values and their units
		std::map<std::string, std::map<std::string, ValueUnit>> GetAllData();

		//! Get the names of all the topics that are monitored
		//
		//! @return - list of topic names that can be accessed
		std::vector<std::string> GetTopicNames();

		//! Get the real time data for a specific topic
		//
		//! @return - the data for a topic.
		//! The map keys are the names of values in the topic. 
		//! The values are pairs of values and their units.
		std::map<std::string, ValueUnit> GetTopicData(std::string name);

		//! Get the error data
		//
		//! @return - the error data.
		//! The map keys are the modules that can generate errors.
		//! The values are list of active errors. 
		//! When a module has no active errors the list is empty
		std::map<std::string, std::vector<std::string>> GetErrorData();

		//! Get the names of all the modules that may create errors
		//
		//! @return - list of module names that can be accessed
		std::vector<std::string> GetErrorModuleNames();

		//! Get the error data for a module
		//
		//! @return - the error data. A list of active errors. 
		//! When a module has no active errors the list is empty
		std::vector<std::string> GetModuleErrors(std::string name);

		//! Get the version data
		//
		//! @return - the version data.
		//! The map keys are the modules that have version information.
		//! The values are version strings of the format major.minor.build
		std::map<std::string, std::string> GetVersionData();

		//! Get the names of all the modules with versions
		//
		//! @return - list of module names that can be accessed
		std::vector<std::string> GetVersionModuleNames();

		//! Get the version of a module
		//
		//! @return - the version strings of the format major.minor.build 
		//! If the version is unkown returns an empty string.
		std::string GetModuleVersion(std::string name);

		///@{
		//! Register to get notification about real time data, error, version changes
		void RegisterForDataChange(TopicChangeCallback observer);
		void RegisterForErrorChange(ErrorChangeCallback observer);
		void RegisterForVersionChange(VersionChangeCallback observer);
		///@}

		//! Get called When a topic is changed so that we can call all observers 
		void TopicChanged(OhmioTcp::RealTimeDataMessageDefinitions::DataTypes whatChanged, std::string topicName);

		///@{
		//! Update observer when change happened
		void OnStatusChanged(std::string topicName);
		void OnVersionChanged();
		void OnErrorChanged();
		///@}

	private:
		//! Helper class for getting change notification
		class ChangeObserver : public OhmioTcp::RealTimeDataMessageDefinitions::IChangeObserver
		{
		public:
			ChangeObserver(RealTimeInterface& target) : m_target(target) {}
			~ChangeObserver() {}

			virtual void OnChange(OhmioTcp::RealTimeDataMessageDefinitions::DataTypes whatChanged, std::string topic) override
			{
				m_target.TopicChanged(whatChanged, topic);
			}

			RealTimeInterface& m_target;
		};

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::RealTimeDataClient> m_responseServer;		//!< how we get data from the vehicle
		std::shared_ptr< OhmioTcp::RealTimeDataMessageDefinitions::IChangeObserver> m_changeHelper;	//!< to register as observer
		std::vector<TopicChangeCallback> m_topicObservers;			//!< observers to update about status changes
		std::vector<ErrorChangeCallback> m_errorObservers;			//!< observers to update about error changes
		std::vector<VersionChangeCallback> m_versionObservers;		//!< observers to update about version changes

	};

}
