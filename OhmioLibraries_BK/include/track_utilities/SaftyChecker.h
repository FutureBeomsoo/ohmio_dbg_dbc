#pragma once
#include <string>
#include <map>
#include <vector>
#include "EventFileLoader.h"
#include "TrackFileLoader.h"
#include "DangerFileLoader.h"


//! How safe is a track
enum class TrackSafety
{
	Safe,		//!< no safety issues
	Warning,	//!< track containers features that may be unsafe
	unsafe,		//!< track is unsafe

	// always add above this
	last		
};


//! Check the safety of a track. 
//! Checks the triplet of track files and warn 
//! about potentially unsafe features 
class SaftyChecker
{
public:
	SaftyChecker();
	~SaftyChecker();


	//! Check if a track is safe.
	//
	//!@param[in] name - full path to the track file
	//!@param[out] issues - list of all the safety issues, classified by severity
	//!@return true if track has no issues.
	bool Check(std::string name, std::multimap<TrackSafety, std::string>& issues);

	//! Check if a track is safe.
	//
	//!@param[in] track - the track as a vector of WP
	//!@param[in] events - the events
	//!@param[in] dangers - the danger zones
	//!@param[out] issues - list of all the safety issues, classified by severity
	//!@return true if track has no issues.
	bool Check(std::vector<OHMIO_WAY_POINT_DRIVE_t>& track,
		std::vector<ExtendedEvent>& events, std::vector<OHMIO_DANGER_POINT_INFO_t>& dangers,
		std::multimap<TrackSafety, std::string>& issues);


private:
	bool Ceck(std::multimap<TrackSafety, std::string> &issues);
	void LoadTrackAndEvents(std::string name);
	void CheckForMissingEvents(std::multimap<TrackSafety, std::string>& issues);
	void CheckForMissingDangers(std::multimap<TrackSafety, std::string>& issues);
	void CheckForUnsfaeEvents(std::multimap<TrackSafety, std::string>& issues);
	void CheckForOverlappingEvents(std::multimap<TrackSafety, std::string>& issues);
	void CheckGpsOff(std::multimap<TrackSafety, std::string> &issues);
	void CheckDangerZones(std::multimap<TrackSafety, std::string>& issues);
	void CheckDangerCrossingTrack(const OHMIO_EVENT_INFO_t& eventData, std::multimap<TrackSafety, std::string>& issues);
	bool IsEventFlagOnAfterEnd(const ExtendedEvent& e);

	// for debugging dump results to file
	void DumpDzCrossingToFiles(const OHMIO_EVENT_INFO_t &eventData, std::vector<OHMIO_DANGER_POINT_INFO_t> &dangerZone, std::vector<OHMIO_WAY_POINT_DRIVE_t> &track);

	void CheckEventRange(std::multimap<TrackSafety, std::string> & issues);

	int FindTrackWpForDZ(const OHMIO_EVENT_INFO_t& eventData);



private:
	TrackFileLoader m_track;		//!< the track
	DangerFileLoader m_dangers;		//!< dander zones
	EventFileLoader m_events;		//!< track events
};