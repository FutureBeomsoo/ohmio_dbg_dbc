#pragma once
#include "CommonInclude.h"
#include <mutex>
#include <thread>
#include "IMessageObserver.h"
#include "canbus/dbc_CAN.h"
#include "track_utilities/WayPointDefinitions.h"
#include "track_utilities/TrackFileLoader.h"

namespace Ohmio
{

    enum class trackId
	{
		one_forword,
		one_reverse,
		two_forword,
		two_reverse,

		last
	};

	//! Upload a track using the existing CAN protocol
	//
	//! not unit tested. Required drive control code on the other side
	class TrackUploader : public IMessageObserver
	{
	public:
		TrackUploader(std::shared_ptr<MessageReceiver> receiver, std::shared_ptr<MessageBuffer> sender);
		~TrackUploader();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Upload the recorded track
		//
		//! Start uploading thread. 
		//! call GetUploadState to monitor the upload
		//! @param[in] track - the track file to upload 
		//! @param[in] destination - which track is it (1/2, F/R) from enum  
		//! @return true if can start uploading. Call GetStatus() to get more details of error
		bool UploadTrack(std::string track, int destination);

		//! Get the status of upload.
		//
		//! @return current status 
		Ohmio::TrackUploadState GetStatus();


		//! Get the progress of upload.
		//
		//! @return progress in [0, 1] range 
		double GetProgress();

		//! Are we done? Return true if not uploading
		bool IsFinished();


	private:
		//! The thread that load a track
		void LoadingThread();

		//! Set progress and state to 'start upload'
		void InitState();

		//! verify the track before trying to upload
		bool IsTrackGoodForUpload();

		//! Do the upload
		void DoUpload();

		//! send a header request first
		void sendHeaderRequest();

		//! Got a drive controller ack message
		void ReciveDriveAckMessage(const CAN_MSG& message);
		void ReciveVersionMessage(const CAN_MSG& message);
		void ReciveWPMessage(const CAN_MSG& message);
		
		//! Fill in message buffer
		void FillInBuffer();

		//! check ACK from controller
		bool CheckAck();

		//! process wait state
		void ProcessWaitState();

		//! process header state
		void ProcessHeaderState();

		//! process waypoint state
		void ProcessWaypointState();
	
		//! process idle state
		void ProcessIdleState();

		//! get track file name
		std::string GetTrackFileName(TrackFileLoader& reader);
		
		//! send out the message
        void PushMessage();

		//! lock and update progress
		void UpdateProgress(double progress, Ohmio::TrackUploadState state);

		//! What's the max allowed track length? 
		uint32_t GetMaxTrackLengthAllowed();

		//! upload to shared folder for obstacle
		void UpdateObstacleFiles();

	private:
		std::mutex m_mutex;				//!< for locking access while thread running
		std::thread	m_loadingThread;	//!< the thread for loading track
		std::shared_ptr<MessageBuffer> m_sender; //!< how we send messages to the vehicle
		Ohmio::TrackUploadState m_status;	//!< current status
		double m_progress;					//!< progress in [0, 1]
		std::string m_trackFile;			//!< track file we are loading
		int m_destination;					//!< Where we load to (1F, 1R, 2F, 2R)
		std::vector<TrackAckMsg_t> m_vAckMsg; //!< response from drive controller	
		std::vector<TrackAckMsg_t> m_vAckMsgBuffer;//!< fill in message buffer from m_vAckMsg
		int m_index_req; 					//!<request track id index
		Ohmio::CAN_MSG m_in_canMsg;         //!<received canbus msg 
		Ohmio::CAN_MSG m_out_canMsg;        //!<canbus msg to be sent
		std::vector<OHMIO_WAY_POINT_DRIVE_t> m_trackData;  //!< all track data
		size_t m_loopCount;                 //!<loop counter
		bool m_bFinishedSendingFile; 	    //!<already finished sending the file 
		bool m_gotAckNack;					//!< flag indicating we got a reply
		bool m_finished;					//!< true when finished loading
		size_t m_indexOfVec;				//!< index of track data vector
		trackId m_longTrackId;				//!< which track can be long?

		OHMIO_PATH_INFO_t stu_pathInfo;
		OHMIO_WAY_POINT_LOC_t stu_LocWP;
		OHMIO_WAY_POINT_DRIVE_t stu_DriveWP;
		OHMIO_PATH_INFO_t stu_pathInfo_MD5;
		WAY_POINT_DRIVE_t stu_DriveWP_MD5;	
	};

}
