#pragma once
#include "V2Xhandler.h"

namespace Ohmio
{
	//! A receiver For the chemtronics OBU unit based on the proper standard
	class ObuReceiverBlueTooth : public IV2Xhandler
	{
	public:
		ObuReceiverBlueTooth(std::string hostAddress);
		~ObuReceiverBlueTooth();



	protected:
		std::string GetDiagnosticName() override;
		void GetObuMessage() override;
		bool Open(std::string hostAddress) override;
		bool IsLive() override;



private:


		void CloseSocket();




	private:
		int m_sock; //!< the socket

		bool m_IsConfigured;		//!< have we got the response from configuration response? 
		std::chrono::high_resolution_clock::time_point m_lastInputTime;		//!< last time we got a message from OBU

	};


}
