
#pragma once
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"

namespace OhmioControl
{
	//! General system management (reset, shutdown, etc)
	class ObstacleControl : public Threading::RunInThreadForever
	{
	public:

		ObstacleControl(std::shared_ptr<Ohmio::MessageBuffer> writeBuffer, 
			std::shared_ptr<Ohmio::MessageReceiver> messageReciever);

		~ObstacleControl();

		//! Temporary shrink the safety margins to allow passing near static object
		//
		//! @param[in] time - time (seconds) to shrink the margins for
		void ShrinkMargins(int time);


	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;
	private:
		//! Sound alarm if obstacle in envelop
		void BeepIfNeeded();

		//! beep
		void SoundAlarm();

		//! What should be the time (mSec) between beeps
		int GetDingPeriodForDistance(double distance);

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;		//!< for writing to the vehicle
		std::shared_ptr<Ohmio::MessageReceiver> m_messageReciever;	//!< for feeding back the margin message to model
		std::shared_ptr<OhmioModel::DriveStatus> m_driveStatus;		//!< to know if we are left or right driver
		std::shared_ptr<OhmioModel::ObstacleStatus> m_obstacleStatus;		//!< status of the obstacle system
		std::chrono::high_resolution_clock::time_point m_lastDingime; //!< last time we made a warning sound 
	};
}

