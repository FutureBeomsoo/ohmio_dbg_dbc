#pragma once

#include "InterfaceManager.h"
#include "OhmioTcpLib/RecordingClient.h"

namespace OhmioInterfacePy
{
	// interface for track recording
	class RecordingInterface
	{
	public:
		RecordingInterface(InterfaceManager& manager);
		~RecordingInterface();

		//! Start a recording. 
		//
		//! If already recording- continue the existing track.
		//! @param[in] trackFileName - where to save the recorded data.
		//! This is a temporary location for the row unprocessed track information
		void StartTrack(std::string trackFileName);

		//! Stop a recording
		//
		//! Will keep the existing track until a new one is started
		void EndTrack();


		//! Get the current location of the vehicle
		OhmioModel::TrackPointForRecording GetCurrentLocation();

        //! Get the recorded track length
		int GetTrackLength();

		//! Get the current speed
		double GetCurSpeed();

		//! Get the Maximum speed
		double GetMaxiSpeed();

        //! Get the current mode of vehicle
		int GetCurrentState();

		//! Get current state as name string
		std::string GetCurrentStateName();

		//! Wait for a change in the status
		//
		//! Sleeps until a change is notified or timeout passed
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);

		//! Upload the recorded track
		//
		//! Start uploading thread. 
		//! call GetUploadState to monitor the upload
		//! @param[in] track - the track file to upload 
		//! @param[in] trackId - which track is it (1/2, F/R) from enum  
		void UploadTrack(std::string track, int trackId);

		//! Get the state of upload.
		//
		//! @return error code 
		Ohmio::TrackUploadState GetUploadStatus();

		//! Get the progress of upload.
		//
		//! @return upload porgerss in [0, 100].  
		double GetUploadProgress();

        //! Check driving forward (false) or reverse (true)
		bool IsReverseDriving();

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::RecordingClient> m_responseServer;		//!< how we get data from the vehicle
	};
}

