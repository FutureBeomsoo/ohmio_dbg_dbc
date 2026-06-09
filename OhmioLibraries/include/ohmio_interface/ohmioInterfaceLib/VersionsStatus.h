#pragma once
#include "IMessageObserver.h"
#include "VersionsInfo.h"
#include <mutex>

namespace Ohmio
{
	//! Monitor the versions.
	class VersionsStatus : public IMessageObserver
	{
	public:
		VersionsStatus(std::shared_ptr<MessageReceiver> receiver);
		~VersionsStatus();

		// IMessageObserver interface
		void MessageCallback(const CAN_MSG& message) override;


		//! Get the  versions of all the devices on the CAN buses
		//
		//! @param[out] versions - the set of versions
		void GetVersions(VersionsInfo& versions);

		//! Get the  versions of all the devices on the CAN buses That have a valid version
		//
		//! Same as GetVersions but only gets the one that have a valid version
		//! @param[out] validVersions - the set of valid versions
		void GetValidVersions(VersionsInfo& validVersions);

		//! Get the  versions of all the devices on the CAN buses
		//
		//! @param[in] unitId - the unit
		//! @param[out] version - the set of version
		void GetUnitVersion(int unitId, UnitVersion& version);


		//! we are asking a device for its version
		void IncrementPollingCount(int deviceId);

		//! Is a version empty (all fields 0)
		bool IsVersionEmpty(const UnitVersion& version) const;

		//! Is a version empty (all fields 0)
		bool IsVersionEmpty(const Version& version) const;

		//! Get the VIN number
		std::string GetVehicleVin();

		// create (part of ) VIN message
		void FillVinMessageData(Ohmio::CAN_MSG& msg);

	private:
		//! Got a version message. update the version
		void ReciveVersionMessage(const CAN_MSG& message);

		//! special version message for motor3
		void ReciveMotor3Message(const CAN_MSG& message);

		//! Get the vin
		void ReadVehicleVin();


	private:
		int m_vinMessageCount;		//!< count the section of VIN message
		std::shared_ptr<VersionsInfo> m_info;
		std::string m_vehicleVin;	//!< VIN number
		std::mutex m_mutex;		//!< for locking the data  
	};
}
