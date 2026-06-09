#pragma once

#include "WayPointDefinitions.h"
#include <vector>
#include <string>


//! Default location of track files 
const std::string TrackFilesSharedFolder = "/media/ohmio-share/";
const std::string fullTrackExtension = ".track";

//! Load a track file 
class TrackFileLoader
{
public:
	TrackFileLoader();
	~TrackFileLoader();

	//! Convert the track number and forward / reverse to track file name
	//
	//! @param[in] trackNumber - false for track 1, true for track 2  
	//! @param[in] reverse - false for forward, true for reverse  
	//! @return - the track file name without folder or extension name 
	//! (1F / 1R / 2F / 2R)  
	static std::string GetTrackFileName(bool trackNumber, bool reverse);


	//! Load a track
	//
	//! @return - Success or error code  
	FileLoadErrorCodes LoadTrack(std::string fullPath);
	FileLoadErrorCodes LoadTrack(std::istringstream &iss);


	//! Calculate all checksums to make the track valid for saving
	void RecalculateHeader();

	//! Save a track to file
	//
	//! @param[in] fullPath - file name to save  
	//! @return - Success or error code  
	FileLoadErrorCodes SaveTrack(std::string fullPath);


	//! Get the track as a vector of WP
	void GetTrack(std::vector<OHMIO_WAY_POINT_DRIVE_t>& track);

	//! Set the track as a vector of WP
	void SetTrack(std::vector<OHMIO_WAY_POINT_DRIVE_t>& track);


	//! Get all the way point indexes where a requested flag changes from 1 to 0.
	void GetActionPoints(wayPointeventFlag flag, std::vector<int>& changes);

	uint32_t GetTrackFlags(int WP);

	//! Get the MD5 checksum for the location only
	uint64_t GetMD5Loc();

	//! Get the full MD5 checksum
	uint64_t GetMD5Full();

	uint64_t GetTrackId();
	std::string GetTrackName();
	uint8_t GetTrackType();

	uint32_t GetTrackLength();

	void SetTrackId(uint64_t id);
	void SetTrackName(std::string name);
	void SetTrackType(uint8_t type);

private:
	FileLoadErrorCodes VerifyMd5();
	bool ReadWayPointsFromString(const std::string& line, OHMIO_WAY_POINT_DRIVE_t& point);
	bool ReadHeader(std::istream& TrackFile);
	void ParseLine(const std::string& line, std::vector<double>& parsedStringOutput);
	void WriteHeader(std::ofstream& TrackFile);
	void WriteWayPoint(std::ofstream& TrackFile, int wpIndex);



private:
	std::vector<OHMIO_WAY_POINT_DRIVE_t> m_FullTrack;	//!< the track
	OHMIO_PATH_INFO_t m_header;		//!< the header (checksum, etc)

};