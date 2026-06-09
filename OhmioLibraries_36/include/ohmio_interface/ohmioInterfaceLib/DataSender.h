#pragma once
#include <mutex>
#include <condition_variable>
#include "CommonInclude.h"
#include "IMessageObserver.h"
#include "canbus/DataTransferDefinitions.h"


#ifdef UseDataTRansfer
	namespace Ohmio
	{
		namespace DataTransfer
		{
			//! Transmit data over the CAN BUS
			//
			//! Implements the sending protocol in
			//! https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1195245596/Generic+data+transmission+over+CAN
			class DataSender : public IMessageObserver
			{
			public:
				//! Constructor
				//
				//! @param[in] reciever - how we get messages from the bus
				//! @param[in] sender - how we send messages to the bus
				//! @param[in] myId - ID of this unit
				//! @param[in] targetId - ID of unit to talk to. Other units will
				//! ignore the message
				//! @param[in] dataType - What is the data for TODO replace with enum
				//! @param[in] timeout - timeout (mSec) to wait for reply.
				//! This is the timeout for every single message sent not the total time.
				//! We need variable timeout for testing of bad cases 
				DataSender(std::shared_ptr<MessageReceiver> reciever, std::shared_ptr<MessageBuffer> sender,
					uint16_t myId, uint16_t targetId, TRANSFER_DATA_TYPES dataType, int timeout = 10000);


				~DataSender();

				// IMessageObserver interface
				void MessageCallback(const CAN_MSG& message) override;

				//! Send data over the bus
				// 
				//! Send a large data to the vehicle. Will be sent with
				//! multiple CAN messages. And add verification information
				//! to make sure the data is sent correctly.
				//! @param[in] dataToSend - the data to send over the bus.
				//! This should include interpretation verification flags. 
				//! Data verification will be added by this function
				//! @return error code of the transfer. 0 if no error
				TRANSFER_ERROR_CODES SendData(const std::vector<uint8_t>& dataToSend);

			protected:
				//! Send a single packet (with resend if needed) and wait for reply
				//
				//! This is virtual and protected so that it can be overridden with specific
				//! errors when mocking this sender for testing
				virtual bool SendPacket(const std::vector<uint8_t>& dataToSend, size_t byteIndex);

				//! Start the partial verification. 
				//
				//! Send verification code for the data up to here and wait for reply
				//! This is virtual and protected so that it can be overridden with specific
				//! errors when mocking this sender for testing
				virtual bool SendPartialVerification(const std::vector<uint8_t>& data, size_t byteIndex);

			private:
				//! Register to get notified with the correct messages
				void RegisterToMessages();

 				//! Start or verify the transfer. Send request and wait for reply
				bool SendUpload_Verify(TRANSFER_DATA_TYPES dataType, TRANSFER_ACTIONS action, uint16_t extra);

				//! Send the length and verification code. Returns after all data was sent
				bool SendVerifcationData(const std::vector<uint8_t>& dataToSend);

				//! send a large stream. Returns after all data was sent
				bool SendByteVector(const std::vector<uint8_t>& data);



				//! did we get ack for the last packet we sent?
				bool IsPacketReplyGood(uint8_t packetId);

				// state of answer from target
				enum class ReplyState
				{
					unkown,		//!< no reply yet
					success,	//!< got ACK reply
					fail,		//!< got NACK reply

					// always add before this line
					last
				};



			private:
				std::shared_ptr<MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
				uint16_t m_myId;			//!< My unit ID. Ignore messages not for this
				uint16_t m_targetId;		//!< Partner unit ID of other side (ignore ack from others) 
				TRANSFER_DATA_TYPES m_dataType;			//!< what is this data for?
				ReplyState m_fullReply;		//!< state of the entire transfer
				ReplyState m_packetReply;	//!< state of the last packet
				uint8_t m_ackPacketId;		//!< the packet id from the ack message
				int m_timeoutReply;			//!< max wait time (mSec) for reply
				TRANSFER_ERROR_CODES m_replyErrorCode;		//!< error code we got (noError if good). from enum TransferErrorCodes
				std::mutex m_mutex;			//!< for locking the message arrived event 
				std::condition_variable m_messageArrived;	//!< we got an answer need to test the results
				uint16_t m_lastVerified;			//!< the last packet index that was verified. Revert to this if verification failes
			};
		}
	}

#endif // !UseDataTRansfer


