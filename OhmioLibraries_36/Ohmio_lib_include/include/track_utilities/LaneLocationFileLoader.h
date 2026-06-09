#pragma once

#include "WayPointDefinitions.h"
#include <vector>
#include <string>


//! Load a track file 
class LaneLocationFileLoader
{
public:
	LaneLocationFileLoader();
	~LaneLocationFileLoader();

	//! Load a the events
	//
	//! @return - Success or error code  
	FileLoadErrorCodes LoadLaneLocations(std::string fullPath);
	FileLoadErrorCodes LoadLaneLocations(std::istringstream &iss);

	//! save a the events
	//
	//! @return - Success or error code  
	FileLoadErrorCodes SaveLaneLocations(std::string fullPath);

	//! Get the track as a vector of locations
	void GetLocations(std::vector<OHMIO_LANE_INFO_POINT_INFO_t>& track);

	//! Set the track as a vector of locations
	void SetLocations(std::vector<OHMIO_LANE_INFO_POINT_INFO_t>& track);


	//! Get the MD5 checksum for the location only
	uint64_t GetMD5Track();

	//! Get the full MD5 checksum
	uint64_t GetMD5Full();
	void SetMD5Track(uint64_t md5);


	uint64_t GetTrackId();
	void SetTrackId(uint64_t id);

	uint64_t GetVehicleId();
	void SetVehicleId(uint64_t id);


	std::string GetFullName(std::string track);


private:
	FileLoadErrorCodes VerifyMd5();
	bool ReadPointFromString(const std::string& line, OHMIO_LANE_INFO_POINT_INFO_t& point);
	bool ReadHeader(std::istream& TrackFile);
	void ParseLine(const std::string& line, std::vector<int32_t>& parsedStringOutput, std::string& extraData);
	void WriteHeader(std::ofstream& TrackFile);
	void WriteLocation(std::ofstream& TrackFile, int locationIdx);
	uint64_t CalculateMd5();


private:
	std::vector<OHMIO_LANE_INFO_POINT_INFO_t> m_locations;	//!< the events
	OHMIO_LANE_INFO_HEADER_INFO_t m_header;		//!< the header (checksum, etc)

};