#pragma once

#include <map>
#include <memory>

namespace OhmioModel
{
	//! What are we converting
	enum class UnitToConvert
	{
		temperature,			//!< C vs F
		speedMmSec,				//!< speed between mm/sec and MPH
        odometer,				//!< Odometer from m to km or miles

		// always add above this
		last
	};

	//! units to use for speed
	enum class SpeedUnits
	{
		mmSec,			//!< the original unit of mm/sec
		kmh,			//!< km / h
		mph,			//!< miles / h

		// always add above this
		last
	};

	//! units to use for temperature
	enum class TemperatureUnits
	{
		celsius,		//!< Celsius 
		fahrenheit,			//!< Fahrenheits

		// always add above this
		last
	};


	//! Helper class for converting a value for display. 
	//
	//! There will be derived classes for the different units to convert and 
	//! to the different targets i.e. speedConverterKmH converts speed to Km/h
	class IUnitConverter
	{
	public:
		IUnitConverter();
		virtual ~IUnitConverter();

		//! Create a converter
		//
		//! @param[in] whatToconvert - what do we want to convert (speed, temperature, etc.)
		//! @param[in] unitToUse - what unit do we want (this comes from the correct enum)
		//! @return the appropriate converter
		static std::shared_ptr<IUnitConverter> CreateConverter(UnitToConvert whatToconvert, int unitToUse);

		//! Convert a value from the vehicle to the right units for display
		virtual double ConvertValueFromVehicle(double fromVehicle) = 0;

		//! Convert a value from the display to the right units for the vehicle
		virtual double ConvertValueToVehicle(double toVehicle) = 0;

		//! Get the unit to display
		virtual std::string GetUnit() = 0;

	private:
		static std::shared_ptr<IUnitConverter> CreateTemperatureConverter(TemperatureUnits unitToUse);
		static std::shared_ptr<IUnitConverter> CreateSpeedConverter(SpeedUnits unitToUse);
        static std::shared_ptr<IUnitConverter> CreateOdometerConverter(SpeedUnits unitToUse); //!< We use the speed to decide of km or miles

	};



	//! Helper class for converting to display units
	//
	//! Display temperature in C or F
	//! display speed in mm/sec, Km/H or MPH
	class DisplayConversion
	{
	public:
		//! construct a converter
		//
		//! @param[in] speed - units to use for speed
		//! @param[in] temp - units to use for temperature
		DisplayConversion(SpeedUnits speed, TemperatureUnits temp);
		~DisplayConversion();


		//! Convert a value from the vehicle to the right units for display
		double ConvertValueFromVehicle(double fromVehicle, UnitToConvert unit);

		//! Convert a value from the display to the right units for the vehicle
		double ConvertValueToVehicle(double toVehicle, UnitToConvert unit);


		//! Get the unit to display
		std::string GetUnit(UnitToConvert unit);

	private:
		// get the desired converter
		std::shared_ptr<IUnitConverter> GetConverter(UnitToConvert unit);

	private:
		std::map<UnitToConvert, std::shared_ptr<IUnitConverter>> m_Converters;
	};

	//! Empty converter to avoid crushing if things go wrong
	class DoNothingUnitConverter : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Temperature converter for deg Celsius
	class TemperatureConverterCelsius : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Temperature converter for deg Fahrenheit
	class TemperatureConverterFahrenheit : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Speed converter for mm / sec
	class SpeedConverterMmSec : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Speed converter for Km / hour
	class SpeedConverterKph : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Speed converter for miles / hour
	class SpeedConverterMph : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};


	//! Odometer  converter for KM
	class OdometerConverterKm : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

	//! Speed converter for miles
	class OdometerConverterMiles : public IUnitConverter
	{

	public:
		double ConvertValueFromVehicle(double fromVehicle) override;
		double ConvertValueToVehicle(double toVehicle) override;
		std::string GetUnit() override;
	};

}
