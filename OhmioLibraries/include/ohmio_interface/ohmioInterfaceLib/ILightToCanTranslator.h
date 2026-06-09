#pragma once
#include "CommonInclude.h"

namespace Ohmio
{
	//! translate between can messages and lights request / status. Need to use a derived class for the specific hardware
	//
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1361969159/Light+control.
	//! If you derive a new translator (because the hardware has changed) you need to add it to HardwareDetector
	class ILightToCanTranslator
	{
	public:
		//! Translate a CAN message to state of related driving lights.
		//
		//! @param[in] msg - the message to translate
		//! @param[out] lights - list of all the light in this message and their state 
		virtual void CanToDrivingLights(const CAN_MSG& msg, std::vector<std::pair<DrivingLightItem, bool>>& lights) const = 0;

		//! translate a set of driving light states to can message(s)
		//
		//! If any of the CAN messages contains other lights or items those 
		//! items should not change in the messages.
		//! @param[in] lights - list of all the light states we want to change. 
		//! @param[out] msg - the can message or multiple messages to send for this change.
		virtual void DrivingLightsToCan(std::vector<std::pair<DrivingLightItem, bool>>& lights,
			std::vector<std::shared_ptr<CAN_MSG>>& msg) const = 0;

		//! Which messages are related to lights?
		//
		//! This is used in order to find out what hardware we have. If we get a message that 
		//! belongs to this translator we have this hardware.
		//! Should be called by the hardware detector.
		//! Also used by the light status to detect what is on.
		//! @param[out] lightMessages - list of all the messages IDS that indicate light status
		virtual void GetAllMessageIds(std::set<uint64_t>& lightMessages) const = 0;

		//! Do we need to turn off day lights when indicating?
		//
		//! If the lights are physically close to the indicators we do unless
		//! the unit is automatically doing it for us.
		virtual bool IsNeedToTurnRunningLightOffWhenIndicating() const = 0;


		//! Is the vehicle symmetric for forward and reverse drive?
		virtual bool IsBidirectional() const = 0;
	};


	//! Mock translator that does nothing just to avoid crashing if we have to create a translator before we know which one
	class MockLightTranslator : public ILightToCanTranslator
	{
		virtual void CanToDrivingLights(const CAN_MSG& msg, std::vector<std::pair<DrivingLightItem, bool>>& lights) const override
		{
			msg; // ugnored
			lights.clear();
		}

		virtual void DrivingLightsToCan(std::vector<std::pair<DrivingLightItem, bool>>& lights,
			std::vector<std::shared_ptr<CAN_MSG>>& msg) const override
		{
			lights; // ignored
			msg.clear();
		}


		virtual void GetAllMessageIds(std::set<uint64_t>& lightMessages) const override
		{
			lightMessages.clear();
		}

		virtual bool IsNeedToTurnRunningLightOffWhenIndicating() const override
		{
			return false;
		}


		virtual bool IsBidirectional() const override
		{
			return true;
		}

	};

}

