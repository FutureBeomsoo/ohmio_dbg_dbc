#pragma once
#include "IModuleClient.h"
#include "ohmioModelLib/TrackRecording.h"

namespace OhmioTcp
{

	//! Events that trigger change
	enum class TrackRecordingChangeEvents
	{
		NoEvent = 0,			//!< no change
		Recording,				//!< recording / not state changed
		Location,				//!< location changed
		TrackLength,			//!< length changed
		Speed,					//!< driving speed changed
		MaxSpeed,				//!< max speed changed
		Mode,					//!< driving mode changed
		Direction,				//!< driving direction changed
		Uploading,				//!< Uploading track to vehicle state changed

		// Always add after this
		LastChangeEvent

	};

	//! Handles the client side of the bus stop interface
	class RecordingClient : public IModuleClient
	{
	public:
		RecordingClient();
		~RecordingClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

		//! Check driving forward (false) or reverse (true)
		bool IsReverseDriving();

		//! Was the last request successful
		bool GetLastAnswer();

		//! Get current place
		void GetCurrentLocation(OhmioModel::TrackPointForRecording& location);

		//! Get the recorded track length
		int GetTrackLength();

		//! Get current driving speed
		double GetVehicleSpeed();

		//! Get maximum speed
		double GetMaxSpeed();

		//! Get current vehicle state
		int GetCurrentState();

		//!@{
		//! Create a command string for sending to the server 
		std::string CreateGetTrackLengthRequest();
		std::string CreateGetSpeedRequest();
		std::string CreateGetMaxSpeedRequest();
		std::string CreateStateRequest();
		std::string CreateStartTrackRequest(std::string trackFileName);
		std::string CreateEndTrackRequest();
		std::string CreateDirectionRequest();
		std::string CreateLocationRequest();
		std::string CreateGetUploadState();
		std::string CreateUploadTrackRequest(std::string trackFile, int trackId);
		//!@}

		//! Upload the recorded track
		//
		//! Start uploading thread. 
		//! call GetUploadState to monitor the upload
		//! @param[in] track - the track file to upload 
		//! @param[in] trackId - which track is it (1/2, F/R) from enum  
		//! @return error code (0 for success)
		void UploadTrack(const std::string trackFile, int trackId);

		//! Get the state of upload.
		//
		//! @return error code 
		Ohmio::TrackUploadState GetUploadStatus();

		//! Get the progress of upload.
		//
		//! @return upload porgeress in [0, 100].  
		double GetUploadProgress();

	protected:

		// IModuleClient interface
		void SendPollingRequests() override;

	private:

		//! Got location from message
		bool HandleGetLocation(const std::vector<std::string>& arguments);

		//! Got track data from message
		bool HandleGetTrackLength(const std::vector<std::string>& arguments);

		//! Got speed data from message
		bool HandleGetCurSpeed(const std::vector<std::string>& arguments);

		//! Got max speed data from message
		bool HandleGetMaxSpeed(const std::vector<std::string>& arguments);

		//! Got max speed data from message
		bool HandleGetCurMode(const std::vector<std::string>& arguments);

		//! Got max speed data from message
		bool HandleIsReverse(const std::vector<std::string>& arguments);

		//! Got upload status from message
		bool HandleGetUploadState(const std::vector<std::string>& arguments);

		//! Got response from upload request
		bool HandleUploadTrack(const std::vector<std::string>& arguments);

	private:
		OhmioModel::TrackPointForRecording m_location; // the recorded track
		bool m_reverseDriving;	//!< Are we driving forward (true) or reverse (false)
		bool m_lastAnswerOK;	//!< was the last request successful
		int m_trackLength;		//!< how long is the track?
		int m_currentMode;		//!< vehicle mode (idle, driving. etc)
		Ohmio::TrackUploadState m_uploadState;		//!< results of uploading
		double m_currentSpeed;	//!< m/sec
		double m_maxSpeed;		//!< m/sec
		double m_uploadProgress;		//!< 0 to 1
	};

}
