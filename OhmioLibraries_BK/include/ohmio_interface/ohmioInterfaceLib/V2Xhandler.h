#pragma once
#include "CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"

class V2XhandlerTests; // forward declaration for friend

namespace Ohmio
{
	//! Use messages from the V2X
	class IV2XConsumer
	{
	public:
		//! Called when we get a V2X message
		//
		//! @param[in] message - JSON string with the message data
		//! @param[in] isLive - true if the V2X is working, False if in error state
		virtual void Consume(std::string message, bool isLive) = 0;
	};

	//! Handle V2X communications
	//
	//! Runs a TCP server loop to get messages from the V2X unit.
	//! In the future it may answer with information to the unit
	//! Sends the relevant information to units that register for messages.
	//! At the moment the only V2X information is traffic light
	class IV2Xhandler : public Threading::RunInThreadForever
	{
	public:

		//! constructor
		IV2Xhandler(std::string address);
		virtual ~IV2Xhandler();


		//! Factory method to create the receiver of the right type 
		//
		//! @param[in] serverAddress - address for communication with the V2X program
		//! - 192.168.137.100:5641 for the OBU
		//! - 0.0.0.0:37008 for the OBU simulated from wireshark
		//! - file name for simulating the OBU from a text file
		static std::shared_ptr<IV2Xhandler> CretaeReceiver(std::string address);



		//! Register to receive V2X messages 
		void Register(std::shared_ptr<IV2XConsumer> consumer);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		int GetWatchdogPeriod() override;

		//! Open the communication channel
		virtual bool Open(std::string hostAddress) = 0;

		//! Read message from the server
		virtual void GetObuMessage() = 0;

		//! Are we getting messages from OBU
		virtual bool IsLive() = 0;



	private:
		//! Decode a message
		void DecodeMessage();

		void SendErrorIfNeeded();
	protected:
		std::string m_hostAddress;			//!< IP address or file name of the OBU 
		std::vector<uint8_t> m_messgeIn;	//!< the message as a binary string
		bool m_IsOpened;					//!< is communication initialized?

	private:
		std::vector<std::shared_ptr<IV2XConsumer>> m_consumers;

		friend V2XhandlerTests; // make the test friend so that it call RunLoopOnce and not need to run the thread 
	};
}
