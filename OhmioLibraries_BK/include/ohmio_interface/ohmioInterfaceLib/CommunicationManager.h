#pragma once
#include "CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"

namespace Ohmio
{
	//! Class to construct and link all the elements needed for communication with the vehicle
	class CommunicationManager : public Threading::RunInThreadForever
	{
	public:
		//! Constructor
		//
		//! @param[in] physicalBus - the connection to the real bus. This
		//! is an input parameter to enable feeding in an emulator to 
		//! simulate the real system
		//! @param[in] v2xServerAddress - address of the V2X unit 
		//! - 192.168.137.100:5641 for the OBU 
		//! - 0.0.0.0:37008 for the OBU simulated from wireshark 
		//! - file name for simulating the OBU from a text file 
		//! - empty for no V2X
		//! @param[in] bidirectional - Is the vehicle symmetric front back or does it have preferred direction.
		//!  Use true to override the default settings from the hardware and avoid the reverse sound beepers
		//! @param[in] versionPollingPeriodMsec - send version request every X mSec. 
		//! Default is 1 second
		//! Set to -1 for testing without requests
		//! @param[in] sendHeartBit - should always be true. To simplify testing
		//! you can call with false to disable sending periodic CAN_ID_MANAGEMENT_ERROR message
		CommunicationManager(std::shared_ptr<ICanBus> physicalBus, std::string v2xServerAddress = "", bool bidirectional = true,
			int versionPollingPeriodMsec = 1000, bool sendHeartBit = true);
		~CommunicationManager();


		//! Get the receiver
		std::shared_ptr<MessageReceiver> GetMessageReceiver();

		//! Get the message receiving buffer. Probably only needed for testing
		std::shared_ptr<Ohmio::MessageBuffer> GetMessageReceiveBuffer();

		//! Get the message sending buffer. Probably only needed for testing
		std::shared_ptr<Ohmio::MessageBuffer> GetMessageSendBuffer();

		//! Get the regulator. For diagnostics when it blocks messages
		std::shared_ptr<SafetyRegulator> GetSafetyRegulator();				

		//! Get the parameter interface
		std::shared_ptr<ParametersInterface> GetParametersInterface();

		//! Get the track uploader interface
		std::shared_ptr<TrackUploader> GetTrackUploader();	

		//! Get the light translator to allow controlling the lights
		//
		//! @param[out] translator - the translator
		//! @return true if ready. If return is false you need to query again before you can use the translator
		bool GetLightToCanTranslator(std::shared_ptr<ILightToCanTranslator>& translator);


		//! Register a consumer for V2X data
		//
		//! @param[in] consumer - the new consumer
		void RegisterToV2x(std::shared_ptr<IV2XConsumer> consumer);

		//! Stop all threads 
		void Close();

		//! Get a report of the state of all watched threads
		//
		//! @param[out] report - each line is the state of a watched thread
		//! @return true if all good, false if at least one thread has not reported in time 
		bool GetWatchdogState(std::vector<std::string>& report);

		//! Add a thread to the watchdog
		void WatchThread( Threading::RunInThreadForever& thread) const;

		//! Set the monitor error from UI
		void SetMonitorError(bool monitorErrorUI);

		//! Are we connected to the vehicle 
		bool IsConnected();


		//! Is this a special platooning version
		bool IsPlatooning();
		

		//! Disable the GPS where it is unreliable
		//
		//! Do not access this function directly. Call DriveControl::EnableGps
		//! Otherwise the drive control will override the change.
		void DisbleGPS(bool disabled); 


		//! The vehicle is recording or not now
		void SetRecordingMode(bool recording);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Check that all threads are running
		void HealthCheck();

		//! get the report for a single thread
		std::string GetThreadState(std::thread::id thread);

		//! Start the controller main thread
		void StratMainThread();

	private:
		std::shared_ptr<MessageBuffer> m_messageReceiveBuffer;	//!< hold messages received from the CAN bus
		std::shared_ptr<MessageBuffer> m_messageSendBuffer;		//!< hold messages to send to the CAN bus
		std::shared_ptr<MessageReceiver> m_messageReceiver;		//!< The CAN bus monitor 
		std::shared_ptr<SafetyRegulator> m_safty;				//!< Block unsafe messages from being sent to the vehicle 
		std::shared_ptr<CanbusLoop> m_canReader;				//!< Access the actual bus
		std::shared_ptr<HardwareDetector> m_hardwareDetector;	//!< what hardware do we have?
		std::shared_ptr<IV2Xhandler> m_V2X;						//!< the V2X message receiver
		std::shared_ptr<ParametersInterface> m_params;			//!< the parameters interface
		std::shared_ptr<TrackUploader> m_trackLoader;	        //!< the track unloader interface
		std::vector<std::shared_ptr< Threading::RunInThreadForever> > m_threadsWeStrated; // list of threads that need to be stopped
		std::shared_ptr<Threading::Watchdog> m_wathDog;			//!< the watchdog thread that monitors all threads 
		bool m_sendHeartBit;									//!< should we send periodic status message? default true. turn off for testing
		bool m_monitorError;                                    //!< the value means if the monitor has an error 
		int m_watchdogNumThrads;								//!< how many threads are watched
		int m_watchdogTimeoutCount;								//!< counter for bad watchdog
		bool m_disableGps;										//!< Disable GPS 
		bool m_recording;										//!< are we recording now?
	};

}

