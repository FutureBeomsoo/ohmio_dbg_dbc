#pragma once
#include "asio.hpp"
#include "Room.h"

namespace OhmioTcp
{
	//! The TCP server for communication with the vehicle
	class Server 
	{
	public:
		//! Constructor
		//
		//! @param[in] io_context - to run the server with
		//! @param[in] ipAddress - the address of the server in format
		//! address:port.
		//! for example tcp://services.hmi.co.nz:27750 or 10.0.10.15:80
		//! @param[in] modules - the collection of server modules for communication with the vehicle
		Server(asio::io_context& io_context, const std::string& ipAddress,
			std::shared_ptr<ServerModuleCollection> modules);
		~Server();

		//! Run the server endless loop
		//
		//! Keep on looking for new connections (clients).
		//! When a client is connecting create a session to handle it 
		void Run();

	private:
		//! Called to find new clients and register them
		void do_accept();

	private:
		std::shared_ptr<asio::ip::tcp::acceptor> m_acceptor;	//!< the main socket for connecting new clients
		std::shared_ptr<Room> m_room;			//!< the 'room' that hosts the communication
		std::shared_ptr<ServerModuleCollection> m_modules; //! the modules for talking to the vehicle
	};

}

