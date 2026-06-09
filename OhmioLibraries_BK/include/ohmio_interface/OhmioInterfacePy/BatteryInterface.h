#pragma once


#include "InterfaceManager.h"
#include "ohmioModelLib/BatteryStatus.h"

namespace OhmioInterfacePy
{
	//! The power API see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1112211506/API+Functions?focusedCommentId=1121419265
	class BatteryInterface
	{
	public:
		BatteryInterface(InterfaceManager& manager);
		~BatteryInterface();

		//! Get the current status of the main buttery
		void GetMainBatteryData(OhmioModel::MainBatteryState& data);

		//! Get the current status of a (general) battery
		void GetBatteryData(OhmioModel::Batteries batteryToGet, OhmioModel::GeneralBatteryState& data);

	private:

	};

}

