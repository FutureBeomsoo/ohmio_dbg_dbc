#pragma once
#include "version.h"
#include <string>


// don't know how to test th1s. need to know the address of the computer used for running
// but it is being tested as part of EncryptionTests and HmiLicenceTests
namespace LicenceUtils
{
	//! Get the MAC address of this computer
	class HardwareId
	{
	public:
		//! Get the hardware dependant ID
		//
		//! @param[in] fullId - if true get all that we can, false just a limited Id. 
		//! The limited id option is there for testing when the hardaware used is not constant
		//! @return the id string
		static std::string GetHardwareId(bool fullId);

	private:

		//! Get the MAC address as a string (something like 1C1B0DC7CEA4)
		static std::string GetMacAddress();

		//! Get the disk serial number as a string
		static std::string GetDiskId();
	};
}

