#pragma once
#include "ILightToCanTranslator.h"
#include "IMessageObserver.h"
#include <set>

namespace Ohmio
{
	//! Light translator for the Ohmio vehicle with multiple lights (and others) in the same message
	class LightTranslatorMixedMessages : public ILightToCanTranslator, public IMessageObserver
	{
	public:
		LightTranslatorMixedMessages(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~LightTranslatorMixedMessages();


		// Inherited via ILightToCanTranslator
		void GetAllMessageIds(std::set<uint64_t>& lightMessages) const override;
		void CanToDrivingLights(const CAN_MSG& msg, std::vector<std::pair<DrivingLightItem, bool>>& lights) const override;
		void DrivingLightsToCan(std::vector<std::pair<DrivingLightItem, bool>>& lights, std::vector<std::shared_ptr<CAN_MSG>>& msg) const override;
		bool IsNeedToTurnRunningLightOffWhenIndicating() const override;
		virtual bool IsBidirectional() const override;


		// Inherited via IMessageObserver
		virtual void MessageCallback(const CAN_MSG & message) override;



	protected:
		//! Get only the messages to register to
		virtual void GetMyMessageIds(std::set<uint64_t>& lightMessages) const;

		//! List of all the lights in the vehicle (for the first lift hardware with strange lights). 
		enum class LightItem_firstCars
		{
			// MainGroup 
			FrontLeftHeadLight,		//!< the front left head light
			FrontRightHeadLight,	//!< the front right head light
			FrontLogo,				//!< the front logo light
			RearLeftHeadLight,		//!< the rear left head light
			RearRightHeadLight,		//!< the rear right head light
			RearLogo,				//!< the rear logo light
			Internal,				//!< the internal light
			Flash,					//<! the flashing light
			Horn,					//<! the reverse beep sound

			// indicator and break
			FrontLeftIndicator,		//!< the front left Indicator light
			FrontRightIndicator,	//!< the front right Indicator light
			FrontBreak,				//!< the front break light
			RearLeftIndicator,		//!< the rear left Indicator light
			RearRightIndicator,		//!< the rear right Indicator light
			RearBreak,				//!< the rear break light
			// Always put more values above this
			CountLights //!< just for enumeration
		};

		//! List of all the lights in the vehicle (for the first lift hardware with strange lights). 
		enum class OvalLightItem_firstCars
		{
			// oval lights
			FrontLeftOval,			//!< the front left oval light 
			FrontRightOval,			//!< the front right oval light
			RearLeftOval,			//!< the rear left oval light 
			RearRightOval,			//!< the rear right oval light 

			// Always put more values above this
			CountLights //!< just for enumeration
		};


		//! which standard old light correspond to a driving light
		virtual LightItem_firstCars GetMainLightIdForDrivingLight(DrivingLightItem light) const;
		//! which oval lights correspond to a driving light
		virtual OvalLightItem_firstCars GetOvalLightIdForDrivingLight(DrivingLightItem light) const;

		//! Update rear lights that were changed
		virtual void SetRearLightsUsed(const std::vector<bool>& rearWasSet, std::map<OvalLightItem_firstCars, OvalLightState>& requiredLights) const;

		//@{
		//! translate state of light or oval light to the driving light status
		virtual void TranslateLightsFromFirstVehiclaHw(std::vector<std::pair<DrivingLightItem, bool>>& lights, 
			const std::vector<std::pair<LightItem_firstCars, uint8_t>>& lightsOldHardwar) const;
		virtual void TranslateLightsFromOval(std::vector<std::pair<DrivingLightItem, bool>>& lights, 
			const std::vector<std::pair<OvalLightItem_firstCars, OvalLightState>>& ovalLights) const;
		//@}


		private:

		//@{
		//! translate a specific message to light
		void CanToOvalLight(const CAN_MSG& msg, std::vector<std::pair<OvalLightItem_firstCars, OvalLightState>> & ovalLights) const;
		void CanToFrontMainLight(const CAN_MSG& msg, std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights) const;
		void CanToRearMainLight(const CAN_MSG& msg, std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights) const;
		void CanToSignalLight(const CAN_MSG& msg, std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights) const;
		//@}


		//! Translate a CAN message to state of lights.
		//
		//! @param[in] msg - the message to translate
		//! @param[out] lights - list of all the light states in this message and their brightens 
		//! @param[out] ovalLights - list of all the oval light states in this message and their RGB values
		void CanToLights(const CAN_MSG& msg, std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights,
			std::vector<std::pair< OvalLightItem_firstCars, OvalLightState>> &ovalLights) const;

		//! translate a set of light states to can message(s)
		//
		//! If any of the CAN messages contains other lights or items those 
		//! items should not change in the messages.
		//! @param[in] lights - list of all the light states we want to change. 
		//! @param[out] msg - the can message or multiple messages to send for this change.
		void LightsToCan(const std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights,
			std::vector<std::shared_ptr<CAN_MSG>>& msg) const;

		//! translate a set of light states to can message(s)
		//
		//! @param[in] ovalLights - list of all the oval light RGB values we want to change. 
		//! @param[out] msg - the can message or multiple messages to send for this change.
		void OvalLightsToCan(const std::vector<std::pair< OvalLightItem_firstCars, OvalLightState>>& ovalLights,
			std::vector<std::shared_ptr<CAN_MSG>>& msg) const;


		//! Create the message for a single oval light
		bool OvalLightToCan(OvalLightItem_firstCars lightId, const OvalLightState& rgb, CAN_MSG& msg) const;

		//! Create a multimap of message ids to indexes in lights
		void FindMessageIds(const std::vector<std::pair<LightItem_firstCars, uint8_t>>& lights,
			std::multimap<uint64_t, std::pair<LightItem_firstCars, int>>& messagesMap) const;

		//! Find all the message ids inmessagesMap 
		void FindUniqueIds(const std::multimap<uint64_t, std::pair<LightItem_firstCars, int>>& messagesMap, std::set<uint64_t>& messageIds) const;

		//! Get all the lights in lights that use a specific ID
		void GetLightsForMessage(const std::multimap<uint64_t, std::pair<LightItem_firstCars, int>>& messagesMap, uint64_t id,
			std::vector<std::pair<LightItem_firstCars, int>>& lightForMessage) const;

		//! What message ID is used by this light?
		uint64_t GetIdForLight(LightItem_firstCars lightId) const;

		//@{
		//! Combine the information from several lights into a single message
		void CreateLightMessage(const std::vector<std::pair<LightItem_firstCars, int>>& lights, CAN_MSG& theMessage) const;
		void CreateSignalsLightMessage(const std::vector<std::pair<LightItem_firstCars, int>>& lights, CAN_MSG& theMessage) const;
		void CreateFrontMainLightMessage(const std::vector<std::pair<LightItem_firstCars, int>>& lights, CAN_MSG& theMessage) const;
		void CreateRearMainLightMessage(const std::vector<std::pair<LightItem_firstCars, int>>& lights, CAN_MSG& theMessage) const;
		//@}


		//! Translate the desired light to the best approximation we can using the old vehicle hardware
		void TranslateLightsToOvalState(const std::vector<std::pair<DrivingLightItem, bool>>& lights,
			std::map< OvalLightItem_firstCars, OvalLightState>& requiredLights) const;

		//! Translate the desired light to the best approximation we can using the old vehicle hardware
		void TranslateLightsToFirstVehiclaHw(const std::vector<std::pair<DrivingLightItem, bool>>& lights, 
			std::vector<std::pair<LightItem_firstCars, uint8_t>>& lightsOldHardware) const;



		//! the headlamps should be on if either high or low beam are on
		void TurnOnHeadLampsIfNeeded(std::vector<std::pair<DrivingLightItem, bool>>& lights) const;

		void GetOvalLightVector(const std::map<OvalLightItem_firstCars, OvalLightState>& ovalLightsRequired, 
			std::vector<std::pair<OvalLightItem_firstCars, OvalLightState>>& ovalLights) const;



	private:
		std::map<uint64_t, Ohmio::CAN_MSG> m_currentStatus;		//!< the current information about the lights
		std::shared_ptr<MixedLightMessageHandler> m_helper;	//!< handle the front and rear main light messages 
	};


}

