#pragma once
#include "CommonInclude.h"
#include "IMessageObserver.h"
#include "UtilityLib/RunInThreadForever.h"

namespace Ohmio
{
	//! Reason for blocking or allowing messages
	enum class SafetyReason
	{
		Ok,								//!< we are in safe mode
		IncompatableVersions,			//!< driving disallowed because of mismatched versions 
		PeripheralDeviceActive,			//!< driving disallowed because a device is operating
		BlockedWhileDriving,			//!< devices stopped because the vehicle is driving
		BootLoaderFailed,				//!< at least one device boot loader failed
		LimpMode,						//!< limited driving to get out if the road only 
		UnsafeTrack,					//!< the track contain unsafe feature (reduced safety margins) that requires operator approval. 
		AutoDisallowed,					//!< auto driving disallowed becuse of some error

		// always add above 
		last
	};

	//! Filter outgoing messages to prevent sending of dangerous messages
	//
	//! The main functionality is implemented in IsMassageSafe().
	//! This is called by the CAN bus loop to filter messages before they are sent to the bus.
	//! The UI may access this class to understand why messages are disabled and inform the users.
	//! There are also allowances for the UI to enable or disable safety features.
	//! For example prevent opening the door while driving. 
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1352859649/Safety+regulator
	//! It monitor versions messages directly and not using OhmioModel::VersionsStatus becuse 
	//! we need additional functionality here that we don't want to expose to the model library
	class SafetyRegulator : public IMessageObserver
	{
	public:
		SafetyRegulator(std::shared_ptr<MessageReceiver> receiver);
		~SafetyRegulator();


		//! Is a message safe to send to the vehicle
		//
		//! @param[in,out] message - the message to test. The
		//! message may be change in order to make it safe. For
		//! example if the message is driving mode but the vehicle
		//! is not safe to drive the mode will be set to idle
		//! @return true if the messages is OK and can be sent to the
		//! vehicle (including if it was modified). false if this message should be blocked
		virtual bool IsMassageSafe(CAN_MSG& message) const;

		//! For work on the vehicle we may need to drive with door opened
		//
		//! @return the status before this call so that caller can restore to original state
		bool AllowDrivingWithOpenedDoor(bool allow);

		//! User acknowledged a track with unsafe features
		void AllowUnsafeTrack(bool allow);


		//! Allow or disallow auto drive if V2X error. Korea disallow others allow for now
		void AllowAutoWithoutV2X(bool allow);

		//! Are we allowed to drive with door opened?
		bool IsAllowDrivingWithOpenedDoor() const;

		//! For work on the vehicle we may need to drive with door opened
		//
		//! @return the status before this call so that caller can restore to original state
		void IgnoreAllPeripherals(bool allow);

		//! Are we allowed to drive with door opened?
		bool IsIgnoreAllPeripherals() const;

		//! Set limp mode.
		//
		//! In limp mode the vehicle can only drive in manual and slow
		//! but it ignore all safety features
		void LimpMode(bool on);

		//! Are we in limp mode?
		bool IsLimpMode() const;

		//! Is it safe to drive?
		//
		//! Mainly for diagnostics
		//! @param[in] drivingMode - mode we want to drive in from SYS_STATES enum. (stronger restrictions for auto)
		//! @param[out] operatingDevice - ID of device that prevent driving. 0 if no such device.
		//! - if return is PeripheralDeviceActive this is the peripheral device (door, charging cable, etc)
		//! - if return is BootLoaderFailed this is the ID of the unit that is still in boot loader stage
		//! @return Ok or the reason for disabling driving
		SafetyReason CanDrive(int drivingMode, uint64_t& operatingDevice) const;

		//! Is it safe to operate devices such as foot step?
		//
		//! Mainly for diagnostics
		//! @return Ok or the reason for disabling
		SafetyReason CanOperateDevices() const;

		//! Is the door safe to operate now?
		bool IsDoorAllowed() const;

		//! Get the status of all the devices.
		//
		//! For diagnostics
		//! @param[out] devices - the list of all the devices it monitors 
		//! and their state. The map key is the device status message,
		//! the value is true if the device is active (not safe to drive)
		void GetDeviceStatus(std::map<uint64_t, bool>& devices) const;

		///@{
		//! Get the actual or expected versions of all the devices on the CAN buses
		//
		//! For diagnostics
		//! @param[out] versions - the set of versions
		void GetExpectedVersions(VersionsInfo& versions) const;
		void GetActualVersions(VersionsInfo& versions) const;
		///@}

		///@{
		//! Set the versions we need to have to be safe.
		//
		//! @param[in] csvFile - full path to a file containing the versions
		//! @param[in] versions - the versions
		void SetExpectedVersions(std::string csvFile);
		void SetExpectedVersions(VersionsInfo& versions);
		///@}

		// Inherited via IMessageObserver
		virtual void MessageCallback(const CAN_MSG & message) override;

		//! Send messages for polling versions
		//
		//! A bit of ugly design here.
		//! This class does not have direct access to the writing buffer
		//! and does not have a timer thread. So the CAN bus loop is calling
		//! this to generate the messages. 
		void PollVersions(MessageBuffer& writingBuffer);

		//! Which unit / device (if any) prevent us from driving
		//
		//! @param[in] drivingMode - what mode is requested
		//! @param[out] reason - why are we disabled
		//! @return 0 if safe to drive, unit or device ID if not
		uint64_t GetStoppingDeviceId(int drivingMode, SafetyReason& reason) const;

		//! Is the mode in question a driving mode (drive, manual, etc)
		static bool IsModeDriving(int state);

		//! Get a list of all the problems
		//
		//! @param[out] reasons - why we can't drive.
		void GetAllBlockingReasons(std::vector<std::pair<SafetyReason, uint64_t>>& reasons);

		//! Get all the problems by the unit IDs
		//
		//! @param[out] reasons - why we can't drive.
		void GetReasonsMap(std::multimap<uint64_t, SafetyReason>& reasons);

		//! The current track contains unsafe features (true) or not (false)   
		void SetUnsafeTrack(bool unsafe);


	private:
		///@{
		//! Got a state changing message. Set vehicle state
		void ReciveStateMessage(const CAN_MSG& message);
		void ReciveStateMessageLongWp(const CAN_MSG& message);
		///@}

		//! Got a device message. Is the device in or out?
		bool InterpretDeviceMessage(const CAN_MSG& message);

		///@{
		//! Interpret a specific message 
		bool IsDoorMessageUnSafe(const CAN_MSG& message);
		bool IsStepMessageUnSafe(const CAN_MSG& message);
		bool IsFoot1MessageUnSafe(const CAN_MSG& message);
		bool IsFoot2MessageUnSafe(const CAN_MSG& message);
		bool IsVehicleCharging(const CAN_MSG& message);
		bool IsVehicleChargingLotteBms(const CAN_MSG& message);
		bool IsVehicleConnected(const CAN_MSG& message);
		bool IsV2xError(const CAN_MSG& message);
		///@}


		//! Get all the units with boot loader Errors
		void CheckBootLoaderErrors(std::vector<int>& failedIds) const;

		//! This is a driving message and we are not allowed to drive. Change the state
		bool PreventDriving(CAN_MSG& message) const;

		//! This is a driving message and we are in limp mode. Change the state
		void LimpModeDriving(CAN_MSG& message) const;

		//! Can we do this while driving?
		bool IsMassageSafeWhileDriving(uint64_t messageId) const;

		//! Is this message setting the mode ? 
		bool IsDriveMessage(uint64_t messageId) const;

		//! Are the expected and actual versions the same?
		bool AreVersonsMatching() const;

		//! Create a version request message for a bus
		std::shared_ptr<CAN_MSG> CreateVersionReqMessage(CanBuses busToSendOn, int deviceToPoll);

		//! Should this message override the rules because it is a door open message?
		bool IgnoreBecauseDoor(uint64_t messageId) const;

		//! When driving(auto) disable the door button
		void EnableOrDisableDoorAccordingToStatae(CAN_MSG& message) const;

		//! When driving pull the step in
		void RetractStepIfDriving(CAN_MSG& message) const;

		// cannot drive while this device is active
		class PreventDrivingDevice
		{
		public:
			PreventDrivingDevice(uint64_t messageId = 0) 
				: sendingMessageId(messageId), isActive(false), lastMessageTime(std::chrono::high_resolution_clock::now())
			{};
			uint64_t sendingMessageId;
			bool isActive;
			std::chrono::high_resolution_clock::time_point lastMessageTime;
		};

		class PreventAutoDrive
		{
		public:
			PreventAutoDrive(uint64_t messageId = 0, bool disabled = false)
				: sendingMessageId(messageId), preventDriving(false), isDisabled(disabled)
			{};
			uint64_t sendingMessageId;		//!< what message we check for this item
			bool preventDriving;					//!< this message indicates no drive
			bool isDisabled;				//!< this restriction is disabled 
		};


		//! Is A device active so blocking driving?
		bool IsDeviceActive(const PreventDrivingDevice& device) const;


	private:
		std::set<uint64_t> m_notOperateWhileDrive;	//!< All the external devices that cannot operate while driving
		std::map<uint64_t, PreventDrivingDevice> m_notAllowedToDrive;	//!< All the things that stop us from driving
		std::map<uint64_t, PreventAutoDrive> m_notAllowedAutoDrive;		//!< All the things that stop us from driving in auto

		int m_currentVehicleState;	//!< what is the current state of the vehicle?
		std::shared_ptr<VersionsInfo> m_expectedVersions;	//!< the versions we should have for all devices
		std::shared_ptr<VersionsStatus> m_versionReader;	//!< keep track of current versions
		int m_nextDeviceToPoll;								//!< which device ID should we poll next time?
		bool m_obstacleSystemFound;							//!< we had detected the obstacle system
		bool m_unsafeTrackAllowed;							//!< Has operator indicated that it is OK to drive with unsafe features
		bool m_trackHasUnsafeFeature;						//!< the current track contains unsafe features

		
		//! bit field for how much safety we want
		enum saftyLevels
		{
			fullSafety			= 0x0,			//!< the standard mode. Does not allow driving if anything is wrong
			doorAlllowed		= 0x1,			//!< allows driving if door is open
			peripheralsAllowed	= 0x2,			//!< allows driving if any peripheral device is operating
			limp				= 0x4,			//!< allows minimal action after an emergency stop

			lastSafety
		};
		saftyLevels m_safetyLevel;	//!< what are we allowed to do?
	};

}

