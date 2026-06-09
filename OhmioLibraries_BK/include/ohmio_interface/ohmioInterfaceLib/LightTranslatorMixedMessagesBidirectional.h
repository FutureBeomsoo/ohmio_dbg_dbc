#pragma once
#include "LightTranslatorMixedMessages.h"
#include "IMessageObserver.h"
#include <set>

namespace Ohmio
{
	//! Light translator for the Ohmio vehicle with multiple lights (and others) in the same message
	class LightTranslatorMixedMessagesBidirectional : public LightTranslatorMixedMessages
	{
	public:
		LightTranslatorMixedMessagesBidirectional(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~LightTranslatorMixedMessagesBidirectional();


		// Inherited via ILightToCanTranslator
		virtual bool IsBidirectional() const override;


		// Inherited via IMessageObserver
		virtual void MessageCallback(const CAN_MSG & message) override;



	protected:
		// LightTranslatorMixedMessages interface
		virtual void GetMyMessageIds(std::set<uint64_t>& lightMessages) const override;

		virtual LightItem_firstCars GetMainLightIdForDrivingLight(DrivingLightItem light) const override;

		virtual OvalLightItem_firstCars GetOvalLightIdForDrivingLight(DrivingLightItem light) const override;

		virtual void SetRearLightsUsed(const std::vector<bool>& rearWasSet, std::map<OvalLightItem_firstCars, OvalLightState>& requiredLights) const override;

		virtual void TranslateLightsFromFirstVehiclaHw(std::vector<std::pair<DrivingLightItem, bool>>& lights,
			const std::vector<std::pair<LightItem_firstCars, uint8_t>>& lightsOldHardwar) const;
		virtual void TranslateLightsFromOval(std::vector<std::pair<DrivingLightItem, bool>>& lights,
			const std::vector<std::pair<OvalLightItem_firstCars, OvalLightState>>& ovalLights) const;


	private:
		//! which way are we going?
		void RecieveTrackMessage(const Ohmio::CAN_MSG& message);

	private:
		bool m_forward;		//!< Are we driving forward (true) or reverse (false)
	};


}

