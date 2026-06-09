#pragma once
#include "track_utilities/WayPointDefinitions.h"
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/commonInclude.h"
#include "ohmioModelLib/DrivingFlagsDefenitions.h"
#include <chrono>


class TrafficLightControllerTests; // forward declaration for friend

namespace OhmioControl
{
	class TrafficLightEventData;

	//! Control the vehicle behavior near a traffic light
	//
	//! After creating the object call StartThread to start it 
	//! Monitor the way point and events to know if the vehicle
	//! is in the area of a traffic light and the message it needs.
	//! Get the messages from the V2X.
	//! Tell the vehicle to stop or go accordingly
	class TrafficLightController : public Threading::RunInThreadForever
	{
	public:

		//! constructor
		//
		//! @param[in] writeBuffer - how we send messages to the bus
		//! @param[in] wpFlagsSourse - how we know where we are
		//! @param[in] receiver - copy the messages we send out to our internal buffer 
		//! so that the model library we can flow the state of the traffic light
		TrafficLightController(std::shared_ptr<Ohmio::MessageBuffer> writeBuffer,
			std::shared_ptr<OhmioModel::IWpFlagsSource> wpFlagsSourse,
			std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~TrafficLightController();

		//! What are we seeing now
		//
		//! @param[out] emergeny - true if current state is emergency (lost communication near the light) 
		//! @return int value corresponds to TRAFFIC_LIGHT_STATUS
		int GetCurrentState(bool& emergeny);

		//! Is there an active error
		//
		//! This is needed for Korea. They use OBU and camera
		//! If the OBU is on but camera is not working they
		//! want to display error but keep on driving.
		//! So we need to separate the error bit in the message from the 
		//! flag IsInError() for display
		bool IsInError(); 

		//! How long (seconds) before the light changes to red
		int GetTimeToRed(); 

		//! Override the traffic light and set the light to green
		void SetGreenLight();

		//! Can the user set the light to green
		bool CanSetGreenLight();


		//! How long can we wai for message before we generate an error;
		void SetV2xPeriodTolerance(int perionMsec);


		//! Set driving to stop line if V2X error
		void AlwaysDriveToStopLine(bool drive);


		//! Set the traffic light state - this is the V2X message coming from interface instead of directly from OBU
		//
		//! @param[in] regionID - region from SPAT message
		//! @param[in] intersectionID - intersection from SPAT message
		//! @param[in] movement - some identifying string
		//! @param[in] status - current status value corresponds to TRAFFIC_LIGHT_STATUS 
		//! @param[in] timeToChange - time (seconds) before the light changes 
		bool SetLightStatus(int regionID, int intersectionID, const std::string& movement, int status, double timeToChange);

		//! Set a temporary light. Mainly for testing
		//
		//! @param[in] wpIdx - stop way point
		//! @param[in] regionID - region from SPAT message
		//! @param[in] intersectionID - intersection from SPAT message
		//! @param[in] movement - some identifying string
		//! @param[in] timeToCross - time (seconds) that it takes the vehicle to cross the junction 
		bool SetTrafficLight(int wpIdx, int regionID, int intersectionID, const std::string& movement, double timeToCross);

		//!@{
		//! Getters
		int GetDistanceToStop() const;
		int GetRegionId() const;
		int GetIntersectionId() const;
		std::string GetMovementName() const;
		double GetTimeToCross() const;
		double GetMillisecFromLastMessages() const;
		//!@}



	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! information about a traffic light we are monitoring
		class traficLightInfo
		{
		public:
			int timeToCross;				//!< time needed to cross the intersection (in 0.1 sec units)
			int timeToChange;				//!< time before the light should change (in 0.1 sec units)
			int timeToChangeInMessage;		//!< to allow proper count down when we have low frequency message
			bool go;						//!< green light?
			bool active;					//!< we are in this traffic light influence
			int actionPoint;				//!< the way point where we cross the line
		};

		class stopEvent
		{
		public:
			bool go;						//!< user released
			int wpIndex;					//!< way point index of the stop
		};

		//! create the message to send to the CAN bus
		void FillMessageData(Ohmio::CAN_MSG& toSend);

		//! Check the events to see what we are looking for
		void GetTrafficLightWeNeed();

		//! No event found - reset 
		void HandleNoEvents(uint16_t flags);

		//! Remove old active events
		void ClearOldStops(int currentWp);

		//! Add stops for 'stop signs'
		void HandleAdditionalStops(std::vector<OhmioModel::TrackEvent>& eventData, int currentWp);


		//! Check if there is an active traffic light event and turn the 'active' flag off if not
		void ResetCurrentLightIfNotActive(std::vector<OhmioModel::TrackEvent> eventData);


		//! Is the last V2X message too old and we have an error?
		bool IsInputTooOld();

		//! Can we drive?
		bool IsGoodToGo();

		//! Decode the event JSON data
		bool DecodeTrafficLightEvent(const std::string& eventJson);

		//! Did we get heart bit message from interface
		bool IsHeartBitOn();

		//! If we are stopped and this is a stop sign (not traffic light) we should go
		bool IsStoppedAtStopSign(const std::string& eventJson, int stopWp);

		//! Should we send error in the message?
		bool IsStatusIndicatingError();

		//! Should we drive to the stop line or stop immediately? 
		bool ShouldDriveToStopLine();

		// distance to stop line in meters
		double GetDistanceToStopLineM();

        //! If we didn't decide to stop yet, and we cant stop in the allowed deceleration - go
		void OverrideTrafficLightByDeceleration(); 

	private:
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_wpFlagsSourse;		//!< the driving status (used for the indicators flags in file)
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;				//!< to send messages to vehicle
		std::shared_ptr<Ohmio::MessageReceiver> m_receiver;					//!< push message we send here so that they can be monitored by model
		traficLightInfo m_currentLight;						//!< information about current traffic light
		std::chrono::high_resolution_clock::time_point m_lastReceiveTime;	//!< time of the last SPAT message
		std::chrono::high_resolution_clock::time_point m_lastHeartBitTime;	//!< time of the last hart bit message
		int m_currentStatus;		//!< what is the current data we should send to drive
		int m_statusInMessage;		//!< what we sent in the last message
		int m_maxmessageAge;		//!< how old can a message be before we generate error 
		bool m_startupMode;			//!< we need to know we are starting before we send errors
		bool m_stopping;			//!< we are planning to stop for this light
		bool m_alwaysDriveToStopLine;	//!< If true keep on drive to stop line when V2X error
		double m_messageAge;		//!< time since last V2X message (mSec)
		std::map<wayPointeventFlag, stopEvent> m_stops;	//!< list of additional stop events that are not traffic light
		std::shared_ptr<TrafficLightEventData> m_trafficLightInfo;	//!< to decide what to do
		OhmioModel::TrackEvent m_specialTrafficLightEvent;			//!< an event used for setting a temporary light mainly for testing

		friend TrafficLightControllerTests; // make the test friend so that it call RunLoopOnce and not need to run the thread 

	};

}
