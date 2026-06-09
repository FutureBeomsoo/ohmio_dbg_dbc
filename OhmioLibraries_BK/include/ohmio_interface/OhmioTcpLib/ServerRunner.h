#pragma once
#include <memory>
#include <thread>
#include "commonInclude.h"
#include "OhmioControlLib/CommonInclude.h"


namespace OhmioTcp
{
	//! run the server. This is the starting point for the main application that is connected to the CAN bus
	class ServerRunner
	{
	public:
		ServerRunner();
		~ServerRunner();



		//! Start the server loop.
		//
		//! This starts a server thread and returns immediately  
		//! @param[in] vehicle - the vehicle communication server to get messages to / from
		//! @param[in] controller - the vehicle control for sending commands to the vehicle
		//! @param[in] serverAddress - the TCP address to use
		void Run(std::shared_ptr<Ohmio::CommunicationManager> vehicle, 
			std::shared_ptr<OhmioControl::ControlManager> controller,
			const std::string& serverAddress);


	private:

		//! The server thread that runs forever. Supporting clients connecting to the server 
		void ServrerThread();

	private:
		std::thread	m_theThread;	//!< the thread we run
		std::shared_ptr<Ohmio::CommunicationManager> m_vehicle; // the connection to the vehicle
		std::string m_serverAddress;	//!< TCP connection address
		std::shared_ptr<asio::io_context> m_ioContext;
		std::shared_ptr<ServerModuleCollection> m_serverModules; // the modules that talk to the vehicle
	};

}

