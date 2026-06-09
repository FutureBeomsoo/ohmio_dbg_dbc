#pragma once
#include "CommonInclude.h"
#include "ICanBus.h"
#include "MessageBuffer.h"
#include "UtilityLib/RunInThreadForever.h"
#include "UtilityLib/Timer.h"

namespace Ohmio
{
	//! Loop for listening on a CAN bus for messages
	//
	//! Runs a thread that keeps on polling the CAN bus for messages
	class CanbusLoop : public Threading::RunInThreadForever
	{
	public:
		//! Constructor 
		//
		//! @param[in] inputBuffer - buffer for messages from the vehicle
		//! @param[in] outputBuffer - buffer for messages to the vehicle
		//! @param[in] source - the actual CAN bus reader. Normally it will be of class Canbus 
		//! But for testing we can use a mock here
		//! @param[in] versionPollingPeriod - Insert version request message every X milliseconds.
		//! For testing we can disable the polling by using negative value 
		CanbusLoop(std::shared_ptr<MessageBuffer> inputBuffer, std::shared_ptr<MessageBuffer> outputBuffer,
			std::shared_ptr<ICanBus> source, std::shared_ptr<SafetyRegulator> safety, int versionPollingPeriod);
		virtual ~CanbusLoop();

		//! Are we connected to the vehicle 
		bool IsConnected();

	protected:
		// Inherited via RunInThreadForever
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Push a message to the buffer
		void PushMessageToBuffer(const  CAN_MSG& canData);

		//! Read messages from the vehicle and push to the read buffer. Return number of messages
		int ReadMessagesFromVehicle();

		//! Get messages from the write buffer and write to the vehicle. Return the number written 
		int WriteMessagesToVehicle();

		//! Collect the message from write buffer and sort them by bus
		int CollectMessagesToSend(std::array<std::vector<CAN_MSG>, (int)CanBuses::lastCan> &canMsgs);

		//! write to the bus
		void SendToVehicle(std::array<std::vector<CAN_MSG>, (int)CanBuses::lastCan> &canMsgs);

		//! Is it time to ask units about their versions
		bool IsTimeToPollForVersions();


	private:
		std::shared_ptr<ICanBus> m_canbus;	//!< the CAN bus to listen to
		std::shared_ptr<MessageBuffer> m_readingBuffer;	//!< message buffer for messages FROM the vehicle	
		std::shared_ptr<MessageBuffer> m_writingBuffer;	//!< message buffer for messages TO the vehicle	
		std::shared_ptr<SafetyRegulator> m_safety;		//!< block unsafe messages
		bool m_initialised;					//!< is the can initialized?
		bool m_SleepIfNotBusy;				//!< should we sleep when detecting no messages?
		NTiming_NS::Timer m_timer;			//!< to monitor time between events
		int m_lastVersionPolling;			//!< last time we polled the version
		int m_versionPollingPeriod;			//!< period (mSec) between calls to version request
	};
}