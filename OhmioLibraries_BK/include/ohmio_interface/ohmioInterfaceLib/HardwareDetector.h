#pragma once


#include "CommonInclude.h"
#include "IMessageObserver.h"

namespace Ohmio
{
	//! Listen to messages and creates the options according to the hardware. For now only lights
	class HardwareDetector : IMessageObserver
	{
	public:
		//! constructor
		//
		//! @param[in] receiver - how we get messages from the car
		//! @param[in] bidirectional - if true the vehicle does not have a special front direction
		HardwareDetector(std::shared_ptr<MessageReceiver> receiver, bool bidirectional);


		~HardwareDetector();

		//! did we get the needed message to decide?
		bool IsLightReady();

		//! Get the right translator
		std::shared_ptr<ILightToCanTranslator> GetLightTranslator();


		// IMessageObserver interface
		void MessageCallback(const CAN_MSG& message) override;

	private:

		//! Create all the possible translators to see which ones work
		void CreateTranslators(std::shared_ptr<MessageReceiver> receiver);

		//! Create the mapping from messages to translator
		void CreateMessageMap();

	private:
		std::shared_ptr<ILightToCanTranslator> m_lightTranslator; //!< the translator
		bool m_lightDetected;			//!< did we get the needed message to decide?
		bool m_bidirectionalVehicle;	//!< Is the car forward / back symmetric?
		//! All the possible translators
		std::vector<std::shared_ptr<Ohmio::ILightToCanTranslator>> m_candiadtes;
		std::map<uint64_t, size_t> m_messageMap; //!< link messages to translators
	};

}

