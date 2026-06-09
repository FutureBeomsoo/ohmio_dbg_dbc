// profiling tool. dump profiles to log. 
// to use it construct the profiler once in the program. it will dump the 
//  results when NTiming_NS::Profiling get out of scope. 
// create a ProfilePeriod object where you want to time and it will time and 
//  automatically be added to the profiles when it gets out of scope.
// A simple way to create th etimer is to use the macro PROFILE_THIS that creates
//  a timer from the function name and file name
// make sure the logger is still running before the profiler gets out of scope 
//  (by calling NLogging_NS::Logger::EndFileLogging()) otherwise the profiles will be 
//  written to a non existing output.
//
// example
// NTiming_NS::ProfilePeriod period("Main Period");
// for (int i = 0; i < 10; ++i)
// {
//		NTiming_NS::ProfilePeriod period("inlopp");
//		testVertexCreation(imgSizeForRaycasting); // NTiming_NS::ProfilePeriod period("testVertexCreation")
//		TestDepthProjection(model, depthImage);   // NTiming_NS::ProfilePeriod period("TestDepthProjection")
//		TestColourProjection(model, colourImage); // NTiming_NS::ProfilePeriod period("TestColourProjection")
// }
// 
// results in log:
// 13:7:39- 	Profile timers (mSec)
// 	13:7:39- 	Thread Number: 7444
// 	Main Period: Avg=1553.16 Min=1553.16 Max=1553.16 Count=1 Sum=1553.16 
// inlopp: Avg=153.515 Min=142.014 Max=168.017 Count=10 Sum=1535.15 
// TestColourProjection: Avg=10.8011 Min=10.001 Max=12.002 Count=10 Sum=108.011 
// TestDepthProjection: Avg=57.7058 Min=51.005 Max=62.006 Count=10 Sum=577.058 
// testVertexCreation: Avg=21.0021 Min=19.002 Max=34.003 Count=10 Sum=210.021 
// 					13:7:39- 	End profile timers

#pragma once
#include "version.h"


#include <string>
#include <map>
#include <stack>
#include <thread>
#include <atomic>

#include "MinMaxAvgTime.h"
#include "Timer.h"
#include "IProfiling.h"

namespace NTiming_NS
{
#define PROFILE_THIS ProfilePeriod timer(std::string(__func__) + "(" + std::string(__FILE__) + + ")");
	enum class outputTypes
	{
		logFile,
		csv,

		last
	};

	//*************************************************************************
	class ProfilePeriod
	{
	public:
		ProfilePeriod(std::string profileName);
		~ProfilePeriod();

		double GetTimePeriodMilliSeconds();

	private:
		void Start(const std::string& profileName);
		void Stop();
		ProfilePeriod(ProfilePeriod&); // disable Copy Constructor

	private:
		Timer m_TheTimer;
		std::string m_ProfileName;
	};


	//******************************************************************
	class Profile;
	typedef std::map<std::string, Profile*> SubProfiles;

	//******************************************************************
	class Profile
	{
	public:
		// pParent = NULL if no parent
		Profile(const std::string& profileName, Profile* pParent);
		~Profile();

		void AddTime(double time);

		MinMaxAvgTime * GetTimes();
		Profile * GetProfile(const std::string& profileName);
		Profile * AddProfile(const std::string& profileName);
		void DeleteProfiles();

		int GetNumSubProfiles();

		std::string GetProfileName();
		SubProfiles * GetSubProfiles();

		Profile * GetParent();
		Profile * FindParentProfile(const std::string& profileName);

		std::string Dump(int indent);
		std::string DumpAsCsv(int indent);
		std::string DumpAllProfiles(int indent, outputTypes format);

	private:
		int m_uniquId;
		Profile* m_pParent;
		std::string m_ProfileName;
		SubProfiles m_SubProfiles;
		MinMaxAvgTime m_MinMaxAvgTime;
	};



	//******************************************************************
	class ThreadProfile
	{
	public:

		ThreadProfile();


		void SetCurrentProfile(const std::string& profileName);
		bool UpdateCurrentProfile(const std::string& profileName, double time);

		Profile * CheckAllTimeouts(double& maxTime, double& elapsedTime);
		void HandleAnyTimeouts();

		bool  CheckForBadNesting();
		std::string  GetBadlyNestedProfileName();

		Profile * GetProfile();

		std::string Dump(int rootLevel, outputTypes format);
	private:
		ThreadProfile(ThreadProfile& threadProfile);		// don't copy entire profile tree.



		Profile m_ThreadProfile;	// Destruction causes entire tree to be deleted
		Profile* m_pCurrentProfile;

		bool m_BadNesting;
		std::string m_BadNestingName;
	};


	typedef std::map<std::thread::id, ThreadProfile*> ThreadProfiles;
	//*************************************************************************
	class Profiling : public IProfiling
	{
	public:
		Profiling(ThreadingModel threadingModel = ThreadingModel::SeperateTimersByThreads);
		virtual ~Profiling();

		// Get Singleton
		static Profiling * GetProfiling();

		// Functions called by profile objects: (e.g.VProfilePeriod)
		void StartProfile(const std::string& profileName);
		void EndProfile(const std::string& profileName, double time);

		int GetUniquId();

		// IProfiling interface
		virtual void Reset() override;
		virtual void DumpProfiles() override;
		virtual void GetProfilesCsv(std::string& logData) override;

	private:
		// enable outside agents to explore our data structures.
		// Be careful using this.
		ThreadProfile * GetThreadProfile(const std::thread::id& threadId);
		Profile* GetRootProfileForCurrentThread();

	private:
		void DeleteThreadProfiles();
		std::string Dump(outputTypes format);
		std::atomic_int m_lastProfileUiqueId;

	private:
		ThreadProfiles m_ThreadProfiles;
		static Profiling* m_pProfilingSingleton;
		ThreadingModel m_threadingModel;
	};
}

