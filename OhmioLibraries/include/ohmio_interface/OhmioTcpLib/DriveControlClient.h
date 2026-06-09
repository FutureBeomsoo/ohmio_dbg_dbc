#pragma once
#include "IModuleClient.h"

namespace OhmioTcp
{
	//! Handles the client side of the bus stop interface
	class DriveControlClient : public IModuleClient
	{
	public:
		DriveControlClient();
		~DriveControlClient();

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

		//!@{
		//! Create a command string for sending to the server 
		std::string CreateStartRequest() const;
		std::string CreateGoRequest() const;
		std::string CreateStopRequest() const;
		std::string CreateRecoverRequest() const;
		std::string CreateStopAtWpRequest(int wayPointIndex) const;
		std::string CreateStopAtLocationRequest(double latitude, double longitude, double distance) const;
		std::string CreateTrackRequest(int trackNumber, bool forward) const;
		std::string CreateSpeedRequest(double speed) const;
		std::string CreateGetModeRequest() const;
		std::string CreateGetTrackRequest() const;
		std::string CreateGetSpeedRequest() const;
		std::string CreateOvertakeRequest(double offset, bool revert) const;
		//!@}

		//!@{
		//! Getters
		bool GetLastAnswer() const;
		bool GetDirection() const;
		int GetPath() const;
		double GetMaxSpeed() const;
		int GetDrivingMode() const;
		//!@}

		//!@{
		//! Can the vehicle perform a command
		bool CanStart() const;
		bool CanGo() const;
		bool CanStop() const;
		bool CanSelectTrack() const;
		bool CanOvertake(bool revert) const;
		//!@}


	protected:
		// IModuleClient interface
		void SendPollingRequests() override;

	private:


		//!@{
		//! Handle reply from server
		bool HandleGetMode(const std::vector<std::string>& arguments);
		bool HandleGetTrack(const std::vector<std::string>& arguments);
		bool HandleGetSpeed(const std::vector<std::string>& arguments);
		//!@}



	private:
		double m_maxSpeed;			//!< sped in m/sec
		int m_mode;					//!< drive mode
		int m_trackId;				//!< track used
		bool m_forward;				//!< true for driving forward
		bool m_lastAnswerOK;		//!< was the last request successful
		
		//std::mutex m_mutex;		//!< for locking the list of stops  

	};

}
