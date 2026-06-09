#pragma once

#include <memory>
#include <vector>
#include "ohmioInterfaceLib/CommonInclude.h"
#include "OhmioControlLib/ControlManager.h"
#include "OhmioTcpLib/commonInclude.h"



namespace OhmioInterfacePy
{
	// forward declarations
	class DriveInterface;

	//! construct all the required parts
	class InterfaceManager
	{
	public:
		//! constructor
		//
		//! @param[in] connectionInfo - How to connect to the vehicle:
		//! TCP address (i.e. "127.0.0.1:1234")
		//! @param[in] emulator - set to true if this is the emulator
		InterfaceManager(std::string connectionInfo);
		~InterfaceManager();

		//! Are we connected top the vehicle?
		bool IsActive();

		//! Get access to the vehicle
		std::shared_ptr<OhmioTcp::ClientRunner> GetVehicleConnection();

		//! Get the default connection string to use for the vehicle
		static std::string GetDefaultAddress();

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we interact with the vehicle

	};
}

