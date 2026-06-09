#pragma once

#include <memory>
#include "ohmioInterfaceLib/CommonInclude.h"

namespace OhmioControl
{
	class BatteryControl
	{
	public:
		BatteryControl(std::shared_ptr<Ohmio::MessageBuffer> writeBuffer);
		~BatteryControl();


		//! Set the charging current
		//
		//! @param[in] current - from enum BMS_CHARGE_CURRENT
		void SetChargingCurrent(int current);


	private:
		void SendVerificationRequest();
		void SendChargeRequest(int current);

	private:

		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
	};
}
