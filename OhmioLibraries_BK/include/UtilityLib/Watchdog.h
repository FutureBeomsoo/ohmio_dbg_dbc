#pragma once

#include "version.h"

#include "stdafx.h"
#include <mutex>
#include <thread>
#include <map>
#include <vector>
#include "RunInThreadForever.h"

namespace Threading
{
	//! Information about a thread that is being watched
	class WatchedThread
	{
	public:
		std::string name;		//!< name for diagnostics
		int reportPeriod;		//!< period of this thread (mSEc). It should call Report at least once in this period 
		std::chrono::high_resolution_clock::time_point m_lastTime; //!< last reported time
		bool good;				//!< is the thread running OK
		int timeFromLast;		//!< time (mSEc) since last reported
	};

	//! Monitor threads to see if any of them is lost
	class Watchdog : public RunInThreadForever
	{
	public:
		Watchdog();

		~Watchdog();

		//! Register a thread to the watchdog
		//
		//! @param[in] threadId - the thread
		//! @param[in] name - the thread name
		//! @param[in] period - expected period (mSec), if 0 use the watchdog default, if < 0 no reporting required
		void Register(std::thread::id threadId, std::string name, int period);

		//! this thread no longer need to be watched
		void UnRegister(std::thread::id threadId);

		//! A thread calls this to Report that it is active
		void Report(std::thread::id threadId);

		//! @return true if all registered threads have reported in the last period
		bool IsOk();
	
		//! Which threads are we watching
		//
		//! @param[out] threads - all the registered threads
		void GetAllThreads(std::vector<std::thread::id>& threads);

		//! Get information about a thread
		//
		//! @param[int] threadId - which thread?
		//! @param[out] info - the current state
		void GetThreadInfo(std::thread::id threadId, WatchedThread& info);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:

	private:
		std::map< std::thread::id, WatchedThread> m_threads;	//!< all the threads we are watching
		std::mutex m_mutexForMap;	//!< for locking the map 
		int m_minimumPeriod;		//!< period of the fastest monitored thread

	};

}

