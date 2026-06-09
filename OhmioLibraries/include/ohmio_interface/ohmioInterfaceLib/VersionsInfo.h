#pragma once

#include "CommonInclude.h"

namespace Ohmio
{
	//! Holds a software version definition
	class Version
	{
	public:
		Version(uint8_t m = 0, uint8_t n = 0, uint32_t b = 0) : majorNumber(m), minorNumber(n), buildNumber(b) {};
		~Version() {};

		uint8_t majorNumber;	
		uint8_t minorNumber;
		uint32_t buildNumber;
	};

	//! operator ==
	inline bool operator==(const Version& lhs, const Version& rhs)
	{
		return (lhs.majorNumber == rhs.majorNumber)
			&& (lhs.minorNumber == rhs.minorNumber)
			&& (lhs.buildNumber == rhs.buildNumber);
	}

	//! The versions for a Unit on the bus. Versions of all the software on the device 
	class UnitVersion
	{
	public:
		UnitVersion() : mainVersion(), canVersion(), bootVersion(), canPVersion() ,requestCount(0) {};
		~UnitVersion() {};

		Version mainVersion;		//!< version of the main software on the device
		Version canVersion;			//!< version of CAN protocol (DBC file) for the main CAN
		Version bootVersion;		//!< version of the boot loader (if existing) on the device
		Version canPVersion;		//!< version of CAN protocol (DBC file) for the peripheral CAN
		int requestCount;			//!< counter for how many times we asked for version and didn't get a reply
	};

	//! operator ==
	inline bool operator==(const UnitVersion& lhs, const UnitVersion& rhs)
	{
		return (lhs.mainVersion == rhs.mainVersion)
			&& (lhs.canVersion == rhs.canVersion)
			&& (lhs.canPVersion == rhs.canPVersion)
			&& (lhs.bootVersion == rhs.bootVersion);
	}

	//! A container to hold the versions of all the different units.
	//
	//! You can load the versions from a CSV file or from CAN messages
	class VersionsInfo
	{
	public:
		VersionsInfo();
		~VersionsInfo();


		//! remove all existing versions
		void Clear();

		//! Get the versions of all the devices
		//
		//! @param[out] versions - the versions
		//! the key is the device CAN id, the value is the version.
		void GetAllVersions(std::map<int, UnitVersion>& versions) const;

		//! Get all devices that have versions
		void GetAllIds(std::vector<int>& Ids);

		//! Do we know the version of a device?
		bool IsDeviceExist(int deviceId);

		//! Get all the versions of a device
		//
		//! Gets the version of a device. 
		//! @param[in] deviceId - the device to set
		//! @param[out] version - the device version
		void GetVersion(int deviceId, UnitVersion& version);

		///@{
		//! Set all the versions or a particular version of a device
		//
		//! Sets the version of a device. 
		//! If the device is not already in the list it will be
		//! created. Missing versions will be 0.0.0
		//! @param[in] deviceId - the device to set
		//! @param[in] version - the device version
		void SetVersion(int deviceId, const UnitVersion& version);
		void SetMainVersion(int deviceId, const Version& version);
		void SetCanVersion(int deviceId, const Version& version);
		void SetCanPVersion(int deviceId, const Version& version);
		void SetBootVersion(int deviceId, const Version& version);
		///@}

		///@{
		//! Read / write the versions from / to a CVS file
		//! The first line in the file is titles. Columns are:
		//! device ID,major,minor,build,can major,can minor,can build,boot major,
		//! boot minor,boot build,can P major,can P minor,can P build,
		//! device name,comments
		//
		//! @param[in] csvFile - coma separated file 
		void ReadFromCsv(const std::string& csvFile);
		void WriteToCsv(const std::string& csvFile);
		///@}

		//! Copy from another. Yes I can make a copy constructor but this is simpler 
		void CopyFrom(const VersionsInfo& other);

		//! Are versions the same. Yes I override == but this is simpler 
		bool IsEqual(const VersionsInfo& other) const;

		//! we are asking a device for its version
		void IncrementPollingCount(int deviceId);

	private:
		//! Set a device version from a CSV data line
		void SetVersionFromCsv(const std::vector<int>& numbers);

		//! Read the version of a device from CSV data
		void CreateDeviceVersionFromCsv(Version& version, const std::vector<int>& numbers, int startIdx);

		//! Get the versions as number array
		void VersionToArray(const UnitVersion& version, std::vector<int>& asNumbers);

		//! Push a particular version to array
		void PushVersionToArray(const Version& version, std::vector<int>& asNumbers);


	private:
		//! Versions of all the devices. 
		//! the key is the device CAN id, the value is the version.
		std::map<int, UnitVersion> m_AllVersions;

	};


}

