#pragma once

#include <vector>


namespace Ohmio
{
	namespace DataTransfer
	{

		//! Helper class for the data transfer
		//
		//! To shared code between the send and receive
		class Helper
		{
		public:
			//! How many byte we get from each packet?
			static const size_t BytesPerPacket = 6;

			//! send partial verification every x packets
			static const int PartialVerificationPackets = 256;

			// Calculate a single packet checksum
			static uint8_t CalculateChecksum(const std::vector<uint8_t>& data, size_t byteIndex);
			
			// Calculate 16 bit verification code for data
			static uint16_t CalculatePartialVerification(const std::vector<uint8_t>& data, size_t numBytes);

			//! Calculate the MD5 (or any other) code for the data 
			static uint64_t CalculateVerificationCode(const std::vector<uint8_t>& data);

			//! Calculate the MD5 (or any other) code for the data 
			static uint64_t CalculateVerificationCode(uint32_t *data, int length);

			//! convert a 64 bit value to byte array and add to an existing vector
			static void PushToBytes(uint64_t value, std::vector<uint8_t>& bytes, int numToPush);

			//! convert data to byte array and add to an existing vector
			static void  PushToBytes(uint8_t*src, int numBytes, std::vector<uint8_t>& bytes);

			//! Create a 64 bit number from byte array
			//
			//! Used for getting the header information
			static uint64_t GetFromBytes(const std::vector<uint8_t>& bytes, int start);

			//! Convert a byte index to the appropriate packet index for resending
			//
			//! Used for restarting the transfer after partial verification failed.
			//! Note that you need to call StartingPacketToIndex to get the correct
			//! index for resending as the packet index is quantized.
			//! @param[in] index - the index to convert. 
			//! @return - the new starting packet index to send to the receiver 
			//! so that they can start getting data again
			static uint16_t IndexToStartingPacket(size_t index);
			
			//! Convert a packet index to the correct index in the data for transfer
			//
			//! Used for restarting the transfer after partial verification failed
			//! @param[in] startingPacket - the new packet index
			//! @return - the index of the byte corresponding to this packet index
			static size_t StartingPacketToIndex(uint16_t startingPacket);

		};
	}
}

