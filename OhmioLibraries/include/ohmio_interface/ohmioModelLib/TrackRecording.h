#pragma once

#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "UtilityLib/RunInThreadForever.h"
#include "commonInclude.h"
#include <deque>

namespace OhmioModel
{
	//! Information about a point when recording a track
	class TrackPointForRecording
	{
	public:
		TrackPointForRecording() 
		: frontLat(400), frontLong(400), frontAlt(-1000)
		, rearLat(400), rearLong(400), rearAlt(-1000)
		, heading(400), timeStamp(0), speed(0), confidence(1000)
		{} // initialize all to invalid

		double frontLat;		//!< Latitude of vehicle front
		double frontLong;		//!< Longitude of vehicle front
		double frontAlt;		//!< Altitude of vehicle front (future)
		double rearLat;			//!< Latitude of vehicle back
		double rearLong;		//!< Longitude of vehicle back
		double rearAlt;			//!< Altitude of vehicle back (future)
		double heading;			//!< Vehicle heading
		double speed;			//!< Speed at recording time
		double confidence;		//!< Confidence measure of location values < 0.8 are generaly good
		uint64_t timeStamp;		//!< Time stamp of the point. For matching data
	};

	//! An observer that collect points for a recorder track
	//
	//! The observer watch the time stamp of message to make sure we don't
	//! mix locations from different messages. When a point does not have full data 
	//! the missing data is set to invalid values.
	//! However altitude and speed messages come from different sources than the fusion
	//! and their time stamps cannot be matched so always assuming they are for
	//! the last point.
	//! Similarly heading message come from the fusion but has no timestamp.
	class TrackRecording : public Ohmio::IMessageObserver, public Threading::RunInThreadForever
	{
	public:
		TrackRecording(std::shared_ptr<Ohmio::CommunicationManager> manager);
		~TrackRecording();

		// IMessageObserver interface
		void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//! Start a recording. 
		//
		//! If already recording- continue the existing track.
		//! @param[in] trackFileName - where to save the recorded data.
		//! This is a temporary location for the row unprocessed track information
		//! @return false if already recording
		bool StartTrack(std::string trackFileName);

		//! Stop a recording
		//
		//! Will keep the existing track until a new one is started
		void EndTrack();

		//! How many points in the recorded track?
		int GetNumPointsInTrack();

		//! Get the current location of the vehicle
		//
		//! @param[out] location - the last track point.
		void GetCurrentLocation(TrackPointForRecording& location);

		//! to help in testing
		bool IsRecording();


	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:

		//! update current location
		void UpdateLocation();



		//! Write a single point to track file
		void WritePoint(std::ofstream& outfile, const  TrackPointForRecording& location);

		//! Get the new locations to write
		//
		//! lock the mutex, move the new points from m_currentLocation to newPoints and return
		void GetPointsToWrite(std::vector<TrackPointForRecording>& newPoints);

		//! Do we have all the data for a point?
		bool IsValidPoint(const TrackPointForRecording& location);

		//! Add a point to the track
		void AddPoint(const TrackPointForRecording& location);

		//! Are 2 points close so that we don't need to record the location?
		bool ArePointsVeryClose(const TrackPointForRecording& pt1, const TrackPointForRecording& location);


	private:
		TrackPointForRecording m_lastLocation;		//!< the last valid location data
		std::deque<TrackPointForRecording> m_track;	//!< The track
		bool m_RecordingNow;			//!< are we collecting points
		int m_numPoints;				//!< how many points we recorded?
		std::string m_trackFileName;	//!< location for recording points
		std::shared_ptr<DriveSystemStatus> m_speedObserver;	//!< to get the speed from
		std::shared_ptr<ILocalizationStatus> m_locationObserver;	//!< to get the speed from
		std::shared_ptr<Ohmio::CommunicationManager> m_manager;	//!< to tell the vehicle that we are recording
		std::mutex m_mutex;				//!< for locking when data is received  

	};

}

