#pragma once
#include "ohmioInterfaceLib/CommonInclude.h"

namespace OhmioControl
{
	//! General system management (reset, shutdown, etc)
	class SystemControl
	{
	public:

		SystemControl(std::shared_ptr<Ohmio::MessageBuffer> writeBuffer);

		~SystemControl();

		//! Reset a unit
		//
		//! @param[in] unitId - unit to reset from UNIT_ID enum, FFFF for reset all
		void ResetRequest(int unitId);

		//! turn logging on / off
		void ResetLogging();

		//! shut down the system
		void Shutdown();

		//! recover from emergency
		void Recovery();

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle

	};
}

