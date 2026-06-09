#pragma once

#include "CommonInclude.h"
#include "IMessageObserver.h"
#include <set>
extern "C"
{
#include "canbus/dbc_CAN_peripheral.h"
}


namespace Ohmio
{
	//! Handle the mixed light messages CAN_ID_LIGHT1_STATUS and CAN_ID_LIGHT2_STATUS
	//
	//! These messages are still used in mixed mode for both hardware systems
	class MixedLightMessageHandler : public IMessageObserver
	{
	public:
		MixedLightMessageHandler(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~MixedLightMessageHandler();

		// What messages do we use
		void GetAllMessageIds(std::set<uint64_t>& lightMessages) const;

		//@{
		//! Get the current state of a complex light
		void GetRearLightStateAsMessageData(RearLightMsg_t & messageData) const;
		void GetFrontLightStateAsMessageData(FrontLightMsg_t& messageData) const;
		//@}

		// Inherited via IMessageObserver
		virtual void MessageCallback(const CAN_MSG & message) override;


	private:
		std::map<uint64_t, Ohmio::CAN_MSG> m_currentStatus; //!< the current information about the lights

	};

}
