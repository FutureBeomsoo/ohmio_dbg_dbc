#pragma once

#include "commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"

namespace OhmioTcp
{
	//! Holds the modules used by the client side to talk with the vehicle.
	//
	//! This class has a message buffer and runs a thread to keep reading the 
	//! messages and pass them to the right module.
	//! modules need to be registered with the collection
	class ClientModuleCollection : public Threading::RunInThreadForever
	{

	public:
		ClientModuleCollection();
		~ClientModuleCollection();


		//! Register a module interested in a topic
		void RegisterDestination(std::shared_ptr<OhmioTcp::IModuleClient> destination,
			std::shared_ptr<Client> client);

		//! remove a module from a topic
		void DeRegisterDestination(std::shared_ptr<OhmioTcp::IModuleClient> destination);

		//! Remove all modules
		void DeRegisterAll();

		//! get the message buffer for clients to push messages to
		std::shared_ptr<StringBuffer> GetReadBuffer();

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;



	private:
		void HandleStringMessage(std::string message);

	private:
		std::mutex m_mutex;		//!< for locking the map while adding modules  
		std::shared_ptr<StringBuffer> m_readBuffer; //! Buffer of messages from server

		//! Map from module names to listeners that are interested in messages
		std::multimap<std::string, std::shared_ptr<OhmioTcp::IModuleClient>> m_messageTargets;

	};

}


