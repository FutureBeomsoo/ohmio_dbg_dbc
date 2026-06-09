#pragma once

#include <memory>
#include <vector>
#include <string>
#include "rapidjson/writer.h"


namespace OhmioControl
{

	//! Holds the traffic light event information (intersection, movement, etc)
	class TrafficLightEventData
	{
	public:
		TrafficLightEventData(int regionID = -1, int intersectionID = -1, const std::string& movement = "", int timeToCross = 10000);
		~TrafficLightEventData();

		//! Do we have a valid intersection data?
		bool IsValid() const;

		//!@{
		//! Is this message for the right intersection?
		bool IsRightIntersection(int regionID, int intersectionID, const std::string& movement) const;
		//!@}


		//! How long (in 0.1 seconds unit) to cross the intersection
		int GetTimeToCross();

		//! Serialize to JSON sting
		void ToJson(std::string& asJson);

		//! Read from JSON string
		bool FromJson(const std::string& asJson);

		//! Get the region ID for diagnostics
		int GetRegionId() const;

		//! Get the Intersection ID for diagnostics
		int GetIntersectionId() const;

		//! Get the movement name for diagnostics
		std::string GetMovementName() const;

		//! Is the movement name meaning no traffic light?
		bool IsIdleMovement(const std::string& movement) const;

		//! Is the event JSON string a stop sign - indicating we should go after we stopped
		bool IsGoAfterStop(const std::string& eventJson) const;

	private:
		//! Write as JSON
		void WriteToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer);

	private:
		int m_regionId;			//!< the region (in the world) of the intersection
		int m_intersectionId;	//!< which intersection it is
		int m_timeToCross;		//!< time mSec required to cross the intersection (0.1 sec units)
		std::string m_movementName;		//!< optional overriding the rules buy passing a red / green message
	};
}

