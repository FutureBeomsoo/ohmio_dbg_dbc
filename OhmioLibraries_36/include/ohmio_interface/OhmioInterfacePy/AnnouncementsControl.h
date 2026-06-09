#pragma once

#include "InterfaceManager.h"
#include "UtilityLib/RunInThreadForever.h"
#include "OhmioControlLib/AnnouncementsControl.h"
#include "OhmioTcpLib/AnnouncementsClient.h"


namespace OhmioInterfacePy
{

	class AnnouncementsControl
	{
	public:
		AnnouncementsControl(InterfaceManager& manager);
		~AnnouncementsControl();

		//! Play a message on sound system
		//
		//! @param[in] soundFile - file to play. May be full path or name of file in the location of all the announcements
		//! @param[in] device - play it internal or external speaker
		//! @param[in] skipQueue - if true play it as soon as possible don't put at the end of the queue
		void SoundAnnouncement(std::string soundFile, OhmioControl::ISoundPlayer::AnnouncementsDevices device, bool skipQueue = false);

	private:
		std::shared_ptr<OhmioTcp::ClientRunner> m_vehicleConnection;	//!< how we send requests to the vehicle
		std::shared_ptr<OhmioTcp::AnnouncementsClient> m_responseServer;		//!< how we get data from the vehicle
	};
}


