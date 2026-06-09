#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"

namespace OhmioModel
{
	//! Monitor the status of the traffic light system
	class TrafficLightStatus : public Ohmio::IMessageObserver
	{
	public:
		TrafficLightStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~TrafficLightStatus();

		// IMessageObserver interface
		void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//! What are we seeing now
		//
		//! The int value corresponds to TRAFFIC_LIGHT_STATUS
		int GetCurrentState();

		//! How long (seconds) before the light changes
		double GetTimeToChange();

		//! which traffic light are we waiting for
		int GetTrafficLightId();

	private:
		int m_state;			//!< current state
		double m_timeToRed;		//!< how long before light change to red
		int m_id;				//!< traffic light ID
	};

}
