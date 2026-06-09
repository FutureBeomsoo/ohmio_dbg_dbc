#pragma once
#include "version.h"
#include <string>
#include <chrono>
#include <ctime>      


//! Utilities for timing  
namespace NTiming_NS
{
	//! class to log the timing of different steps.
	//! construct a timer anywhere you need it and it will log the processing time when it gets out of scope.  
	class Timer
	{
	public:
		Timer(std::string name);
		~Timer();
		double GetTimePeriodMilliSeconds() const;

		//! Fake the starting time of a timer to allow testing
		void SetStartTimrForTesting(std::chrono::high_resolution_clock::time_point fakeStart);

		//! Get current local time as a string
		//
		//! Time formatting is nusty. This is the main reason this function exists
		//! @param[in] format - fomat string. see http://www.cplusplus.com/reference/ctime/strftime/
		//! @return the time as string
		static std::string nowAsString(const char* format = "%c");

		//! Get local time as a string
		//
		//! Time formatting is nusty. This is the main reason this function exists
		//! @param[in] time - the time stamp to connvert
		//! @param[in] format - fomat string. see http://www.cplusplus.com/reference/ctime/strftime/
		//! @return the time as string
		static std::string TimeAsString(const std::chrono::system_clock::time_point& time, const char* format = "%c");


		//! GetCurrent time in full minutes
		static int GetMinutesNow();


	private:
		std::string m_myName;
		std::chrono::high_resolution_clock::time_point m_startTime;
	};
}
