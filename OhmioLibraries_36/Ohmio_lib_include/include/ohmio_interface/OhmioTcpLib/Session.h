#pragma once

#include "commonInclude.h"
#include "Room.h"
#include <deque>
#include "asio.hpp"

namespace OhmioTcp
{
	//! Representing a single client involved in communication with the vehicle.
	//
	//! This is where most of the work is done.
	class Session : public IParticipant, public std::enable_shared_from_this<Session>
	{
	public:
		//! Constructor
		//
		//! @param[in] socket - the socket this client is talking on
		//! @param[in] room - the 'room' that is used to host the communication
		//! @param[in] modules - the collection of server modules for communication with the vehicle
		Session(asio::ip::tcp::socket socket, std::shared_ptr<Room> room,
			std::shared_ptr<ServerModuleCollection> modules);
		~Session();

		//! Start interactions with the server
		void start();

		//! Send a message to the client
		//
		//! @param[in] msg -  the message to send
		void deliver(std::string msg);

	private:
		//! Got a message from client. Need to send to the vehicle and other clients
		void MessageFromClient();

		//! Got a message from vehicle (or other clients). Pass it to client
		void MessageToClient();

		//! process the message we got
		void HandleMessageFromClient();

	private:
		std::shared_ptr<Room> m_room;				//!< the 'room' we use for conversations
		asio::ip::tcp::socket m_socket;				//!< the socket uses for communication
		asio::streambuf m_readBuffer;				//!< data we got from client
		std::shared_ptr<StringBuffer> m_msgsToClient;	//!< messages to send to the client
		std::shared_ptr<ServerModuleCollection> m_modules; //! the modules for talking to the vehicle
	};
}

