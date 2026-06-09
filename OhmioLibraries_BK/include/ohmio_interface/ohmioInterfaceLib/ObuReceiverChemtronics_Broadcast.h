#pragma once
#include "V2Xhandler.h"

namespace Ohmio
{
	//! A receiver For the chemtronics OBU unit based on the wireshark protocol. Not the correct one
	//
	//! This is here just for debugging and testing. Use ObuReceiverChemtronics for proper communication
	class ObuReceiverChemtronics_Broadcast : public IV2Xhandler
	{
	public:
		ObuReceiverChemtronics_Broadcast(std::string hostAddress);
		~ObuReceiverChemtronics_Broadcast();



	protected:
		std::string GetDiagnosticName() override;
		void GetObuMessage() override;
		bool Open(std::string hostAddress) override;
		bool IsLive() override;

	private:
		int m_sock; //!< the socket

		std::chrono::high_resolution_clock::time_point m_lastTime; //!< to feed the messages at some rate
	};


}
