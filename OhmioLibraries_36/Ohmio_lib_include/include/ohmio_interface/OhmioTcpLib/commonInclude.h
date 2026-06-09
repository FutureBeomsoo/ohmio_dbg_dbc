#pragma once
#include "ohmioInterfaceLib/CommonInclude.h"

// This library is based on ASIO example.
// Most of the code is not testable

//! TCP communication library for the Ohmio interface. Based on ASIO chat example. See https://think-async.com/Asio/asio-1.16.1/doc/asio/examples/cpp11_examples.html
//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/2275409947/Some+more+details+of+the+TCP+server+client+design for more on the TCP interface
namespace OhmioTcp
{
	// convert enum to string
#define stringify( name ) # name

	//! interface class for class that participates in conversation with the vehicle 
	class IParticipant
	{
	public:
		IParticipant() {}
		virtual ~IParticipant() {}

		//! Send a message to the connection
		virtual void deliver(std::string msg) = 0;
	};
	typedef std::shared_ptr<IParticipant> Participant_ptr;
	
	class Client;
	class ClientRunner;
	class Session;
	class StringBuffer;
	class IModuleServer;
	class IModuleClient;
	class ServerModuleCollection;
	class ClientModuleCollection;
	class ServerRunner;

	//! Module names
	enum class ModuleNames
	{
		busStop = 0,		//!< bus stop interface
		recording,			//!< recording interface
		realTimeData,		//!< real time data collection
		trafficLight,		//!< traffic light control
		obstacle,			//!< obstacle interface
		driveControl,		//!< drive interface
		announcements,		//!< drive interface

		// always add before this
		last				//!< unused
	};
}

//! forward declarations of asio to avoid needing to include it
namespace asio
{
	class io_context;
}