#pragma once
#include "ohmioModelLib/ModeStatus.h"
#include "ohmioModelLib/DriveStatus.h"
#include "ohmioModelLib/ChangeMonitor.h"
#include "ohmioInterfaceLib/CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include "canbus/dbc_MsgID_main.h"
#include "PeripheralControl.h"
#include "SystemControl.h"
#include "LaneChanger.h"

namespace OhmioControl
{
	//! Reasons for stopping
	enum class StopReason
	{
		ManagementRequest,			//!< request from management computer
		BusStop,					//!< arriving at a stop
		Joystick,					//!< joystick switch to manual
		remoteControl,				//!< joystick switch to manual
		porter,						//!< stop from external interface

		// Always add before this
		last
	};

	//! Interface class for DriveControl to allow using mock for testing
	class IDriveControl
	{
	public:
		//! Perform the user request
		//
		//! Translate the user request into a massage (or several messages) 
		//! and send to the vehicle
		//! @param[in] control - the control item that was changed
		//! @param[in] actionValue - a value associated with the UI item 
		//! (the new track id, the new speed limit, etc)
		//! If the action is Stop the value is:
		//!  - the way point index to stop at (if actionValue > 0) 
		//!  - the acceleration rate in mm/sec^2 (if actionValue < 0) 
		//!  - using default deceleration (if actionValue == 0) 
		//! @return true if the action is valid, false if not
		virtual bool PerformAction(OhmioModel::DriveButtons control, int actionValue) = 0;

		//! Should a UI item be enabled?
		virtual bool IsEnabled(OhmioModel::DriveButtons control) = 0;

		//! Set limp mode.
		//
		//! In limp mode the vehicle can only drive in manual and slow
		//! but it ignore all safety features
		virtual void LimpMode(bool on) = 0;

		//!@{
		//! For the existing QT system change all the states in one command
		//
		//! Used only for QT app
		//! @param[in] mode - the new mode for the vehicle 
		//! @param[in] path - what track we should use. If < 0 keep existing value
		//! @param[in] maxSpeed - in mm/sec. If < 0 keep existing value
		//! @param[in] lidar - should we use lidars for obstacle detection
		//! @param[in] ultraSound - should we use ultra sound for obstacle detection
		//! @param[in] errorCheck - should we get to emergency if there is an error
        //! @param[in] reason - if false is returned this string will contain the reason
        //! @return true if can perform the action, false if not. Note that it will always send the 
        //! message. If the action is not valid it will be substituted by a valid one
		virtual bool SetDrivingState(SYS_STATES mode, int path, int maxSpeed, bool lidar, bool ultraSound, bool errorCheck, std::string& reason) = 0;
		//!@}


		//! Simulate driving to allow UI testing
		//
		//! @param[in] simulate - TRUE for simulation, FALSE use the real value 
		//! @param[in] speed - Speed in mm/sec. Negative if in reverse. Ignored if simulate == false
		virtual void SimulateDrivingForAvs(bool simulate, double speed) = 0;

		//! Is the hardware supporting the 'stop at' command? 
		//
		//! Used only for unit tests. If the command is not supported
		//! it is replaced by the appropriate SetDrivingState by the implementation class
		virtual bool IsStopAtAvailable() = 0;

		//! @{
		//! stop at specific location
		//! @param[in] wp - WP to stop at
		//! @param[in] latitude - latitude of stop
		//! @param[in] longitude - longitude of stop
		//! @param[in] distance - if the location is too far from the track ignore it
		//! @return true if can stop
		virtual bool StopAt(int wp) = 0;
		virtual bool StopAt(double latitude, double longitude, double distance) = 0;
		//! @}


		//! Enable (true) or disable (false) driving
		//
		//! To allow passengers to 'hold' the bus while getting on / off 
		virtual bool EnableDrive(bool enable) = 0;

		//! Is driving disabled because 'hold' button is pressed
		virtual bool IsDrivingDisabled() = 0;

		//! Enable (true) or disable (false) the GPS
		//
		//! Disable GPS while driving with bad reception mainly for testing and recording key frames for SLAM 
		virtual void EnableGps(bool enable) = 0;

		//! SEnd a bypass track command
		//
        //! @param[in] startWp - the way point to start the bypass
        //! @param[in] endWp - the way point to end the bypass	
        //! @param[in] bypassMode - from enum CONNECT_TRACK_TYPE
        //! @param[in] beforeWp - number of way points to use for curve calculations
        //! @param[in] skipping - true if we are skipping a stop, false if restoring the original track
		virtual void SendBypassTrack(int startWp, int endWp, int bypassMode, int beforeWp, bool skipping) = 0;



	};

	//! Control the vehicle driving (start, stop, track select, etc)
	//
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1042022401/Simple+controller+UI
	//! Note that some safety features such blocking door open when driving
	//! are implemented by the low level interface (blocking unsafe messages)
	class DriveControl : public IDriveControl, public Threading::RunInThreadForever
	{
	public:
		//! Constructor
		//
		//! @param[in] model - the relevant parts of the sate of the vehicle
		//! @param[in] writeBuffer - connection for writing to the vehicle
		//! @param[in] sysControl - needed for recovering from emergency
		//! @param[in] safety - for limp mode
		DriveControl(std::shared_ptr<Ohmio::CommunicationManager> vehicle,
			std::shared_ptr<IPeripheralControl> peripheral,
			std::shared_ptr<SystemControl> sysControl,
			std::shared_ptr<Ohmio::SafetyRegulator> safety
		);
		~DriveControl();

		//! Get the model (DriveStatus) so that we can monitor the vehicle
		std::shared_ptr<OhmioModel::DriveStatus> GetModel();

		//! Set the vehicle to towing mode or not
		//
		//! in towing mode we release the park break
		void SetTowing(bool towing);

		//! are we in towing mode?
		bool IsTowing();

		//! Set the speed and distance for lane change
		//
		//! this function is obsolete the offset limit are taken from the track
		//! @param[in] offset - distance (m) to next lane (<0 is left)
		//! @param[in] speedUnused - not used anymore. remains in to keep the interface working
		void SetLaneChangeParams(double offset, double speedUnused);
		
		//! Set to bidirectional (symmetric front back) or not
		void SetBidirectional(bool bidirectional);


        //! activate the AVAS sound for a specific period (if called with 0 it will stop the sound)
        void SoundTramNoise(int activeForSeconds);	

		// IDriveControl interface
		bool IsEnabled(OhmioModel::DriveButtons control) override;
		bool PerformAction(OhmioModel::DriveButtons control, int actionValue) override;
		bool SetDrivingState(SYS_STATES mode, int path, int maxSpeed, bool lidar, bool ultraSound, bool errorCheck, std::string& reason) override;
		void SimulateDrivingForAvs(bool simulate, double speed) override;
		bool IsStopAtAvailable() override;
		void LimpMode(bool on) override;
		bool EnableDrive(bool enable) override;
		bool IsDrivingDisabled() override;
		void EnableGps(bool enable) override;
		bool StopAt(int wp) override;
		bool StopAt(double latitude, double longitude, double distance) override;
		void SendBypassTrack(int startWp, int endWp, int bypassMode, int beforeWp, bool skipping) override;

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
        //@{ 
		//! Update the state for a particular driving mode
		bool IsSpeedEnabled();
		bool IsPathEnabled(int VechicleState);
		bool IsStartEnabled(int VechicleState);
		bool IsStopEnabled(int VechicleState);
		bool IsGoEnabled(int VechicleState);
		bool IsLidarEnabled(int VechicleState);
		bool IsErrorEnabled(int VechicleState);
		bool IsOvertakeEnabled(int VechicleState);
		bool IsReturnToLaneEnabled(int VechicleState);
		bool IsIdleEnabled(int VechicleState);
		bool IsTowingEnabled(int VechicleState);
		//@}


		//@{ 
		//! functions called by RunLoopOnce
		void InitialseIfNeeded();
		void DoTowingAsNeeded();
		void HandleStandBy();
		void HandleLimpMode();		// send recover and set to manual if we are in limp mode
		void ResetLaneChagerIfNeeded(); // reset the lane changer if we are in an invalid state
		void PerformJoystickActions();
		void OvertakeFromRemoteIfRequested();
		void IgnoreDzAsNeeded();
		void DisableGpsAsNeeded();
		//@}

		// can the user ignore DZ?
		bool CanIgnorDZ(int VechicleState);

		//! The vehicle has stopped. What do we do now?
		void HandleVehicleStop();

		//! construct the command for the vehicle and send it
		bool SendDriveCommand(OhmioModel::DriveButtons control, int actionValue);

		//! Tell the vehicle to stop
		//
		//! @param[in] stopParameter - 
		//! if stopParameter < 0 this is the decelaration to use (mm / sec ^2)
		//! if stopParameter > 0 this is the way point index to stop at
		//! if stopParameter == 0 use default deceleration
		bool SendStopCommand(int stopParameter, StopReason reason);


        //! recover from emergency
		void RecoverFromEmergency();


		//! Send periodic park break release command (when in towing)
		void ReleaseParkBreak();
        
		//https://owncloud.hmi.co.nz/owncloud/index.php/apps/files/?dir=/ohmio/ohmio-intern/Korea/Vehicle%20design/DTG_Korea&fileid=
		//https://owncloud.hmi.co.nz/owncloud/index.php/apps/files/?dir=/ohmio/Documentation/External&fileid=1165384
		//! Send the DTG message for the Korean DTG device including:
		//! Motor RPM
        //! Brake activation information
        //! Vehicle speed
		void SendDtgIfNeeded();

		//! Initialize the drive control for the first time
		void InitialiseDrive();

		//! The joystick changed state - do we need to do something about it?
		void HandleJoystickChange();

        //! Limit the max speed according the obstacle range
		int LimitSpeedByObstacleRange(int request);

	private:
		std::shared_ptr<IPeripheralControl> m_peripheral;		//!< to know if door is open
		std::shared_ptr<SystemControl> m_sysControl;			//!< for recover from emergency
		std::shared_ptr<LaneChanger> m_laneChanger;				//!< handling lane change maneuver
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
		std::shared_ptr<Ohmio::SafetyRegulator> m_safety;		//!< for limp mode
		std::shared_ptr<Ohmio::MessageReceiver> m_receiever;	//!< for sending to the model messages we send to the vehicle
		std::shared_ptr<Ohmio::CommunicationManager> m_vehicleComms;		//!< for disabling GPS
		std::shared_ptr<OhmioModel::DriveStatus> m_state;		//!< monitor the state of the UI items
		std::shared_ptr<OhmioModel::DriveSystemStatus> m_system_state;	 //!< monitor the drive system (steering, speed, etc) status
		std::shared_ptr<OhmioModel::JoystickStatus> m_joystick;		//!< state of the joystick (to 'jump' to manual)
        std::shared_ptr<OhmioModel::ObstacleStatus> m_obstacle;		//!< needed for setting max speed according to the obstacle range
		std::shared_ptr<OhmioModel::RemoteStatus> m_remoteControl;	//!< state of the remote (for 'go' button on remote control)
		std::shared_ptr<OhmioModel::ChangeMonitor> m_joystickChange;	//!< Get notified when joystick state changes
		std::shared_ptr<OhmioModel::ChangeMonitor> m_changeDetector;	//!< Get notified when state changes
		std::chrono::high_resolution_clock::time_point m_lastTowingTime; //!< last time we sent a towing command
		std::chrono::high_resolution_clock::time_point m_lastDtgTime; //!< last time we sent a DTG command for the Korean DTG device
		std::chrono::high_resolution_clock::time_point m_lastLimpTime; //!< last time we sent message for limp mode
        std::chrono::high_resolution_clock::time_point m_EndTramSound; //!< stop sounding the reverse beeper for tram sound at this time
		int m_AVAS_req_counter;                                 //!< counter for AVAS request        
		int m_doorOpenRetry;									//!< retry for door
		int m_ignoreDzWp;										//!< way point to stop ignoring DZ
		bool m_towing;											//!< are we in towing mode now?
		bool m_bidirectional;									// is driving the same forward and reverse?
		bool m_limpMode;										//!< allow driving out of emergency
		bool m_driveInitialized;								//!< have we set the drive status for the first time?
		bool m_disabled;										//!< if true we don't allow driving
		bool m_joystickSwitchToManual;							//!< we got a joystick command to switch
        bool m_SentIdleForKeyStandBy;                           //!< set it to true after sending and false when the key is not off
        bool m_gpsDisabledByUI;									//!< user requested GPS off
		double m_laneChangeOffset;								//!< distance to next lane for overtaking (m)
	};

}

