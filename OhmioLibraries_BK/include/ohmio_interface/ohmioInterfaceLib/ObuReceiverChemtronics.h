#pragma once
#include "V2Xhandler.h"

namespace Ohmio
{
	//! A receiver For the chemtronics OBU unit based on the proper standard
	class ObuReceiverChemtronics : public IV2Xhandler
	{
	public:
		ObuReceiverChemtronics(std::string hostAddress);
		~ObuReceiverChemtronics();



	protected:
		std::string GetDiagnosticName() override;
		void GetObuMessage() override;
		bool Open(std::string hostAddress) override;
		bool IsLive() override;
private:
		void GotIfEvent();
		void GotWaveCfg();


		void CloseSocket();

		//! Send configuration request message
		void SendConfigRequest();



	private:
		int m_sock; //!< the socket

		bool m_IsConfigured;		//!< have we got the response from configuration response? 
		std::chrono::high_resolution_clock::time_point m_lastRequestTime;	//!< last time we sent a message to OBU
		std::chrono::high_resolution_clock::time_point m_lastInputTime;		//!< last time we got a message from OBU
	};


}
