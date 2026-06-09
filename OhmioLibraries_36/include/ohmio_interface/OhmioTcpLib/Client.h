#pragma once
#include "asio.hpp"
#include "commonInclude.h"
#include <deque>

namespace OhmioTcp
{
	//! TCP client to talk to the interface
	//
	//! responsible for send and receive messages from TCP.
	//! The client runner is responsible for communicating with the application
	//! (getting messages from the application and passing vehicle state to the application)
	class Client
	{
	public:
		//! Constructor
		//
		//! @param[in] io_context - to run the client with
		//! @param[in] ipAddress - the address of the server in format
		//! address:port.
		//! for example tcp://services.hmi.co.nz:27750 or 10.0.10.15:80
		//! @param[in] vehicle - message buffer to hold messages from vehicle
		Client(asio::io_context& io_context, const std::string& ipAddress,
			std::shared_ptr<StringBuffer> vehicle);

		~Client();

		//! Send a message to the server
		void MessageToServer(std::string msg);

		//! End the connection
		void close();

		bool IsConnected() const;

		//! Has the IO listener times out?
		bool Timeout(double mSec) const;

	private:
		//! Connect to the server
		void Connect(const asio::ip::tcp::resolver::results_type& endpoints);

		//! Get the latest message from the server
		void GetFromServer();

		//! Send a message to the server
		void SendToServer();

		//! pass m_msgFromServer to the client receive buffer
		void WriteToRecieveBuffer();


	private:
		//! buffer for reading from vehicle. We put all messages we got here so that the receiver can use them
		std::shared_ptr<StringBuffer> m_vehicleRead;

		asio::io_context& m_ioContext;	//!< the context we need
		asio::ip::tcp::socket m_socket;	//!< the socket used for communication
		asio::streambuf m_readBuffer;				//!< data we got from server
		std::shared_ptr<StringBuffer> m_msgsToServer;		//!< messages to send to the server
		bool m_connected;				//!< are we connected to the server?
		std::chrono::system_clock::time_point m_hartbit;	//!< monitor the read to detect timeout
	};

}

