#pragma once
#include "InterfaceManager.h"
#include "ohmioInterfaceLib/SafetyRegulator.h"
#include "ohmioInterfaceLib/VersionsInfo.h"

namespace OhmioInterfacePy
{
	//! version of a device on the CAN bus
	class UnitVersion
	{
	public:
		int id;	//!< device id
		Ohmio::UnitVersion version; //!< device version
	};

	//! State of an external device
	class DeviceState
	{
	public:
		uint64_t id;	//!< device id
		bool state; //!< device status active or not
	};

	//! Interface to the Ohmio::SafetyRegulator for diagnostics
	//
	//! this is just an interface. Everything is passed on to the Ohmio 
	//! library do the work
	class SaftryRegulatorInterface
	{

	public:
		SaftryRegulatorInterface(InterfaceManager& manager);
		~SaftryRegulatorInterface();

		//! Is it safe to drive?
		//
		//! Mainly for diagnostics
		//! @param[out] operatingDevice - ID of device that prevent driving. 0 if no such device.
		//! @return Ok or the reason for disabling driving
		Ohmio::SafetyReason CanDrive(uint64_t& operatingDevice) const;

		//! Is it safe to operate devices such as foot step?
		//
		//! Mainly for diagnostics
		//! @return Ok or the reason for disabling
		Ohmio::SafetyReason CanOperateDevices() const;

		//! Get the status of all the devices.
		//
		//! For diagnostics
		//! @param[out] devices - the list of all the devices it monitors 
		//! and their state. The map key is the device status message,
		//! the value is true if the device is active (not safe to drive)
		void GetDeviceStatus(std::vector<DeviceState>& devices) const;

		//! For work on the vehicle we may need to drive with door opened
		void AllowDrivingWithOpenedDoor(bool allow);

		///@{
		//! Get the actual or expected versions of all the devices on the CAN buses
		//
		//! For diagnostics
		//! @param[out] versions - the set of versions
		void GetExpectedVersions(std::vector<UnitVersion>& versions) const;
		void GetActualVersions(std::vector<UnitVersion>& versions) const;
		///@}

		///@{
		//! Set the versions we need to have to be safe.
		//
		//! @param[in] csvFile - full path to a file containing the versions
		//! @param[in] versions - the versions
		void SetExpectedVersionsFromFile(std::string csvFile);
		void SetExpectedVersions(std::vector<UnitVersion>& versions);
		///@}


	private:
		void GetVersionAsVector(const Ohmio::VersionsInfo& versionData, std::vector<UnitVersion>& versions) const;

	private:
	};

}

