#pragma once

#include "OhmioControlLib/ControlManager.h"
#include "commonInclude.h"

namespace OhmioTcp
{
	//! an interface for a server to handle a specific module
	//
	//! Collects the relevant status and notify the client when status changes.
	//! Passes control commands from the client to the vehicle.
	//! This is done by translating the commands to function calls on the
	//! right unit. The unit will convert these calls to CAN messages as needed
	class IModuleServer
	{
	public:
		IModuleServer();
		virtual ~IModuleServer();

		//! Process a client request
		//
		//! @param[in] command - the message meaning. An enum of the right type for the module
		//! @param[in] arguments - list of arguments for the command (may be empty)
		virtual std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const = 0;

		//! Get name. Note that the name needs to be the same as in IModuleClient
		virtual std::string GetModuleName() const = 0;

		//! Factory method to create a module
		static std::shared_ptr<OhmioTcp::IModuleServer> CreateModule(const std::string& moduleName, 
			std::shared_ptr<OhmioControl::ControlManager> controlManager, 
			std::shared_ptr<Ohmio::CommunicationManager> vehicle, int moduleIdxForDebugging);

	private:

	};


	//! mock module for testing
	//
	//! To make 
	class MockModuleServer : public IModuleServer
	{
	public:
		MockModuleServer(int serverIdx, std::string name) : m_serverID(serverIdx), m_name(name) { }
		~MockModuleServer() {}

		//! Always answers with a name and ID and the command and arguments so it is
		//! easy to unit test the base class
		std::string ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) const override
		{
			std::string answer = GetModuleName() + ": ";
			answer += std::to_string(command);
			for (const auto& a : arguments)
			{
				answer += ", ";
				answer += a;
			}

			return answer;
		}

		//! Append ID to name to make it easy to test
		std::string GetModuleName() const override
		{
			return "MockServerFor_" + m_name + "_" + std::to_string(m_serverID);
		}

	protected:


	private:
		int m_serverID;			//!< for testing
		std::string m_name;		//!< the name of the server we wanted to create

	};

}

