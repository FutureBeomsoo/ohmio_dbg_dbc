#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"

extern "C"
{
#include "canbus/dbc_CAN_peripheral.h"
}

namespace OhmioControl
{
	//! The wipers we have
	enum class wiperId
	{
		front,	//!< front wiper
		rear,	//!< rear wiper
		
		// always add after this
		last
	};


	//! Control the wipers
	//
	//! Note that this is also a model holding the current state of the wipers
	class WipersControl : public Ohmio::IMessageObserver
	{
	public:
		WipersControl(std::shared_ptr<Ohmio::MessageReceiver> receiver, std::shared_ptr<Ohmio::MessageBuffer> writeBuffer);
		~WipersControl();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! What mode is the requested wiper in now 
		WIPER_MODE GetWiperMode(wiperId wiper);

		//! What is the interval? 
		//
		//@return time (seconds) between wipes if modeis WIPER_MODE::WIPER_INTERVAL
		//! is WIPER_MODE::WIPER_INTERVAL
		double GetWiperInterval(wiperId wiper);

		//! Set wiper function
		//
		//@param[in] wiper - which wiper to set
		//@param[in] mode - the mode to use
		//@param[in] interval - time (seconds) between wipes if mode
		//! is WIPER_MODE::WIPER_INTERVAL
		void SetWiperMode(wiperId wiper, WIPER_MODE mode, double interval);
		
		//! Turn on the spray for a fixed period
		void SetSpray(wiperId wiper);

	private:
		//! struct for wiper state
		class WiperInfo
		{
		public:
			WiperInfo() : mode(WIPER_MODE::WIPER_IDLE), interval(0) {}
			~WiperInfo() {}

			WIPER_MODE mode;
			double interval;
		};

		//! Get the message ID for sending wiper command
		uint64_t GetWiperRequestId(wiperId wiper);

		//! Get the wiper index for status message ID 
		int GetWiperId(uint64_t statusMessageId);

		//! Received a status message
		void UpdateStatus(const Ohmio::CAN_MSG & message);

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for sending to vehicle
		std::array<WiperInfo, (int)wiperId::last> m_wiperStatus;
	};


}

