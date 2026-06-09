#pragma once

#include "CommonInclude.h"
#include "ohmioModelLib/commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioInterfaceLib/MessageReceiver.h"

namespace OhmioControl 
{
	// Get the remote control state and react to the buttons by passing the commands to the right controller
	class RemoteHelper : public Threading::RunInThreadForever
	{
	public:
		RemoteHelper(std::shared_ptr<DriveControl> driveControl, 
			std::shared_ptr<TrafficLightController> trafficLight, std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~RemoteHelper();


	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Remote control status changed - react to buttons
		void HandleRemoteChange();

		//! Overtake pressed
		void HandleOvertakeButton();

		//! 'Go' pressed
		void HandleGoButton();


	private:
		std::shared_ptr<DriveControl> m_driveControl;			//!< to send sop, go, etc
		std::shared_ptr<TrafficLightController> m_trafficLight;	//!< to send 'go' for junctions 
		std::shared_ptr<OhmioModel::RemoteStatus> m_remoteControl;	//!< state of the remote 
		std::shared_ptr<OhmioModel::ChangeMonitor> m_remoteChange;	//!< Get notified when remote control state changes
	};
}
