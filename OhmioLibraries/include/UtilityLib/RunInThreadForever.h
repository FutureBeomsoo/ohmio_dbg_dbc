#pragma once
#include "version.h"

#include <mutex>
#include <thread>
#include <memory>

namespace Threading
{
	class Watchdog;		// forward declaration is needed because these 2 classes are using each other 

	//! A common class for ruining something in a thread with an endless loop until told to finish
	//
	//! After creating the runner, call StartThread() on it. It wil start a thread and run the processing loop.
	//! Call Done() from the main thread to finish the procvessing thread. 
	//! The destructor will wait for the thread to finish. \n
	//! <B> WARNING: any class that derives from this MUST call Done() in it's destructor. Otherwise
	//! the processing thread will be called on the derived class after it was destroyed and before the base class is.
	//! Sorry but I can;t see a solution to this </B>
	class RunInThreadForever
	{
	public:
		RunInThreadForever();
		virtual ~RunInThreadForever();

		//! Start the thread
		void StartThread();


		//! Register this thread with watchdog 
		void RegisterWithWatchDog(std::shared_ptr<Watchdog> wd);


		//! Called by the manager to tell us to finish
		void Done();

		//! Pause or unpause the thread.
		//
		//! Keep the thread running but pause its operation. This is mainly for
		//! video processing to freeze the current frame so that we can look at 
		//! the process results without loosing the picture. 
		//! May be useful For other cases.
		//! Stop pushing or reading images to the buffer until told to unpause.
		//! File source will unpause by continuing from the stop position.
		//! Real camera will loose the data.
		//! Processing thread will stop reading
		//! @param[in] pause - true to pause, false to unpause
		void Pause(bool pause);

	protected:
		//! Do the job of a single run of the endless loop
		virtual void RunLoopOnce() = 0;

		//! Get the name of this thread for diagnostics
		virtual std::string GetDiagnosticName() = 0;

		//! What is the period that this thread should report to the watchdog? 
		virtual int GetWatchdogPeriod() = 0;

	private:
		//! Should we terminate?
		bool IsTimeToQuit();

		//! Tell the thread to finish
		void SignalToQuit();


		//! The thread loop that runs util Done() is called
		void ThreadLoop();



	protected:
		bool m_pausing;				//!< we are now paused so shouldn't process
		bool m_timeToQuit;			//!< Are we done?

	private:
		std::mutex m_mutex;			//!< for locking  the finished flag
		std::thread	m_theThread;	//!< the thread we run
		std::shared_ptr<Watchdog> m_watchdog; //!< the watchdog to report to
		std::thread::id m_threadId;	//!< the thread ID

	};
}

