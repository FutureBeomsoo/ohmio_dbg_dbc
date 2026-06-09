#pragma once
#include "commonInclude.h"
#include "ohmioInterfaceLib/ICanBus.h"
#include <thread>
#include <mutex>

namespace OhmioTcp
{
	//! run the client
	//
	//! create the client and start a thread to run it.
	//! This is the starting point on the application side.
	class ClientRunner 
	{
	public:
		//! constructor
		//
		//! @param[in] serverAddress - TCP address (i.e. "127.0.0.1:1234") of the server
		ClientRunner(const std::string& serverAddress);
		~ClientRunner();


		//! Send a message to the server
		void SendToServer(std::string message);

		//! Register a module interested in a topic
		void RegisterDestination(std::shared_ptr<OhmioTcp::IModuleClient> destination);

		//! remove a module from a topic
		void DeRegisterDestination(std::shared_ptr<OhmioTcp::IModuleClient> destination);

		//! Are we alive?
		bool IsConnected();

		//! Stop the connection and the client
		void Done();

	private:
		//! The thread loop that runs forever keeping the IO context alive
		void ThreadLoop();

		//! Watchdog that restart the client if the communication is lost
		void WatchDogLoop();

		//! Starts the client and the IO
		void StartClient();

		//! Stops the client and the IO
		void StopClient();



	private:
		std::shared_ptr<asio::io_context> m_ioContext;		//!< the IO to use
		std::shared_ptr<Client> m_client;	//!< the TCP client
		std::thread m_ioThread;				//!< the thread we run
		std::thread m_watchdogThread;		//!< Keep on monitoring the client
		std::string m_serverAddress;		//!< the server connection string
		bool m_done;						//!< stop the watchdog threads
		std::shared_ptr<ClientModuleCollection> m_modules; //!< in charge of passing messages to the right module
		std::set<std::shared_ptr<OhmioTcp::IModuleClient>> m_destinations; //!< list of modules for this client (probably only 1)
		std::mutex m_mutex;		//!< for locking the list of destinations  


	};

}


