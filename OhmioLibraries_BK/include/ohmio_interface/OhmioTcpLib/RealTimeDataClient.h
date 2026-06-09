#pragma once

#include "IModuleClient.h"
#include "RealTimeDataMessageDefinitions.h"
#include <mutex>

namespace OhmioTcp
{
	//! For reporting real time data from the vehicle
	class RealTimeDataClient : public IModuleClient
	{
	public:
		RealTimeDataClient();
		~RealTimeDataClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;

		//! Create a command string for sending to the server 
		std::string CreateStatusRequest();

		//! Create a command string for sending to the server 
		std::string CreateErrorsRequest();

		//! Create a command string for sending to the server 
		std::string CreateVersionsRequest();

		//! Get all the topics that we collect real time data for
		void GetTopicNames(std::vector<std::string>& topicList);

		//! Get the data for a topic
		void GetTopicData(const std::string& name, RealTimeDataMessageDefinitions::PropertyMap& topicData);

		//! Get all the modules that we collect error data for
		void GetErrorModuleNames(std::vector<std::string>& moduleList);

		//! Get the errors for a module
		void GetModuleErrors(const std::string& name, std::vector<std::string>& errorList);


		//! Get all the modules that we collect version data for
		void GetVersionModuleNames(std::vector<std::string>& moduleList);

		//! Get the version for a module
		void GetModuleVersion(const std::string& name, std::string& version);

		//! Register an observer for change notification
		void RegisterToChange(std::shared_ptr<RealTimeDataMessageDefinitions::IChangeObserver> observer);

	protected:
		// IModuleClient interface
		void SendPollingRequests() override;

	private:
		//! Read the data
		bool HandleGetStatus(const std::vector<std::string>& arguments);

		//! Read the data from arguments and update m_data
		bool ReadStatusData(const std::vector<std::string> &arguments, std::set<std::string> &changedTopics);

		//! Read the error data
		bool HandleGetErrors(const std::vector<std::string>& arguments);

		//! Read the versions data
		bool HandleGetVersions(const std::vector<std::string>& arguments);

		//! Read a property out of the arguments
		int ReadProperty(const std::vector<std::string>& arguments, int startIdx, 
			RealTimeDataMessageDefinitions::Property& property);


		//! For enum types we add all the values to the type
		void AddEnumValuesAsNeeded(RealTimeDataMessageDefinitions::Description& description);

		//! update observers
		void NotifyChanges(const std::set<std::string>& changedTopics, RealTimeDataMessageDefinitions::DataTypes whatChanged);

		//! Swap m_data with currentState 
		void UpdateCurrentState(RealTimeDataMessageDefinitions::TopicMap& currentState);

		//! Swap m_versionData with versions, return true if there is a change 
		bool UpdateVersions(std::map<std::string, std::string>& versions);

		//! Swap m_errorData with errors, return true if there is a change 
		bool UpdateErrors(std::map<std::string, std::vector<std::string>>& errors);

	private:
		RealTimeDataMessageDefinitions::TopicMap m_data;	//!< current state
		std::map<std::string, std::vector<std::string>> m_errorData;	//!< current errors
		std::map<std::string, std::string> m_versionData;	//!< current versions
		std::mutex m_mutex;		//!< for locking the data  
		bool m_lastAnswerOK;	//!< was the last request successful
		std::shared_ptr<Ohmio::NameTranslator> m_translator; //!< for getting names as strings
		std::vector<std::shared_ptr<RealTimeDataMessageDefinitions::IChangeObserver>> m_observers; //!< Observers to tell when data change

	};

}
