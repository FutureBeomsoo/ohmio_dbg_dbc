#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"
#include "track_utilities/EventFileLoader.h"
#include "DrivingFlagsDefenitions.h"
#include <mutex>
#include <chrono>

namespace OhmioModel
{
	//! List of driving control UI items
	enum class DriveButtons
	{
		SpeedControl = 0,	//!< Max speed slider
		PathSelector,		//!< combo box for track selection
		Start,				//!< start button
		Stop,				//!< stop button
		Go,					//!< go button
		Lidar,				//!< turn lidars on / off
		UltraSoundUnused,	//!< space holder. not used anymore
		ErrorChecks,		//!< turn error checking on / off
		Manual,				//!< set to manual driving
		Overtake,			//!< shift to the next lane in order to overtake am obstacle
		ReturnToLane,		//!< Return to track after overtaking finished
		idle,				//!< change to idle
		towing,				//!< change to towing mode

		// Insert more controls above this 
		last				//!< for counting the buttons
	};


	//! the key state
	enum class KeyStatus
	{
		off = 0,			//!< key is in off
		standBy,			//!< key position 1
		on,					//!< key position 2

		// always add before
		last
	};


	//! The current state of the driving system. see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1042022401/Simple+controller+UI
	class DriveStatus : public Ohmio::IMessageObserver , public IWpFlagsSource
	{
	public:
		DriveStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~DriveStatus();

		// IMessageObserver interface
		void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//! IWpFlagsSource interface
		uint16_t GetFlag1() override;
		uint16_t GetFlag2() override;
		bool GetEventData(std::vector<TrackEvent>& eventData) override;
		int GetWpIndex() const override;
		void GetAllEventsForTrack(std::vector<TrackEvent>& eventData) override;
		void GetAllEventsForTrack(std::vector<TrackEvent>& eventData, wayPointeventFlag requestedType) override;
		bool GetWpLocation(int wpIdx, double& latitude, double& longitude, double& heading) override;
		int FindWpForLocation(double latitude, double longitude, double requiredDistance, int startWP) override;
		void SetStopDestination(int wpIdx) override;
		int GetTrackLength() const override;
		int GetDrivingMode()  const override;
		bool IsTrackContainUnsdafeFeatures() const override;
		bool IsTrackValid() const override;
		double GetSpeed() const override;
		//! Get the track MD5 id
		uint64_t GetTrackId() const override;
		virtual bool IsDriveHeartbitOn() const override;


		//! Get the drive control version (just major minor, no build or debug)
		std::pair<int, int> GetControllerVersion();

		//! Which messages are related to this?
		//
		//! When using this class as part of the QT management system the system needs
		//! to pass all these messages to the class
		//! @param[out] messages - list of all the messages IDS that this class needs
		void GetAllMessageIds(std::set<uint64_t>& messages) const;

		//! Get the name of a control item for diagnostics
		static std::string GetItemName(DriveButtons item);

		//! Set the value associated with a control item 
		void SetRequestedControlValue(DriveButtons item, int actionValue);

		//! Where should we load track files from
		//
		//! @param[in] the folder for storing the track file. Must include the '\' at the end
		void SetTrackFilesFolder(std::string folder);

		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);
		void RegisterToWayPoint(const std::shared_ptr<IChangeObserver>& notify) override;
		void RegisterToTrack(const std::shared_ptr<IChangeObserver>& notify) override;

		//! What is the current startup state?
		//
		//! return int from STARTUP_STATUS
		int GetStartupStaus();

		//! Did we read the minimum required data from the actual vehicle?
		bool IsInitialized();

		//! Simulate driving to allow UI testing
		//
		//! @param[in] simulate - TRUE for simulation, FALSE use the real value 
		//! @param[in] speed - Speed in mm/sec. Negative if in reverse
		void SimulateDrivingForAvs(bool simulate, double speed);

		//! Are we near the end so should announce "arriving .."?
		bool IsEndOfTrack() const;

		//!< what is the status of the key
		KeyStatus GetKeyStatus();

		//! Get the status emum as a map from value to string
		static void GetKeyStatusNames(std::map<int, std::string>& names);

		//! Are we driving on the right (true) or left (false) side of the road
		bool IsRightHandDriving();

		//! Is the vehicle stopped?
		bool IsStopped();

		//! Check if the track is safe to drive on
		//
        //! @param[in] path - the track index to check this is the path as in the mode message 
        //! 0 - 1F, 1 - 2F, 2 - 1R, 3 - 2R
		bool IsTrackSafe(int path);


		//@{
		//! Getters
		int GetCurrentState(modelQueryType queryType) const;
		bool IsUseErrorCheck(modelQueryType queryType) const;
		bool IsUseLidar(modelQueryType queryType) const;
		bool IsUseUltrasound(modelQueryType queryType) const;
		int GetCurrentMaxSpeed(modelQueryType queryType) const;
		int GetCurrentPath(modelQueryType queryType) const;
		int GetVehicleSpeed(modelQueryType queryType) const;
		int GetWayPoint(modelQueryType queryType) const;
		double GetSpeedRpm(modelQueryType queryType) const;
		double GetErrorDistance(modelQueryType queryType) const;
		bool IsReverseDriving(modelQueryType queryType) const;
		//@}

		//! For debugging
		int GetLastButtonPressed(); 

	private:
		//! Tell all the observers that the status has changed 
		void NotifyChange();

		//! Set the requested state to the actual so that when we get a new request we don't change the other fields
		void CopyDriveToRequest();


		//! Load a track file
		uint64_t LoadTrack(const std::string &trackFile);

		//! Load an events file
		uint64_t LoadEvents(const std::string &eventsFile);

        // ! Load a danger file - just for safety checks
		uint64_t LoadDanger(std::string fileName, std::vector<OHMIO_DANGER_POINT_INFO_t>& dangers);

        //! is manual driving
		bool IsManualDriving();

		//@{
		//! Got a message from vehicle
		void RecieveSpeedMessage(const Ohmio::CAN_MSG& message);
		void RecieveDriveMessage(const Ohmio::CAN_MSG& message);
		void RecieveDriveMessageLongWp(const Ohmio::CAN_MSG& message);
		void RecieveTrackMessage(const Ohmio::CAN_MSG& message);
		void RecieveVersionMessage(const Ohmio::CAN_MSG& message);
		void RecieveStartupMessage(const Ohmio::CAN_MSG& message);
		void RecieveManualMessage(const Ohmio::CAN_MSG& message);
		//@}

		//@{
		//! Update current state and report change
		//
		//! @param[in] newValue - what we got from the message
		//! @param[in,out] current - our current state that may need to change
		//! @return true if this value has changed
		bool UpdateIntValue(int64_t newValue, int& current);
		bool UpdateBoolValue(int64_t newValue, bool& current);
		bool UpdateStateValue(int newValue, int& current);
		bool UpdateFlags();
		//@}

		//! Get the speed value out of a motor message
		double ExtractSpeedFromMotorMessage(const Ohmio::CAN_MSG& message);

		//! does point contain features that may make driving unsafe
		bool IsPointUnsafe(const WAY_POINT_DRIVE_t& wp) const;


		//! Update the stop hysteresis counter
		void UpdateStopCount();

	private:
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		std::vector<std::shared_ptr<IChangeObserver>> m_trackNotify;	//!< tell these when track change
		std::string m_trackFilesFolder;									//!< where to load track files from
		std::set<uint64_t> m_messageIds;								//!< list of message Ids we need 
		std::chrono::high_resolution_clock::time_point m_lastDriveHeartBitTime;	//!< time of the last WP message

		std::mutex m_eventLock;				//!< lock the events vector when getting it

		uint64_t m_trackId;					//!< track ID (MD5)
		uint16_t m_flags1;					//!< track annotation flags 
		uint16_t m_flags2;					//!< track annotation flags 
		std::vector<TrackEvent> m_currentEvents; //!< events info for current WP
		bool m_eventsOK;					//!< event data loaded correctly
		bool m_rightSideDriving;			//!< Are we driving on the right or left side of the road

		std::vector<OHMIO_WAY_POINT_DRIVE_t> m_Track;	//!< the track
		std::vector<ExtendedEvent> m_events;	//!< the events

		bool m_overrideSpeedForSimulation;		//!< replace speed with UI data
		bool m_usingMotor1;						//!< we have the old motor
		double m_simulatedSpeed;				//!< speed to use if simulation
		int m_destinationWpIdx;					//!< the WP index of the next stop
		int m_stopCount;						//!< hysteresis for stop
		bool m_stopped;							//!< moving or stopped

		std::pair<int, int> m_controllerVersion;	//!< version of the drive control (just major and minor)

		int m_startupStatus;				//!< stratup mode
		KeyStatus m_keyStatus;				//!< status of the key

		int m_lastButtonPressed;			//!< for debugging remember last request

		//! The state of the vehicle
		class vehicleState
		{
		public:
			vehicleState();
			~vehicleState();
			bool m_brake;					//!< is break on?
			bool m_reverse;					//!< are we going forward (false) or reverse (true)
			bool m_useErrorCheck;			//!< are we checking errors ?
			bool m_useLidar;				//!< are we using lidars?
			bool m_stateInit;				//!< has the state been initialized?
			int m_currentMode;				//!< current state of the vehicle mode (from SYS_STATES enum)
			int m_wayPointIdx;				//!< current way point we are on - unused
			int m_path;						//!< current track id
			int m_maxSpeed;					//!< current speed limit of the vehicle mm/Sec
			int m_vehicleSpeed;				//!< current speed of the vehicle mm/Sec
			int m_errorDistance;			//!< deviation from track. internaly held in mm
			double m_speedRpm;              //!< speed rpm
		};
		std::array<vehicleState, (int)OhmioModel::modelQueryType::last> m_state;	//! the actual and requested states
	};
}

