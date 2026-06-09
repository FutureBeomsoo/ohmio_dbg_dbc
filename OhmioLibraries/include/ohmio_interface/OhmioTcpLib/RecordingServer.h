#pragma once
#include "IModuleServer.h"
#include "IModuleClient.h"
#include "ohmioModelLib/commonInclude.h"
#include "ohmioModelLib/TrackRecording.h"


namespace OhmioTcp
{
	//! The server interface for recording
	//
	//! Notify the client about track, location, bus stops locations and mode.
	//! Allows the client to activate stops and to 'go' 
	class RecordingServer : public IModuleServer
	{
	public:
		RecordingServer(std::shared_ptr<Ohmio::CommunicationManager> comsManager);
		~RecordingServer();

		// IModuleServer interface
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

		//! Extract a track to a string. Public to help in testing
		static void LocationToString(const OhmioModel::TrackPointForRecording& location, std::string& answer);

		//! to help in testing
		bool IsRecording();

	protected:
		void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments, std::string& answer) override;

	private:

		//! @{
		//! Handle specific command
		void HandleStartTrack(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleEndTrack(std::string& answer) const;
		void HandleGetTrackLength(std::string& answer) const;
		void HandleGetLocation(std::string& answer) const;
		void HandleGetCurrentSpeed(std::string& answer) const;
		void HandleGetMaxSpeed(std::string& answer) const;
		void HandleGetCurrentState(std::string& answer) const;
		void HandleIsReverse(std::string& answer) const;
		void HandleUploadTrack(const std::vector<std::string>& arguments, std::string& answer) const;
		void HandleGetUploadState(std::string& answer) const;
		//! @}

	private:
		std::shared_ptr<OhmioModel::TrackRecording> m_recorder;		//!< monitors the recording
		std::shared_ptr<OhmioModel::DriveStatus> m_driveState;		//!< monitors additional information for UI
		std::shared_ptr<Ohmio::TrackUploader> m_trackUploader;		//!< for loading the recorded track
	};

}

