#pragma once


#include "ohmioInterfaceLib/IMessageObserver.h"

namespace OhmioModel
{
	//! the (additional) batteries on the vehicle
	enum class Batteries
	{
		controller = 0,
		breakBattery,
		frontSteering,
		rearSteering,
		door,

		// always add before this line
		last
	};

	//! State of a battery (voltage and alarm)
	class GeneralBatteryState
	{
	public:
		GeneralBatteryState() : voltage(0), alarm(false) {}
		double voltage;		//!< voltage [volts]
		bool alarm;			//!< is alarm on (true) or off (false)
	};

	//! State of the main battery (
	class MainBatteryState
	{
	public:
		MainBatteryState() : heatRelay(false), errorLevel(0), status(0),
			insulationError(0), charge(0), health(0), vendorNum(0), hardwareVersion(0),
			softwareVersion(0), current(0), energy(0), insulationResistance(0), 
			temperature(0), heatCurrent(0), voltage(0), charging(false)
		{}

		bool heatRelay;					//!< heat relay is closed
		int errorLevel;					//!< error from BMS_ERROR_LEVEL
		int status;						//!< status from BMS_STATUS
		int insulationError;			//!< insulation
		int charge;						//!< main battery charge [%]
		int health;						//!< main battery health [%]
		int vendorNum;					//!< version info
		int hardwareVersion;			//!< version info
		int softwareVersion;			//!< version info
		double current;					//!< DC current [Amp]
		double energy;					//!< remaining energy [KWH]
		double insulationResistance;	//!< insulation resistance [K Ohm]
		double temperature;				//!< average temperature [deg]
		double heatCurrent;				//!< current oh heating element [amp]
		double voltage;					//!< voltage [volts]
		bool   charging;                //!< is charging or not
	};

	//! Information about the vehicle power system
	class BatteryStatus : public Ohmio::IMessageObserver
	{
	public:
		BatteryStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~BatteryStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Get the current status of the main buttery
		void GetMainBatteryData(MainBatteryState& data);

		//! Get the current status of a (general) battery
		void GetBatteryData(Batteries batteryToGet, GeneralBatteryState& data);


	private:
		///@{
		//! Recieve a specific message and update status
		void RecieveBatteryMessage(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage1(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage2(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage3(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage4(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage5(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage6(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage7(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage8(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage111(const Ohmio::CAN_MSG& message);
		void RecieveManagementMessage122(const Ohmio::CAN_MSG& message);
		void RecieveDoorMessage(const Ohmio::CAN_MSG& message);
		void RecieveLotteBms1(const Ohmio::CAN_MSG& message);
		void RecieveLotteBms2(const Ohmio::CAN_MSG& message);
		void RecieveLotteBms3(const Ohmio::CAN_MSG& message);
		void RecieveLotteBmsStatus(const Ohmio::CAN_MSG& message);
		void RecieveLotteBmsChargeVehicle(const Ohmio::CAN_MSG& message);
		///@}

	private:
		MainBatteryState m_MainBattery;				//!< the main buttery
		std::array<GeneralBatteryState, (int)Batteries::last> m_additionalBatteries;	//!< other batteries	
		bool m_doorInBatteryMessage;			//! Is the door battery info in the battery message (true) or door (false) 
	};
}


