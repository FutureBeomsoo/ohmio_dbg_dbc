/* *****************************************************************************
*  Interface class for profiler. Provides compatibility for CLR runtime.
*  ***************************************************************************** */
#pragma once
#include "version.h"

namespace NTiming_NS
{
	enum class ThreadingModel
	{
		SeperateTimersByThreads,
		SingleTimesTree,

		lastThreadingModel
	};

	class IProfiling
	{
	public:
		virtual void Reset() = 0;
		virtual void DumpProfiles() = 0;
		virtual void GetProfilesCsv(std::string& logData) = 0;
	};

	// Get the profiler, creating if necessary. Typically 
	// implemented with profiler.
	std::shared_ptr<IProfiling> GetProfiler(ThreadingModel singleOrMultiThreded);

}
