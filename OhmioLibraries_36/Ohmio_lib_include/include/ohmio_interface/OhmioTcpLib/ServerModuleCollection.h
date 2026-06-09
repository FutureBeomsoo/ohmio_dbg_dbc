#pragma once

#include "commonInclude.h"
#include "OhmioControlLib/ControlManager.h"

namespace OhmioTcp
{
	//! Holds (and creates) the modules used by the server side to talk with the vehicle.
	//
	//! This class is in charge of ALL (non CAN) messages sent to the vehicle (over TCP).
	//! It is responsible for creating a SINGLE server module for each 'topic'.
	//! The server module translates TCP commands into function calls for the right unit.
	//! The unit will convert the calls to CAN message(s)
	class ServerModuleCollection
	{

	public:
		ServerModuleCollection(std::shared_ptr<OhmioControl::ControlManager> controller, std::shared_ptr<Ohmio::CommunicationManager> vehicle);
		~ServerModuleCollection();

		//! Process a string message.
		//
		//! Find the right module and pass the message on
		//! @param[in] messageText - the message we got from the client
		//! @return - the reply to the client (may be empty)
		std::string ProsessMessage(const std::string& messageText);

		//! How many modules we have. For debugging / testing only
		int GetNumModules();

		//! Parse a message to get the module, command and parameters
		//
		//! static to allow the server and client to use it
		//! @param[in] message - the message to parse
		//! @param[out] moduleId - the module to pass the command to
		//! @param[out] command - the command to perform
		//! @param[out] arguments - list of parameters
		//! @return true if this can be parsed
		static bool ParseMessage(const std::string& message, int& moduleId,
			int& command, std::vector<std::string>& arguments);


	private:
		//! Find (or create) a module by name
		std::shared_ptr<OhmioTcp::IModuleServer> FindModule(int moduleId);

	private:
		std::map<ModuleNames, std::shared_ptr<IModuleServer>> m_modules;	//!< all the modules that we need
		std::shared_ptr<OhmioControl::ControlManager> m_controlManager;		//!< for creating modules that need control
		std::shared_ptr<Ohmio::CommunicationManager> m_vehicle;				//!< for creating listeners to the vehicle
		std::mutex m_mutex;		//!< for locking the map while adding modules  
	};

}

