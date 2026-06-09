#pragma once
#include "IMessageObserver.h"
#include "Helper.h"
#include <mutex>
#include <condition_variable>
#include "canbus/DataTransferDefinitions.h"
#include "UtilityLib/Timer.h"

#ifdef UseDataTRansfer
	namespace Ohmio
	{
		namespace DataTransfer
		{
			//! Transmit data over the CAN BUS
			//
			//! Implements the sending protocol in
			//! https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1195245596/Generic+data+transmission+over+CAN
			class DataReceiver : public IMessageObserver
			{
			public:
				//! Constructor
				//
				//! @param[in] bus - Accessor for the bus
				//! @param[in] myId - ID of this unit
				DataReceiver(std::shared_ptr<CommunicationManager> bus, uint16_t myId);
				~DataReceiver();



				// IMessageObserver interface
				void MessageCallback(const CAN_MSG& message) override;

				//! Receive data over the bus
				// 
				//! This will wait until the data is received or failed.
				//! Receive a large data from the CAN bus. Will be sent with
				//! multiple CAN messages. Including verification information
				//! to make sure the data is sent correctly.
				//! @param[out] dataToGot - the data received from the bus.
				//! This should include interpretation verification flags. 
				//! @param[out] senderId - the id of the sender of the data
				//! @param[out] dataType - code indicating what the data means.
				//! @param[in] timeout - timeout (mSec) to wait for a single message.
				//! This is the timeout for every single message sent not the total time.
				//! We need variable timeout for testing of bad cases 
				//! @return true if was able to receive
				bool ReceiveData(std::vector<uint8_t>& dataToGot, uint16_t& senderId, uint8_t& dataType, int timeout = 10000);


			private:
				///@{
				//! Receive a specific message 
				void ReciveStart(const CAN_MSG& message);
				void RecievePacket(const CAN_MSG &message);
				void RecieveDataPacket(const CAN_MSG& message);
				///@}

				//! Process a packet
				//
				// @param[in] message - the message
				// @param[out] packetIdx - the packet index (needed when answering)
				// @return error code from enum TransferErrorCodes (noError for OK) 
				TRANSFER_ERROR_CODES DoRecievePacket(const CAN_MSG& message, uint8_t& packetIdx);

				//! We received 'start transfer' message
				void StartRecieving(uint8_t transferType, uint16_t senderId);

				//! We received 'verify transfer' message
				void VerifyRecieving(uint8_t transferType, uint16_t senderId);

				//! We received 'resend' message to start again from a location
				void ResetLocation(uint16_t startingPacket);

				//! We received 'partial verification' message
				void VerifyPartialData(uint16_t verificationCode);

				//! Send ack / nack for the transfer or packet
				//
				//! @param[in] errorCode - from enum TransferErrorCodes the error (noError for OK) 
				//! @param[in] packetIdx - which packet was it for (ignored if this is a full ack
				//! @param[in] isPacket - true if this is packet, false if whole transfer 
				void SendResults(TRANSFER_ERROR_CODES errorCode, uint8_t packetIdx, bool isPacket);

				//! are the data size and verification code correct?
				bool VrifyData();

				// state of receiving data 
				enum class ReceivingState
				{
					idle,				//!< not receiving
					waitForHeader,		//!< waiting for the header data
					collectingData,		//!< getting the main data
					done,				//!< got all the data 
					failed,				//!< error - stop the transfer
					verified,			//!< verification success

					// always add before this line
					last
				};

				//! change our current state and update the notification flag
				void ChangeState(ReceivingState newState);

			private:
				std::shared_ptr<MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
				uint16_t m_myId;			//!< My unit ID. Ignore messages not for this
				uint16_t m_senderId;		//!< Partner unit ID of other side (ignore ack from others) 
				uint8_t m_dataType;			//!< what is this data for?
				ReceivingState m_sate;		//!< state of data receiving 
				std::vector<uint8_t> m_data;	//!< the data we get
				uint64_t m_expectedVerificationCode;	//!< the verification code as sent to us
				uint64_t m_expectedSize;	//!< the data size as sent to us 
				std::mutex m_mutex;						//!< for locking the state change event 
				std::condition_variable m_stateChange;	//!< our state has changed we should check if finished
				int m_lastRecieveTime;		//!< time of the last message we got
				std::shared_ptr<NTiming_NS::Timer> m_timer; //!< to allow stopping on timeout
			};
		}
	}


#endif // !UseDataTRansfer

