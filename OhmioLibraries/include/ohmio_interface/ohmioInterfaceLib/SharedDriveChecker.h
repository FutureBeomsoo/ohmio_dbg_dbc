#pragma once
#include "CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include <chrono>

namespace Ohmio
{
	//! Check the access to the shared drive so that we can report errors
	//
	//! Need to run in a separate thread because when it fails it takes very long tome to response
	class SharedDriveChecker : public Threading::RunInThreadForever
	{
	public:
		SharedDriveChecker();
		~SharedDriveChecker();

		//! Is there an error in accessing the shared drive
		bool IsError();

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		bool m_accessError;			//!< is there an error?
		std::chrono::high_resolution_clock::time_point m_lastCheck;		//!< time of last check

	};
}
