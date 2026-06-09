#pragma once
#include "version.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <deque>
#include <mutex>
#include <thread>
#include  <condition_variable>

#define LogAlways  NLogging_NS::Logging().Get(NLogging_NS::LogLevels::Minimum)
#define LogVerbose if ( NLogging_NS::LogLevels::Verbose == NLogging_NS::LoggingToFile::GetLevel())  NLogging_NS::Logging().Get(NLogging_NS::LogLevels::Verbose)
#define LogError  LogAlways << "ERROR: "
#define LogWarning  LogAlways << "WARNING: "

//! logging 
namespace NLogging_NS {

//! the logging levels
enum class LogLevels {
	Minimum, //!< Log just minimum information
	Verbose, //!< Log extended information
};

//! Log the messages into a file
//
//! Without keeping the file opened constantly and without (slow) file operations in the logging thread.  
//! Construct LoggingToFile once in the program. It will handle logging to file.
//! To log use one of the macroes above (LogError, LogWarning, LogAlways, LogVerbose)
//! The macro will do nothing if the logging level is not on and take virtualy no time.
//! Otherwise it will push the corect message to a buffer.
//! A separate file writing thread will periodicaly write the messages to the file.
class LoggingToFile {

public:
	//! Constructor
	//
	//! Create a file logger.
	//! @param[in] fileName - the file to log into to
	//! @param[in] level - logging level. Minimum to log just warnings, errors and always. Verbose
	//!	 to log everything
	//! @param[in] clearLogFile - if set to true delete the existing file before creating a new one.
	//!	 The default is to appand to the old file. 	
	LoggingToFile(std::string fileName, LogLevels level, bool clearLogFile =
			false);
	~LoggingToFile();

	//! Force the logging to write all existing message to file
	//
	//! Use this in rear cases when you are afraid the program will crash before the message
	//! will be wrtitten to file in the normal way.
	static void WriteAllMessagesToFile();

	//! Log a message. Do not call directly. Called by Logging to push a message to the internal buffer
	void LogMessage(std::string text);

	//! What level of logging is on now.
	static LogLevels GetLevel();

	static void LogException(std::string where,
			std::exception& e);

private:
	void SetLevel(LogLevels level);
	std::string LogLevelToString(LogLevels level);
	void WritingThread();
	void WriteMessages();
	int GetBufferSize();
	std::pair<uint64_t, std::string> GetOldestMessage();
	void WaitForMessages();

private:
	std::mutex m_mutex;			//!< for locking access to the actual buffer  
	std::condition_variable m_newMessage;		//!< new message event
	std::deque<std::pair<uint64_t, std::string>> m_messageBuffer;//!< buffer of messages to write to file
	static LogLevels m_reportingLevel;			//!< what level are we logging
	std::string m_logFileName;					//!< the log file				
	std::thread m_writingThread;			//!< a thread that writes to file
	bool m_done;				//!< flag telling us it is time to finish		
	uint64_t m_currentMessageId;				//!< message count
};

//! logging class
//
//! a very simple Logging based on http://www.drdobbs.com/cpp/logging-in-c/cpp/logging-in-c/201804215?pgno=2
//! but only the core functionality kept. \n 
//! usage:
//! call StartFileLogging with LogLevels::Minimum or LogLevels::Verbose once. This sets up the logging level. 
//! In Verbose everything is logged, in Minimum only LogAlway is logged LogVerbose is ignored.
//! \n Use: LogAlways << "loading simulation " << xmlFile; to logs always 
//! \n Use: LogVerbose << "loading simulation " << xmlFile; to logs only if in verbose mode 
//! \n Do not access any of these functions diretly. The logging macros will do all the work for you. 
class Logging {
	// make it non copyable
private:
	Logging(const Logging&);
	Logging& operator =(const Logging&);

public:
	Logging();
	virtual ~Logging();

	std::ostringstream & Get(LogLevels level);

private:
	static LoggingToFile* s_Stream;
	std::ostringstream m_logStream;
	friend class LoggingToFile;
};

}
