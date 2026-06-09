#pragma once
#include "UtilityLib/JasonWriteHelper.h"
#include <vector>


namespace V2XComms
{
	//! Sate of the traffic light
	enum class trafficPhaseState
	{
		unavailable = 0,						//!< unknown
		dark = 1,								//!< not operating
		stop_Then_Proceed = 2,					//!< 4 ways stop style
		stop_And_Remain = 3,					//!< red
		pre_Movement = 4,						//!< prepare to start
		permissive_Movement_Allowed = 5,		//!< green but needs to give way
		protected_Movement_Allowed = 6,			//!< green 
		permissive_clearance = 7,				//!< yellow - stop if can
		protected_clearance = 8,				//!< yellow - stop if can
		caution_Conflicting_Traffic = 9,		//!< flashing yellow - may go but give way

		// always add before this
		last
	};

	//! name of movement
	enum class movementName
	{
		STR = 1,	//! Straight
		LEFT = 2,	//! LEFT
		PED = 3,	//! Pedestiran
		BYC = 4,	//! Bycicle
		RIGHT = 5,	//! Right
		BUS = 6,	//! Bus

		// always add before this
		last
	};

	//! define the traffic light status for a particular movement
	class SignalGroup
	{
	public:

		int groupID;						//!< ID of this  group in the traffic light
		trafficPhaseState currentState;		//!< state of the light
		int	endTimemSec;					//!< time remaining in this state before transition (mSec)
		movementName name;					//!< movement name

	};

	//! Defines the data of spat message
	class SpatMessageData
	{

	public:

		SpatMessageData();
		~SpatMessageData();

		//! Convert the data to JSON format
		//
		//! @param[in, out] an open writer to write to
		void ToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer) const;

		//! Read the data from JSON format
		//
		//! @param[in] the data as json string
		void FromJson(const std::string& json);


		//! Convert list of messages to JSON string
		static std::string ToJson(const std::vector<V2XComms::SpatMessageData>& spatData);

		//! Convert JSON string to list of messages t
		static void FromJson(const std::string& jsonString, std::vector<V2XComms::SpatMessageData>& spatData);

		//! Convert nmae string to enum
		static movementName MovementNameToEnum(std::string nameText);
		
		//! conver movement name to string for display
		static std::string MovementNameToText(movementName name);

	public:

		int regionId;				//! id of the region
		int intersectionId;			//! id of the intersection
		std::vector<SignalGroup> lights; //!< the state of all the lights


	private:
		void SignalsToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer) const;
		void lightToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer, const SignalGroup& light) const;

		//! conver state to string for display
		std::string StateToText(trafficPhaseState phase) const;


	};

}

