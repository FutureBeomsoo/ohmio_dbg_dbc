#pragma once
#include <map>
#include <vector>
#include <string>

namespace Ohmio
{
	//! Helper class for translating enums to strings
	class NameTranslator
	{
	public:
		NameTranslator();
		~NameTranslator();

		//! Convert unit ID to name string
		std::string GetUnitName(int unitId) const;

		//! Convert errors to strings
		std::string GetUnitErrorStrings(int unitId, uint64_t errorCode) const;

		//! Convert errors to strings
		std::string GetUnitWarningStrings(int unitId, uint64_t errorCode) const;

		//! Convert errors to strings
		std::string GetUnitResetStrings(int unitId, uint64_t errorCode) const;

		//! Get system state as a string
		std::string GetModeName(int state) const;

		//@{
		//! Get enum meaning as list of string
		void GetSysStates(std::map<int, std::string>& sysStates) const;
		void GetPathNames(std::map<int, std::string>& pathNames) const;
		void GetSysKeys(std::map<int, std::string>& keyNames) const;
		void GetEpbStatusNames(std::map<int, std::string>& names) const;
		void GetgpsQualityNames(std::map<int, std::string>& names) const;
		void GetTrafficLightStatusNames(std::map<int, std::string>& names) const;
		void GetBmsStatusNames(std::map<int, std::string>& names) const;
		void GetBmsErrorNames(std::map<int, std::string>& names) const;
		void GetMotorStatusNames(std::map<int, std::string>& names) const;
		void GetBatteryChargingNames(std::map<int, std::string>& names) const;
		//@}

		//! Convert error code to bit
		uint64_t ErrorCodeToBit(int code);

	private:
		//! build m_UnitNames
		void CreateUnitNameTable();

		//! build error names table
		void CreateErrorsTable();

		//! build waring names table
		void CreateWarningsTable();

	private:
		std::map<uint64_t, std::string> m_UnitNames;	//!< table for converting IDs to names
		std::map<uint64_t, std::map<uint64_t, std::string>> m_ErrorNames;	//!< table for converting error bits to names
		std::map<uint64_t, std::map<uint64_t, std::string>> m_WarningNames;	//!< table for converting waring bits to names

	};


}
