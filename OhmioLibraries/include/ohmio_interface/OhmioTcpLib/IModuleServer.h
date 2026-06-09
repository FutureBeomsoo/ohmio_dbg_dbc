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
		std::string ProcessMessage(int command, const std::vector<std::string>& arguments);

		//! Get name. Note that the name needs to be the same as in IModuleClient
		virtual std::string GetModuleName() const = 0;

		//! Get the ID. Note that the ID needs to be the same as in IModuleClient
		virtual ModuleNames GetModuleId() const = 0;

		//! Factory method to create a module
		static std::shared_ptr<OhmioTcp::IModuleServer> CreateModule(ModuleNames moduleToCreate, 
			std::shared_ptr<OhmioControl::ControlManager> controlManager, 
			std::shared_ptr<Ohmio::CommunicationManager> vehicle);


	protected:
		bool CheckArgumaentSize(int command, const std::vector<std::string>& arguments, int expected) const;

		//! Process a client request
		//
		//! @param[in] command - the message meaning. An enum of the right type for the module
		//! @param[in] arguments - list of arguments for the command (may be empty)
		//! @param[in,out] answer - the answer to the message. Base class fills in the defaults and the derived classes add the details 
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) = 0;
	private:

	};


	//! mock module for testing
	//
	//! To make 
	class MockModuleServer : public IModuleServer
	{
	public:
		MockModuleServer(std::string name) : m_name(name) { }
		~MockModuleServer() {}


		//! Append ID to name to make it easy to test
		std::string GetModuleName() const override
		{
			return "MockServerFor_" + m_name;
		}
		virtual ModuleNames GetModuleId() const override
		{
			return ModuleNames::last;
		}

	protected:
		//! Always answers with a name and ID and the command and arguments so it is
		//! easy to unit test the base class
		void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) override
		{
			for (const auto& a : arguments)
			{
				answer += a;
				answer += ",";
			}
			answer += "0";
			command = 0; // unused
		}


	private:
		std::string m_name;		//!< the name of the server we wanted to create
	};

}

