#pragma once
#include "ILightToCanTranslator.h"
#include "IMessageObserver.h"
#include <set>

namespace Ohmio
{
	//! Light translator for the Ohmio vehicle for the dedicated lights (1st korean full lights)
	class LightTranslatorKoeraV1 : public ILightToCanTranslator, public IMessageObserver
	{
	public:
		LightTranslatorKoeraV1(std::shared_ptr<Ohmio::MessageReceiver> receiver, bool bidirectional = false);
		~LightTranslatorKoeraV1();


		// Inherited via ILightToCanTranslator
		void GetAllMessageIds(std::set<uint64_t>& lightMessages) const override;
		void CanToDrivingLights(const CAN_MSG& msg, std::vector<std::pair<DrivingLightItem, bool>>& lights) const override;
		void DrivingLightsToCan(std::vector<std::pair<DrivingLightItem, bool>>& lights, std::vector<std::shared_ptr<CAN_MSG>>& msg) const override;
		bool IsNeedToTurnRunningLightOffWhenIndicating() const override;
		virtual bool IsBidirectional() const override;

		// Inherited via IMessageObserver
		virtual void MessageCallback(const CAN_MSG & message) override;

	private:

		//! Create the message for a light
		void ConvertLightToMessage(DrivingLightItem light, bool on, std::shared_ptr<CAN_MSG>& message) const;

		//! Is this item head lamp? If so it needs special handling
		bool IsHeadlamp(DrivingLightItem item) const;

		//! Head lamps need special treatment
		void AddHeadLampMessages(std::vector<std::pair<DrivingLightItem, bool>>& lights, std::vector<std::shared_ptr<CAN_MSG>>& msg) const;

		//! Translate rear lights message to reverse 'beep'
		bool IsHornOn(const CAN_MSG& msg) const;

		//! Translate front lights message to internal
		bool IsInternalOn(const CAN_MSG& msg) const;

		//! Get only the messages to register to
		void GetMyMessageIds(std::set<uint64_t>& lightMessages) const;

	private:
		bool m_headLampOn;		//!< head lamp is on according to status message
		bool m_beamOn;			//!< high is on according to status message
		bool m_bidirectional;	//!< if true the vehicle can drive in both directions (turn off reverse beepers)
		std::shared_ptr<MixedLightMessageHandler> m_helper;	//!< handle the internal and horn + speaker messages
	};


}

