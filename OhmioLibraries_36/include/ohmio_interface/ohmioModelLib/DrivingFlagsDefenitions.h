#pragma once
#include "track_utilities/WayPointDefinitions.h"
#include "commonInclude.h"
#include <array>
#include <vector>
#include <memory>

namespace OhmioModel
{
	//! Describing an event for the track
	class TrackEvent
	{
	public:
		uint32_t type;					//!< what is it. from wayPointeventFlag. 0 if wayPointeventFlag2
		uint32_t startPoint;			//!< way point number where the event becomes active
		uint32_t endPoint;				//!< way point number where the event is deactivated
		uint32_t actionPoint;			//!< way point number where the event action is happening (e.g. stop line).
		std::string json;				//!< the event information as JSON string
	};


	//! Get the status of the way point flags
	class IWpFlagsSource
	{
	public:
		//!@{
		//! Get current flags
		virtual uint16_t GetFlag1() = 0;
		virtual uint16_t GetFlag2() = 0;
		//!@}


		//! What is the current WP?
		virtual int GetWpIndex() const = 0; 

		//! How many waypoints in the track?
		virtual int GetTrackLength() const = 0;

		//! Which track are we driving?
		virtual uint64_t GetTrackId() const = 0;

		//! Get current event information
		//
		//! @param[out] eventData - All the events that are relevant to the current WP. 
		//! @return false if error
		virtual bool GetEventData(std::vector<TrackEvent>& eventData) = 0;

		//! Register to get notified when way point changes
		virtual void RegisterToWayPoint(const std::shared_ptr<IChangeObserver>& notify) = 0;

		//! Get all the events for this track
		//
		//! @param[out] eventData - All the events that are relevant to the current WP. 
		virtual void GetAllEventsForTrack(std::vector<TrackEvent>& eventData) = 0;

		//! Get all the events of a specific type for this track
		//
		//! @param[in] eventData - All the events that are relevant to the current WP. 
		//! @param[out] requestedType - the event flag we want. 
		virtual void GetAllEventsForTrack(std::vector<TrackEvent>& eventData, wayPointeventFlag requestedType) = 0;

		//! Register to get notified when track is loaded
		virtual void RegisterToTrack(const std::shared_ptr<IChangeObserver>& notify) = 0;

		//! find the nearest WP for a location. 
		//
		//! @param[in] latitude - latitude of location
		//! @param[in] longitude - longitude of location
		//! @param[in] requiredDistance - the location needs to be within this distance of the track
		//! @return the nearest WP index. If the location is too far return -1
		virtual int FindWpForLocation(double latitude, double longitude, double requiredDistance, int startWP) = 0;

		//! find the nearest WP for a location. 
		//
		//! @param[in] wpIdx - which WP
		//! @param[out] latitude - latitude of this WP
		//! @param[out] longitude - longitude of this WP
		//! @param[out] heading - heading at this WP
		virtual bool GetWpLocation(int wpIdx, double& latitude, double& longitude, double& heading) = 0;


		//! We intend to stop at a location
		//
		//! @param[in] wpIdx - the next stopping location
		virtual void SetStopDestination(int wpIdx) = 0;

		//! What mode is the vehicle now?
		//
		//! @return vehicle mode (from SYS_STATES enum)
		virtual int GetDrivingMode() const = 0;

		//! Does the current track contain unsafe features (reduced margins)?
		//
		//! @return true if unsafe, false if safe
		virtual bool IsTrackContainUnsdafeFeatures() const = 0;

        //! Is the track good for driving? All track files are good.
		//
		//! @return true if safe, false if not
		virtual bool IsTrackValid() const = 0;

		//! what is the current speed 
		//
		//! @return speed in m/sec
		virtual double GetSpeed() const = 0;


		//! Are we getting drive heart bit messages
		virtual bool IsDriveHeartbitOn() const = 0;

	};

	//! mock IWpFlagsSource for testing
	class MockWpFlagsSource :public IWpFlagsSource
	{
	public:
		MockWpFlagsSource() : m_f1(0), m_f2(0), validEvents(true), m_driveMode(0), wpIdx(0), m_speed(0){}
		~MockWpFlagsSource() {}
		virtual uint16_t GetFlag1() override { return m_f1; }
		virtual uint16_t GetFlag2() override { return m_f2; }
		void SetFlag1(uint16_t f) { m_f1 = f; }
		void SetFlag2(uint16_t f) { m_f2 = f; }
		virtual int GetTrackLength() const
		{
			return 0;
		}


		virtual bool GetEventData(std::vector<TrackEvent>& eventData) override
		{
			eventData.clear();
			eventData.insert(eventData.end(), m_eventData.begin(), m_eventData.end());
			return validEvents;
		};


		int GetWpIndex() const override
		{
			return wpIdx;
		}


		void RegisterToWayPoint(const std::shared_ptr<IChangeObserver>& ) override
		{
			// do nothing
		}


		int FindWpForLocation(double , double , double , int ) override
		{
			// do nothing
			return -1;
		}


		void GetAllEventsForTrack(std::vector<TrackEvent>& ) override
		{
			// do nothing
		}

		void GetAllEventsForTrack(std::vector<TrackEvent>& , wayPointeventFlag ) override
		{
			// do nothing
		}


		void RegisterToTrack(const std::shared_ptr<IChangeObserver>& ) override
		{
			// do nothing
		}


		virtual bool GetWpLocation(int , double& , double& , double& ) override
		{
			return false;
		}


		void SetStopDestination(int ) override
		{
			// do nothing
		}


		uint64_t GetTrackId() const override
		{
			return 0;
		}

		int GetDrivingMode() const override
		{	
			return m_driveMode;
		}

		bool IsTrackContainUnsdafeFeatures() const override
		{
			return false;
		}

		bool IsTrackValid() const override
		{
			return true;
        }	

		virtual double GetSpeed() const override
		{
			return m_speed;
		}

		virtual bool IsDriveHeartbitOn() const override
		{
			return true;
		}

	public:
		uint16_t m_f1;
		uint16_t m_f2;
		std::vector<TrackEvent> m_eventData;
		int wpIdx;
		int m_driveMode;
		bool validEvents;	//!< set to false to simulate bad event file
		double m_speed;		//!< current speed 
	};
}
