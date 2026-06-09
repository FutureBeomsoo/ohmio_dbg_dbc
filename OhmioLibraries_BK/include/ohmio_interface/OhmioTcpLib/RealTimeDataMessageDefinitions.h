#pragma once

namespace OhmioTcp
{
	//! helper for real time data TCP communication
	namespace RealTimeDataMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			GetStatusData,			//!< Get the status
			GetErrorData,			//!< Get the errors
			GetVersionData,			//!< Get the versions

			// always add above this line
			last
		};


		//! A description of part of unit i.e. "name', "volt"
		//typedef std::pair<std::string, std::string> UnitDescriptor;

		//! The units of a data. i.e. "symbol": "V", "name": "volts" , "type" : "double", etc
		typedef std::map<std::string, std::string> Description;

		//! a value with its description
		typedef std::pair<double, Description> Property;

		//! the key is the value name (i.e 'voltage') the value is the data (i.e. 10 volts)
		typedef std::map<std::string, Property> PropertyMap;

		//! the key is the topic name (i.e 'battery') the value is a map of all the properties
		typedef std::map<std::string, PropertyMap> TopicMap;

		//! What type of data we are dealing with
		enum class DataTypes
		{
			status,		//!< the different status information
			errors,		//!< error information
			versions,	//!< version information

			// Always add above this
			last
		};

		//! Observer pattern
		class IChangeObserver
		{
		public:
			virtual void OnChange(DataTypes whatChanged, std::string topic) = 0;
		};


	};
}


