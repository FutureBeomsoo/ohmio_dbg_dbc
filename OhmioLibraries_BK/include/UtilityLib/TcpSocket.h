#pragma once
#include "version.h"
#include <string>
#include <functional>

//! Utilities for networking  
namespace CommunicationUtils
{
	//! A socet communication class for sending and recieving messages over TCP
	//
	//! Based on https://www.geeksforgeeks.org/socket-programming-cc/ 
	class TcpSocket
	{
	public:

		//! Send a message out as a client
		//
		//! Opens the socket, sends the message and close the port.
		//! Not thread safe! if 2 threads try to send at the same time things can get ugly
		//! @param[in] address - the address we send to in the format
		//! address:port. everything before the ':' is a valid IP address 
		//! and after the ':' is the port number.
		//! for example tcp://services.hmi.co.nz:27750 or 10.0.10.15:80
		//! @param[in] message - the message to send
		//! @param[out] reply - the answer from the server
		//! @return true is successful.
		static bool ClientSend(std::string address, const std::string& message, std::string& reply);

		//! Receive a message out as a server
		//
		//! Opens the socket, wait for the client message and sends information back to the client.
		//! Not thread safe! if 2 threads try to send at the same time things can get ugly
		//! @param[in] address - the address we send to in the format
		//! address:port. everything before the ':' is a valid IP address 
		//! and after the ':' is the port number.
		//! for example tcp://services.hmi.co.nz:27750 or 10.0.10.15:80
		//! @param[in] timeout - maximum time (milliseconds) to wait before we give up on finding the client
		//! @param[in] callBack - A callback function to genertae the reply we want to send to the client.
		//! This is how the message from the client is recieved by the caller. 
		//! This fuction takes the message the client sent us and returns the answer we want to give
		//! @return true is successful. If no response is needed the callback can return an empty string.
		static bool ServerReceive(std::string address, int timeout, std::function<std::string(const std::string&)>& callBack);

		//! Break the address to host IP address and port number
		//
		//! @param[in, out] address - the original full adress, returns the address part only
		//! @ return port number
		static int BreakAddressToHostAndPort(std::string& address);

	private:


		//! Connect to the port as a client
		//
		//! @return the socket ID or < 0 for error
		static int ConnectClient(std::string& address, int port);

		//! Connect to the port as a server
		//
		//! Cretae the port, bind and listen. Be ready to look for a client
		//! @return the socket ID or < 0 for error
		static int CretaeServerListeningSocket(std::string& address, int port);

		//! Wait for the client to connect
		//
		//! @param[in] timeout - maximum time (milliseconds) to wait before we give up
		//! @param[in] listenSocket - the socket ID to listen on
		//! @return the socket ID for communicating with the client (< 0 if failed)
		static int ServerWaitForClient(int listenSocket, int timeout);

		//! Close the communication
		static void CloseConnection(int connectionId);

		//! Get the message from the other side
		//
		//! @param[in] reply - the server answer
		//! @return - true if recieved an answer
		static bool WaitForMessage(std::string& reply, int socketId);
		
		//! Get the error code as string
		static std::string GetLastError();

	};
}

