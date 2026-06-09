#pragma once

#include "WayPointDefinitions.h"
#include <vector>
#include <string>

//! an event with additional JSON data
class ExtendedEvent
{
public: 
	OHMIO_EVENT_INFO_t eventData;	//!< the event standrad data
	std::string extraInfo;			//!< the event as JSON string
};

//! Load a track file 
class EventFileLoader
{
public:
	EventFileLoader();
	~EventFileLoader();

	//! Load a the events
	//
	//! @return - Success or error code  
	FileLoadErrorCodes LoadTrack(std::string fullPath);
	FileLoadErrorCodes loadEventsFile(std::istringstream &iss);

	//! save a the events
	//
	//! @return - Success or error code  
	FileLoadErrorCodes SaveEvents(std::string fullPath);

	//! Calculate all checksums to make the track valid for saving
	void RecalculateHeader();


	//! Get all the events 
	void GetEvents(std::vector<ExtendedEvent>& events);

	//! Get all the events 
	void SetEvents(std::vector<ExtendedEvent>& events);

	//@{
	//! Get all the events for a requested type
	void GetEvents(std::vector<ExtendedEvent>& events, wayPointeventFlag eventType);
	void GetEvents(std::vector<ExtendedEvent>& events, wayPointeventFlag2 eventType);
	void GetEvents(std::vector<ExtendedEvent>& events, uint32_t eventType);
	//@}

	//! How many events do we have
	int GetNumEvents();

	//! Get the MD5 checksum for the location only
	uint64_t GetMD5Track();

	//! Get the full MD5 checksum
	uint64_t GetMD5Full();
	void SetMD5Track(uint64_t md5);


	uint64_t GetTrackId();
	void SetTrackId(uint64_t id);

	//! Convert bit index to flag enum
	static uint32_t FlagFromBit(uint32_t bitIdx);

	//! Convert bit index to flag enum
	static uint32_t BitFromEvent(uint32_t flag);

	//! Get the event file name from the track file
	static std::string GetFullName(std::string track);

private:
	FileLoadErrorCodes VerifyMd5();
	bool ReadEvenFromString(const std::string& line, ExtendedEvent& point);
	bool ReadHeader(std::istream& TrackFile);
	void ParseLine(const std::string& line, std::vector<uint32_t>& parsedStringOutput, std::string& extraData);
	void WriteHeader(std::ofstream& TrackFile);
	void WriteEvent(std::ofstream& TrackFile, int eventIdx);
	uint64_t CalculateMd5();


private:
	std::vector<ExtendedEvent> m_events;	//!< the events
	OHMIO_EVENT_HEADER_INFO_t m_header;		//!< the header (checksum, etc)

};