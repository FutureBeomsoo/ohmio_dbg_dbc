#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"

namespace OhmioModel
{
	//! State of the lights on the vehicle
	//
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1361969159/Light+control
	class DrivingLightStatus : public Ohmio::IMessageObserver
	{
	public:
		//! Constructor
		//
		//! @param[in] receiver - where we get CAN messages from 
		//! @param[in] canTranslator - how to translate messages to lights 
		DrivingLightStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver,
			std::shared_ptr<Ohmio::ILightToCanTranslator> canTranslator);
		~DrivingLightStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);

		//! Is a driving light on or off?
		//
		//! @param[in] lightId - which light are we interested in
		//! @return true if on.
		bool IsDrivingLightOn(Ohmio::DrivingLightItem lightId);

	private:

		//! Tell all the observers that the status has changed 
		void NotifyChange();

		// Get the state of a single light channel as int
		int GetOvalLightChannelState(const Ohmio::OvalLightState& light, int channel) const;

	private:
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		std::map<Ohmio::DrivingLightItem, bool> m_drivingLightStatus;	//!< Current status of the oval lights
		std::shared_ptr<Ohmio::ILightToCanTranslator> m_translator;			//!< translates from CAN messages to state of lights
	};

}


