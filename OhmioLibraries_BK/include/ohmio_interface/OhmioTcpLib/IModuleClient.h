#pragma once
#include "commonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioModelLib/ChangeMonitor.h"

namespace OhmioTcp
{
	//! an interface for a client to handle a specific module
	class IModuleClient : public Threading::RunInThreadForever
	{
	public:
		IModuleClient();
		virtual ~IModuleClient();

		//! Process a message from the vehicle to the client
		//
		//! @param[in] command - the message meaning. An enum of the right type for the module
		//! @param[in] arguments - list of arguments for the command (may be empty)
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) = 0;

		//! Get name. Note that the name needs to be the same as in IModuleServer
		virtual std::string GetModuleName() const = 0;

		//! How do we send messages to the server
		void SetMessegeTarget(std::shared_ptr<Client> target); // tell the module how to send messages

		//! Wait for a change in the status
		//
		//! Sleeps until a change is notified or timeout passed
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);


	protected:
		// RunInThreadForever
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		virtual int GetWatchdogPeriod() override;

		//! Poll the server for all the information we want to keep
		virtual void SendPollingRequests() = 0;

		//! Send a request
		void SendToTarget(std::string message);

		//! The vehicle state has changed. Notify users
		void UpdateChange(int whatChanged);


		//! Create a request string (no parameters)
		std::string CreateRequestString(int command) const;

	protected:

	private:
		std::shared_ptr<OhmioModel::ChangeMonitor> m_ChangeMonitor;	//!< Get notified when data changed
		std::shared_ptr<Client> m_target;	//!< Send requests using this client
		std::mutex m_mutex;					//!< for locking while changing targets  

	};
}

