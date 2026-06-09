#pragma once

#include "InterfaceManager.h"
#include "ohmioModelLib/LocalizationStatus.h"

namespace OhmioInterfacePy
{
	//! UWB data point. the anchor ID and 2 values (either 2 distances or lat, long)
	class UwbDataPoint
	{
	public:
		int id;	//!< anchor id
		double first; //!< first value ditance to front or latitude
		double second; //!< second value ditance to reat or longitude
	};

	//! The localisation API see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1112211506/API+Functions?focusedCommentId=1121419265
	class LocalizationInterface
	{
	public:
		LocalizationInterface(InterfaceManager& manager);
		~LocalizationInterface();

		//! Get the current status of GPS location
		void GetLocationData(OhmioModel::LocationData& data);

		//! Get the current status of the fusion unit
		void GetFusionData(OhmioModel::FusionData& data);

		//! Get the (fixed) locations of all the known UWB anchors
		void GetUwbAnchorsLocations(std::vector<UwbDataPoint>& locations);

		//! Get the distances to all current UWB anchors
		void GetUwbAnchorsDistances(std::vector<UwbDataPoint>& distances);


	private:

	};
}

