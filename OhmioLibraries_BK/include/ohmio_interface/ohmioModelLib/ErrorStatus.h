#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"


namespace OhmioModel
{
	//! Monitor error messages
	//
	//! Register go get notified for changes or poll for status.
	//! Can get all the errors or the current ones.
	//! Can ask about a specific unit or all the units.
	//! - Initial errors are the first errors that generate emergency.
	//! This might happened in a very short period and disappeared. They come from 0x600 message
	//! - Accumulated error collects all the error flags happened after the initial error occurred.
	//! This includes all the short period errors and the current errors. They come from 0x600 message
	//! - Current errors come from the individual unit and are what is happening now.
	//! Accumulated and initial errors and warnings are accumulated. When a message arrive it needs to be 'ored'
	//! with current value
	class ErrorStatus: public Ohmio::IMessageObserver
	{
	public:

		//! Unit errors hold the state of a unit. for each bit it holds the time it was raised (if it is error) 
		typedef std::map<uint64_t, std::chrono::time_point<std::chrono::system_clock>> unitErrors;
		//! An error map holds all the unit errors
		typedef std::map<int, unitErrors> errorMap;

		//! Constructor
		//
		//! @param[in] receiver - where we get CAN messages from 
		//! @param[in] resetPeriodMSec - current errors older then this (mSec) are reset.
		//! keep the default value. This parameter is here to allow testing without waiting 3 seconds per 
		//! error.
		ErrorStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver, int resetPeriodMSec = 3000);
		~ErrorStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);

		//!@{
		//! Whats the current error / warning / reset / debug state of a unit
		//
		//! @param[in] unitId - the unit we are interested in
		//! @param[out] info - the errors for this unit 
		//! For warning and error this is a bit collection.
		//! For reset this is an enum from PICRESET_REASON or ATMEL_RESET.
		//! For debug this is 7 character ascii code.
		void GetUnitAccumulatedErrors(int unitId, unitErrors& info);
		void GetUnitCurrentErrors(int unitId, unitErrors& info);
		void GetUnitCurrentWarnings(int unitId, unitErrors& info);
		void GetUnitResetReason(int unitId, unitErrors& info);
		//!@}

		//!@{
		//! Whats the error / warning / reset / debug state of all the units
		//
		//! Get the current, initial or accumulated errors
		//! @param[out] status -  a map with key unit ID and value errors bit
		//! For reset the value is an enum from PICRESET_REASON or ATMEL_RESET.
		//! For reset the value is 7 character ascii code.
		void GetCurrentErrors(errorMap& status);
		void GetInitialErrors(errorMap& status);
		void GetAccumulatedErrors(errorMap& status);
		void GetCurrentWarnings(errorMap& status);
		void GetReaseReasons(errorMap& status);
		//!@}

		//! Get the current errors in as list of strings
		//
		//! Get the current errors
		//! @param[out] status -  a map with unit name as key and list of error strings as value
		void GetCurrentErrors(std::map<std::string, std::vector<std::string>>& status);


		//! Get debug message for a particular unit
		void GetUnitDebugMessage(int unitId, std::vector<uint8_t>& bytes);

		//! Get debug message for all units
		void GetDebugMessages(std::map<int, std::vector<uint8_t>>& status);

		//! Clear the debug messages for a unit. Call with negative value to reset all
		void ResetDebugMessages(int unitId = -1);

		//!@{
		//! How many errors are active?
		//
		//! Get the number current, initial or accumulated errors
		int GetNumCurrentErrors();
		int GetNumInitialErrors();
		int GetNumAccumulatedErrors();
		int GetNumWarnings();
		//!@}


		//!@{
		//! Clear the accumulated / initial errors
		void ResetInitialErrors();
		void ResetAccumulatedErrors();
		void ResetWarnings();
		//!@}

		//! Convert 64 bit error bits to unitErrors;
		void ErrorBitsToUnitErrors(uint64_t data, unitErrors& asErrors);

		//! Are 2 set of errors same?
		bool AreUnitsSame(const unitErrors& unit1, const unitErrors& unit2);

		//! Add the errors from newErrors to unitToUpdate
		void UpdateUnitErrors(unitErrors& unitToUpdate, const unitErrors& newErrors);

	private:
		//! Tell all the observers that the status has changed 
		void NotifyChange();

		//! Receive an error message
		void UpdateErrors(int unitId, const Ohmio::CAN_MSG& message);

		//! Update initial error
		void UpdateErrorList(int unitId, uint64_t data, bool accumulateData, errorMap& mapToUpdate);

		//! Receive a warning message
		void UpdateWarnings(int unitId, const Ohmio::CAN_MSG& message);

		//! Receive a reset cause message
		void UpdateReset(int unitId, const Ohmio::CAN_MSG& message);

		//! Receive a debug message
		void UpdateDebug(const Ohmio::CAN_MSG& message);

		//! Receive a system report
		void HandleSysErrorReport(const Ohmio::CAN_MSG& message);

		//! Handle the special mixed error message
		void HandleMixedLocationMotorError(uint64_t errorBits, errorMap& mapToUpdate);

		//! Count of errors
		int GetErrorCount(errorMap& errors);

		//! Clear current errors that are old
		void ClearOldErrors();

		//! Does a unit have no resent error bits. If so it should be reset 
		bool IsUnitErrorsOld(int unitId, const std::chrono::time_point<std::chrono::system_clock>& now);

		//! special case for the motor error
		void HandleMotorErrorMessage(const Ohmio::CAN_MSG & message);

	private:
		std::mutex m_mutex;								//!< for locking the maps in multi threaded  
		std::map<uint64_t, int> m_errorMessageMap;		//!< convert error message to unit ID
		std::map<uint64_t, int> m_warningMessageMap;	//!< convert warning message to unit ID
		std::map<uint64_t, int> m_resetMessageMap;		//!< convert reset message to unit ID
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		errorMap m_currentErrors;		//!< Current error status of all units
		errorMap m_currentWarnings;		//!< Current warning status of all units
		errorMap m_initialErrors;		//!< initial errors that caused emergency
		errorMap m_accumulatedErrors;	//!< all errors that caused emergency
		errorMap m_resetReasons;			//!< reset reason for each unit
		std::map<int, std::vector<uint8_t>> m_debugMessage;		//!< debug message for each unit
		bool m_mixMotorErrors;		//!< are motor errors sent as part of localization error 
		int m_resetCurrentErrorPeriod;		//!< reset current errors if no data in this period (mSec)
		std::shared_ptr<Ohmio::NameTranslator> m_nameHelper;		//!< for translating errors to string

	};
}


