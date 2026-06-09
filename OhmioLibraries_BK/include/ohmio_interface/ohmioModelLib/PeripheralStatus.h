#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"

namespace OhmioModel
{
	//! What peripheral devices we have (door, step, etc)
	enum class peripheralDevices
	{
		door = 0,	//!< door
		step,		//!< foot step
		foot1,		//!< footing 1
		foot2,		//!< footing 2
		lift,		//!< lift for wheelchair
		charge,		//!< charging gun

		// always add before this line
		last
	};

	//! state of a device (door, foot step, etc)
	enum class deviceState
	{
		off,			//!< Device is not active (foot step in, door close , etc)
		on,				//!< Device is active (foot step out, door opened , etc)
		activating,		//!< Transitioning from off to on (foot step moving out, door opening , etc)
		deactivating,	//!< Transitioning from on to off (foot step moving in, door closing , etc)
		noDevice,		//!< device doesn't exist
		unknown,		//!< device exists but in undefined state

		//! Always put additional states before
		lastState
	};

	class DeviceStatus
	{
	public:
		DeviceStatus() : state(OhmioModel::deviceState::noDevice), errorCode(0) {};
		~DeviceStatus() {};

		OhmioModel::deviceState state;
		int errorCode;
	};

	enum class AirConMode
	{
		Ventilation,
		Cooling,
		Heating,

		// always add before this line
		lastMode	//! invalid
	};


	//! What is the AVAS doing now (should be in a model class)
	class AvasStatus
	{
	public:
		bool active;			//!< is the AVAS active?
		double voltage;			//!< what voltage
		int errorState;			//!< error code from enum AVAS_ERROR
	};


	//! Monitor status of peripheral devises (door, air con, step, etc)
	class PeripheralStatus : public Ohmio::IMessageObserver
	{
	public: 
		PeripheralStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~PeripheralStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Register an observer to get notified when status changed
		void RegisterForChange(const std::shared_ptr<IChangeObserver>& notify);


		//! Get the air condition information
		//
		//! @param[out] roomTemp - room temperature (deg)
		//! @param[out] airConTemp - air condition temperature (deg)
		void GetAirConState(double& roomTemp, double& airConTemp) const;

		//! Get device state
		//
		//! @param[in] device - the device to ask
		//! @return - the state of the device
		OhmioModel::deviceState GetDeviceState(OhmioModel::peripheralDevices device);

		//! Is device in error?
		//
		//! @param[in] device - the device to ask
		//! @param[out] errorCode - the error codes from the device
		//! @return - true if error
		bool IsDeviceError(OhmioModel::peripheralDevices device, int& errorCode);

		//! Get the AVAS status
		void GetAvasState(OhmioModel::AvasStatus& status) const;

		//! Is the horn beeping
		bool IsHornOn();


		//! Get the status emum as a map from value to string
		static void GetStatusNames(std::map<int, std::string>& names);

	private:
		//! Tell all the observers that the status has changed 
		void NotifyChange(peripheralDevices device);

		///@{
		//! Update current state from incoming message
		void UpdateDoorState(const Ohmio::CAN_MSG & message);
		void UpdateStepState(const Ohmio::CAN_MSG & message);
		void UpdateFoot1State(const Ohmio::CAN_MSG & message);
		void UpdateFoot2State(const Ohmio::CAN_MSG & message);
		void UpdateAirConState(const Ohmio::CAN_MSG & message);
		void UpdateChargingState(const Ohmio::CAN_MSG & message);
		void UpdateAvsState(const Ohmio::CAN_MSG & message);
		void UpdateHornState(const Ohmio::CAN_MSG & message);
		///@}

	private:
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		std::map<OhmioModel::peripheralDevices, DeviceStatus> m_devices;
		OhmioModel::AvasStatus m_avasState;	//!< the AVAS
		double m_airConTemp;	//!< air con status
		double m_roomTemp;		//!< air con status
		bool m_hornOn;			//!< is the horn beepong

	};


}

