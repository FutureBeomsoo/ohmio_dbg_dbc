#pragma once
#include "version.h"
#include <string>
#include <vector>

//! preventing illigal copy of our software
namespace LicenceUtils
{
	//! Licencing. Read a licence file and enable / disable programs
	class HmiLicence
	{
	public:
		//! constructor
		//
		//! @param[in] useFullHarwareId - Do we use full hardware id (true)
		//! or just the mimimum that is stable in running the tests on unspecified hardware (false)
		HmiLicence(bool useFullHarwareId = true);
		~HmiLicence();

		//! Read a licence file
		//
		//! @param[in] licenceFilePath - path to the input encrypted licence file
		void ReadLicence(const std::string& licenseFilePath);

		//! Create and encrypt a licence file
		//
		//! @param[in] sourceOptionsFile - path to the source unencypted licence file
		//! @param[in] licenceFilePath - path to the output encrypted licence file
		//! @param[in] hardwareId - the hardware signiture to use. If empty use the current computer
		void CreateLicenceFile(const std::string& sourceOptionsFile, const std::string& licenceFilePath, std::string hardwareId = "");


		//! Are we alowed to run?
		//
		//! @param[in] licenceFilePath - path to the encrypted licence file
		//! @param[in] programName - the program to check
		//! @return - true if can run
		bool IsAuthorised(const std::string& programName);


		//! Get the customer for this licence
		std::string GetCustomerName();


	private:
		//! Read and extruct data from the licence file
		void ExtracutLicence(const std::string& licenseFilePath);

		//! extract data from a single line
		void ExtractFromLine(const std::string& line);

		//! Make sure the options file have the correct signatures
		void AppendSignatureIfNeeded(const std::string& optionsFile);

		//! Does the stream contain the needed signature?
		bool FindSignature(const std::stringstream& optonsStream);

		// Get the semi random signature
		void GetLicenceSignatureString(std::string& signature);

		private:
			std::vector<std::string> m_alowedPrograms;		//!< list of program that can run
			std::string m_customer;							//!< the customer name	
			bool m_valid;									//!< is the licence valid
			bool m_AllAllowed;								//!< If true we allow all programs
			std::string HmiSignature;						//!< the signiture we put in the licence file
			bool m_useFullHarwareId;						//!< full ID or just limited for testing
	};
}

