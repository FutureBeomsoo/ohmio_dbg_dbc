#pragma once
#include "V2Xhandler.h"
#include <fstream>
#include <chrono>


namespace Ohmio
{
	//! File based receiver for testing
	class FileObuReceiver :	public IV2Xhandler
	{
	public:
		FileObuReceiver(std::string hostAddress);
		~FileObuReceiver();


	protected:
		std::string GetDiagnosticName() override;
		void GetObuMessage() override;
		bool Open(std::string hostAddress) override;
		bool IsLive() override;

	private:
		std::ifstream m_theFile;		//!< the file source
		std::string m_fileName;			//!< source file name
		std::chrono::high_resolution_clock::time_point m_lastTime; //!< to feed the messages at some rate

	};

}
