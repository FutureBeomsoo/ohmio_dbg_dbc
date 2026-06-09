#pragma once

//#include "ohmioModelLib/DrivingLightStatus.h"
#include "OhmioControlLib/DrivingLightsControl.h"
#include "InterfaceManager.h"
//#include "ohmioModelLib/ChangeMonitor.h"

//! Library for Pybind11 interface for the Ohmio vehicle
namespace OhmioInterfacePy
{
	//! Control / monitor the lights
	class LightInterface
	{
	public:
		//! constructor
		//
		//! @param[in] manager - how do we connect top the hardware
		//! @param[in] hardwareDetectorTimeoutSeconds - timeout before we give up the hardware type detection
		LightInterface(InterfaceManager& manager, int hardwareDetectorTimeoutSeconds);
		~LightInterface();

		//! Indicate (none, left, right, both). 
		void SetIndicators(OhmioControl::DrivingLightsControl::IndicatorStatus whatToDo);

		//! What are we indicating now?
		OhmioControl::DrivingLightsControl::IndicatorStatus GetIndicators();

		//! Set the mode to use. Are we driving in day or night, etc
		void SetLightingMode(OhmioControl::DrivingLightsControl::LightMode whatToDo);

		//! Are we driving in day or night, etc
		OhmioControl::DrivingLightsControl::LightMode GetLightingMode();

		//! Turn a light on / off for testing
		//
		//! Ignored if not in test mode
		//! @param[in] lightList - list of lights to turn on / off
		//! @return false if cannot set the light (not in test)
		bool SetDrivingLightForTest(
			 std::vector<std::pair<Ohmio::DrivingLightItem, bool>>& lightList);

		//! Turn a light on / off 
		//
		//! Should only be used for internal light or other non driving lights
		//! @param[in] lightId - light to control
		//! @param[in] on - should it be on or off
		//! @return false if cannot set the light (not in test)
		bool SetLight(Ohmio::DrivingLightItem lightId, bool on);


		//! Wait for a change in the lights
		//
		//! Sleeps until a change is notified or timeout passed
		//! @param[in] timeoutmSec - timeout in milliseconds
		//! @return true if there was a change
		bool WaitForChange(int timeoutmSec);

	private:
	};

}
