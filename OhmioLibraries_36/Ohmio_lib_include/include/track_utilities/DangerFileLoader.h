#pragma once

#include "WayPointDefinitions.h"
#include <vector>
#include <string>



//! Load a danger file 
class DangerFileLoader
{
public:
	DangerFileLoader();
	~DangerFileLoader();



	//! Load a track
	//
	//! @return - Success or error code  
	FileLoadErrorCodes LoadTrack(std::string fullPath);
	FileLoadErrorCodes loadDangersFile(std::istringstream &iss);
	FileLoadErrorCodes SaveTrack(std::string fullPath);

	//! Calculate all checksums to make the track valid for saving
	void RecalculateHeader();

	//! Get all the danger points
	void GetDangers(std::vector<OHMIO_DANGER_POINT_INFO_t>& dangers);
	void SetDangers(const std::vector<OHMIO_DANGER_POINT_INFO_t>& dangers);

	//! Get all the danger points for a zone
	void GetDangers(std::vector<OHMIO_DANGER_POINT_INFO_t>& dangers, int zoneId);

	//! Get the MD5 checksum for the location only
	uint64_t GetMD5Track();
	void SetMD5Track(uint64_t md5);

	//! Get the full MD5 checksum
	uint64_t GetMD5Full();

	uint64_t GetTrackId();
	void SetTrackId(uint64_t id);

	//! how many danger zones are there
	int GetNumZones();

	//! how many danger points are there
	int GetNumPoints();


	//! Get the danger file name from the track file
	static std::string GetFullName(std::string track);


private:
	FileLoadErrorCodes VerifyMd5();
	bool ReadPointFromString(const std::string& line, OHMIO_DANGER_POINT_INFO_t& point);
	bool ReadHeader(std::istream& TrackFile);
	void ParseLine(const std::string& line, std::vector<double>& parsedStringOutput);
	void WriteHeader(std::ofstream& TrackFile);
	void WriteDangers(std::ofstream& TrackFile, int dangerIdx);

private:
	std::vector<OHMIO_DANGER_POINT_INFO_t> m_dangers;	//!< the events
	OHMIO_DANGER_HEADER_INFO_t m_header;		//!< the header (checksum, etc)

};