#pragma once
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"


namespace OhmioControl
{


	//! Handle changing lane manouver
	//
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/2248409089/Track+deviation+for+static+obstacles
	//! Sends periodic change messages to cause the change.
	//! Keep track of our location in the change to enable / disable changes
	class LaneChanger : public Threading::RunInThreadForever
	{
	public:
		//! constructor
		//
		//! @param[in] sendBuffer - write change messages to this buffer
		//! @param[in] wpSource - used to follow our progress. May also use to set disable flag
		//! on part of the track (future feature)
		//! @param[in] maxWpJump - if the location change by more than this
		//! we move away and should reset the state machine. Should always 
		//! use the default. We can override this for testing
		//! 25 WP is 5m which is much more that we drive at 10 m / sec
		LaneChanger(std::shared_ptr<Ohmio::MessageBuffer> sendBuffer,
			std::shared_ptr<OhmioModel::IWpFlagsSource> wpSource, int maxWpJump = 25);
		~LaneChanger();

		//! Can we change lane now?
		bool CanChangeLanes();

		//! Are we not on the main track (somewhere in the overtake maneuver)? 
		bool IsOffTrack();

		//! Are we on the next lane and can return to the main track?
		bool CanReturn();

		//@{
		//! Initiate / return from changing lanes
		//
		//! @param[in] distanceToNextLane - distance (m) to shift. 
		//! Negative is changing to the left
		//! @param[in] currentSpeed - speed (m/Sec) we are driving now.
		//! This controls how many WP ahead we will start the transition.
		//! If the speed is very low we are probably stopped so we need 
		//! to start the transition now. Otherwise we start 3 way points ahead to 
		//! give all the systems time to get the message.
		//! @return true if can initiate the change
		bool Overtake(double distanceToNextLane, double currentSpeed);
		bool ReturnFromLane(double currentSpeed);
		//@}


	protected:
		// Inherited via RunInThreadForever
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		virtual int GetWatchdogPeriod() override;

	private:
		//! Status of lane changing 
		enum class LaneTransitionState
		{
			OnTrack = 0,	//!< we are on the main track
			Transitioning,	//!< we are moving between lanes
			OnDeviationTrack,		//!< We are on the next lane
			Returning,		//!< we are going back to our lane

			// Always add before this line
			Last
		};

		//! Do we send?
		bool NeedToSendCanMessage();

		//! Send lane change massage
		void SendChangeMessage();


		//! Check our progress
		void UpdateState();

		//! Which WP should start the change?
		void CalculateTransitionStart(double currentSpeed);

		//! Which WP should end the change?
		void CalculateTransitionEnd();

		//! Decide on the acceleration profile to use
		void SetAcceleration(double speed);

		//! limit offset by track limits keeping direction from track
		void LimitOvertakeOffset(double distanceToNextLane);

		//! Get the rules from the track
		void UpdateTrackLimits();

		//! get the event information for overtaking
		bool ReadEventInformation(const std::string& json);

		//! Get the data out of the JSON string
		bool DecodeEventJson(const std::string& json);

		//! Did the track change? If so we need to reset
		bool IsTrackChanged();

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for writing to the vehicle
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_wpSource;	//!< to know where we are
		LaneTransitionState m_currentState;		//!< are we on track or changeling or ?
		double m_acceleration;					//!< the acceleration to use for calculation			
		double m_velocity;						//!< how fast should we drive when changing lane			
		double m_offset;						//!< distance between lanes ( < 0 is to the left)			
		double m_maxOffset;						//!< how much are we allowed to deviate from track
		uint64_t m_trackId;						//!< the track we are on
		int m_wpOfTransition;					//!< the WP to start the transition 
		int m_wpEndTransition;					//!< when do we stop the transitioning
		int m_currentWP;						//!< WP number
		int m_maxWpJumpAllowed;					//!< if we jump more WP we should reset the state machine
		int m_onTrackSendCounter;				//!< counter for sending 'on track' just a few times
		bool m_overtakeAllowed;					//!< does the track allow overtaking
	};

}
