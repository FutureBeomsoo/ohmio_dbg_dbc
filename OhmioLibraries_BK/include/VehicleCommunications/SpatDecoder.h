#pragma once

#include "IMessageDecoder.h"
#include "SpatMessageData.h"

namespace V2XComms
{
	//! Decode a SPST message
	class SpatDecoder : public IMessageDecoder
	{
	public:
		SpatDecoder(SPAT_t& msg);
		~SpatDecoder();

		//! Decode the current message into a JSON string
		void Decode(std::string& result) override;

	private:

		void DecodeIntersection(IntersectionState_t* intersection, V2XComms::SpatMessageData& intersectionData);
		void DecodeMovementState(MovementState_t*  movment, V2XComms::SignalGroup& group);
		void DecodeMovementEvent(MovementEvent_t* event, V2XComms::SignalGroup& group);

	private:
		SPAT_t& m_msg;
	};


}
