#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "ohmioModelLib/commonInclude.h"

//! Control library for the Ohmio vehicle
namespace OhmioControl
{
	//! Interact with the light. 
	//
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1361969159/Light+control
	//! Some lights are controlled automatically such as break lights or flashing.
	//! Some lights are controlled by on / off commands such as indicators.
	//! And some are activated  manually such as internal lights.
	//! It knows the vehicle direction so can respond to head lights on command with the right 
	//! direction.
	//! It reports on the general state of lights (i.e. driving lights on)
	//! and also the state of individual lights (i.e oval lights are RGB 200,0,0)
	//! This is breaking the model view controller pattern. It is both the model
	//! and the controller. Otherwise we have to split the interpretations
	//! of CAN massages on two classes.
	class DrivingLightsControl : public Ohmio::IMessageObserver
	{
	public:
		//! Constructor
		//
		//! @param[in] receiever - how we get information from the vehicle
		//! @param[in] writeBuffer - connection for writing to the vehicle receiever
		//! @param[in] canTranslator - how to translate lights to messages
		//! @param[in] wpFlagsSourse - how to find out the way point flags.
		//! Shuold be OhmioModel::DriveStatus but can use a mock for testing
		DrivingLightsControl(std::shared_ptr<Ohmio::MessageReceiver> receiever,
			std::shared_ptr<Ohmio::MessageBuffer> writeBuffer,
			std::shared_ptr<Ohmio::ILightToCanTranslator> canTranslator,
			std::shared_ptr<OhmioModel::IWpFlagsSource> wpFlagsSourse);
		~DrivingLightsControl();

		// IMessageObserver interface
		virtual void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//! Which messages are related to this?
		//
		//! When using this class as part of the QT management system the system needs
		//! to pass all these messages to the class
		//! @param[out] messages - list of all the messages IDS that this class needs
		void GetAllMessageIds(std::set<uint64_t>& messages) const;

		//! What does the indicators do. Note that left and right are according to 
		//! vehicle direction, not the vehicle body. When in reverse the class will
		//! switch left / right for you
		enum class IndicatorStatus
		{
			off = 0,	//!< no indicator
			left,		//!< indicating left
			right,		//!< indicating right
			hazard,		//!< indicating both

			// always add before this line
			last		//!< unused
		};


		//! What mode are we in. We will apply rules accordingly
		enum class LightMode
		{
			day = 0,			//!< Operate in day mode (day light running lights, rear red lights off, etc)
			nightLowBeam,		//!< Operate in normal night mode (front lights on, rear red lights on, etc)
			nightHighBeam,		//!< Operate in night mode with high beam (front lights on, rear red lights on, etc)
			test,				//!< Do not operate the light. User it testing lights one by one

			// always add before this line
			last		//!< unused
		};


		// allow manual override of a light item
		enum class LightControl
		{
			autoMode = 0,		//!< control according to rules
			on,					//!< keep the light on
			off,				//!< keep light off

			// always add before this line
			last		//!< unused
		};


		//! Indicate (none, left, right, hazard). 
		void SetIndicators(IndicatorStatus whatToDo, bool overrideWpForTesting = false);

		//! What are we indicating now?
		IndicatorStatus GetIndicators();

		//! Set the mode to use. Are we driving in day or night, etc
		void SetLightingMode(LightMode whatToDo);

		//! Are we driving in day or night, etc
		LightMode GetLightingMode();

		//! Turn a light on / off for testing
		//
		//! Ignored if not in test mode
		//! @param[in] lightList - list of lights to turn on / off
		//! @return false if cannot set the light (not in test)
		bool SetDrivingLightForTest(
			 std::vector<std::pair<Ohmio::DrivingLightItem, bool>>& lightList);

		//! Turn a light on / off 
		//
		//! Should only be used for internal light or other non driving lights
		//! @param[in] lightId - light to control
		//! @param[in] on - should it be on or off
		//! @return false if cannot set the light (not in test)
		bool SetLight(Ohmio::DrivingLightItem lightId, bool on);


		//! Override (or restore) a light control
		//
		//! In general lights should be in auto mode and this function should
		//! not be called.
		//! Mainly used to turn off reverse beeper
		//! @param[in] lightId - light to control
		//! @param[in] mode - what to do with it
		void OverrideLight(Ohmio::DrivingLightItem lightId, LightControl mode);


	private:
		//! Got a drive message
		void UpdateDrivingMode(const Ohmio::CAN_MSG& message);

		//! Got a drive message with the newer format
		void UpdateDrivingModeLongWayPoint(const Ohmio::CAN_MSG& message);

		//! Got a break status message
		void UpdateBreak(const Ohmio::CAN_MSG& message);

		//! get the acceleration (to activate brake light on deceleration)
		void UpdateDecelration(const Ohmio::CAN_MSG& message);

		//! get the acceleration (to activate brake light on deceleration)
		void UpdateDecelrationFromLatMessage(const Ohmio::CAN_MSG& message);

		//! Update the average acceleration from a new reading
		void UpdateDecelerationValue(double accel);

		//! Do the update from the driving message
		void UpdateFromDrivingessage(bool drivingForward);

		//! Got loading message
		void HandleLoadingRequest(const Ohmio::CAN_MSG& message);
		
		//! Got overtake message
		void HandleOvertakeRequest(const Ohmio::CAN_MSG& message);

		//! Are we changing state between break on and off?
		bool IsBreakingChange(bool breaking);


		//! Are we changing direction (forward / reverse)?
		bool IsDirectionChange(bool drivingForward);

		//! Is the hazard changing on / off
		bool IsHazardChange();

		//! Some change to driving requires changes to lights
		void OnModeChange();

		//! Send all the messages to turn lights on / off
		void SendMessages(const std::vector<std::shared_ptr<Ohmio::CAN_MSG>>& messagesToSend);

		//! Find out which light should be on / off
		void ApplyRulesToLights(std::vector<std::pair<Ohmio::DrivingLightItem, bool>>& lights);

		//! Does a light need to be on or off?
		bool ShouldLightBeOn(Ohmio::DrivingLightItem light);

		//! Does a light need to be on or off when we are in loading mode?
		bool ShouldLightBeOnInLoadingMode(Ohmio::DrivingLightItem light);

		//! Get the indicator request from way point flags 
		void GetIndicatorsFromWp();

		//! Get the indicator request from joystick buttons
		void GetIndicatorsFromJoystick();

		//! struct for holding loading mode data
		class LoadingModeLighting
		{
		public:
			LoadingModeLighting() : 
				maxAngle(-1), breaking(false), reverse(false), dualSteering(false), horn(false) {}
			~LoadingModeLighting() {}

			int maxAngle;		//!< max steering angle (0,1,2 allowed)
			bool breaking;		//!< break is on
			bool reverse;		//!< driving reverse
			bool dualSteering;	//!< dual / single axis steering
			bool horn;			//!< horn is on
		};

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
		std::shared_ptr<Ohmio::ILightToCanTranslator> m_translator;			//!< translates lights changes to CAN
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_wpFlagsSourse;		//!< the driving status (used for the indicators flags in file)
		std::shared_ptr<OhmioModel::JoystickStatus> m_joystick;		//!< state of the joystick (to 'jump' to manual)
		std::shared_ptr<OhmioModel::DriveStatus> m_driveStatus;		//!< to get speed from
		std::shared_ptr<OhmioModel::DriveSystemStatus> m_driveSystem;	//!< needed for park break status
		IndicatorStatus m_indicator;		//!< what are we indicating now?
		LightMode m_mode;					//!< what rules should we apply
		int m_breakOffCount;				//!< number of messages since last break release
		int m_drvingMode;					//!< the system mode
		int m_wpOvertakeIndicates;		//!< override the indicators from flags until this WP
		bool m_drivingForward;				//!< are we in forward (true) or reverse (false) direction
		bool m_breakOn;						//!< is breaking?
		bool m_emergencyOn;					//!< is system in emergency?
		bool m_breaking;					//!< break is on now
		bool m_modeOrIndicatorChange;		//!< Did we change mode (day / night) or indicators?
		bool m_overrideIndictorsByUser;		//!< if true use indicators from user request not from flags
		double m_acceleration;				//!< for turning on break lights if decelerating fast 
		std::set<uint64_t> m_messageIds;	//!< list of messageIds we need 
		std::map<IndicatorStatus, bool> m_indicatorButtonsJoystick;	//!< current state of indicator buttons
		std::map<Ohmio::DrivingLightItem, LightControl> m_overrideList;		//!< rules for overriding lights
		LoadingModeLighting m_loadingMode;	//!< information for loading mode
	};

}


