#pragma once

#include "DrivingFlagsDefenitions.h"

namespace OhmioModel
{
	//! Serialise event to / from JSON string
	class EventDecoder
	{
	public:
		//! Serialise to JSON sting
		static void ToJson(const TrackEvent& event, std::string& asJson);

		//! Read from JSON string
		static bool FromJson(const std::string& asJson, TrackEvent& event);

	private:

	};
}
