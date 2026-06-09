#pragma once
#include "ohmioModelLib/commonInclude.h"
#include <mutex>
#include <condition_variable>

namespace OhmioModel
{
	//! Wait for notification about light changes
	class ChangeMonitor : public OhmioModel::IChangeObserver
	{
	public:
		ChangeMonitor();
		~ChangeMonitor();

		// IChangeObserver interface
		void OnChanged(int param) override;

		//! Wait for a change in the lights
		//
		//! Sleeps until a change is notified or timeout passed
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);

	private:
		std::mutex m_mutex;						//!< for locking the new event
		std::condition_variable m_changeEvent;	//!< indicating that something had changed
		bool m_changed;							//!< set to true when a change happen

	};

}
