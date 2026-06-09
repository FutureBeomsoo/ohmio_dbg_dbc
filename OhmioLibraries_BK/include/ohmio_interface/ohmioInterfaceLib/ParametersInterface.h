#pragma once
#include "IMessageObserver.h"
#include "UtilityLib/RunInThreadForever.h"
#include "UtilityLib/Timer.h"

namespace Ohmio
{
	//! Monitor and control parameters. Periodically ask for values and keep them 
	class ParametersInterface : public IMessageObserver, public Threading::RunInThreadForever
	{
	public:

		//! Constructor 
		//
		//! @param[in] receiver - to get messages from the vehicle
		//! @param[in] outputBuffer - buffer for messages to the vehicle
		//! @param[in] pollingPeriod - Insert version request message every X milliseconds.
		//! For testing we can disable the polling by using negative value 
		ParametersInterface(std::shared_ptr<MessageReceiver> receiver, std::shared_ptr<MessageBuffer> outputBuffer, int pollingPeriod);

		~ParametersInterface();

		//! Read a parameter
		//
		//! @param[in] id - what parameter to read
		//! @param[out] valid - false if this parameter is not known
		//! @return the parameter value. 
		double GetParameterValue(int id, bool& valid);

		 
		//! Get all th parameters
		//
		//! @param[out] valid - params the list of all the parameters. 
		void GetAllParams(std::map<int, double>& params);

		//! Write a parameter
		//
		//! @param[in] id - what parameter to write
		//! @param[in] value - value to write
		//! @param[in] writeToFlash - set to false if this is part of a series of writes and not last one
		//! @return true if can write 
		bool WriteParameter(int id, double value, bool writeToFlash = true);


		//! Write a parameter
		//
		//! @param[in] params - the set of parameters to write
		//! @return true if can write 
		bool WriteMultipleParameters(const std::map<int, double>& params);

		// IMessageObserver interface
		void MessageCallback(const CAN_MSG& message) override;

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Do we want to ask about the next parameter?
		bool IsTimeToPollForVersions();

		//! Get the next parameter from the vehicle
		void PollParameters();

	private:
		int m_pollingPeriod;				//!< get a parameter value every X mSec
		std::map<int, double> m_params;		//!< parameter values
		NTiming_NS::Timer m_timer;			//!< to monitor time between events
		int m_lastPolling;					//!< last time we polled the parameters
		int m_nextParamToPoll;				//!< the next parameter we want to read
		std::shared_ptr<MessageBuffer> m_writeBuffer;	//!< to send messages to vehicle
	};

}

