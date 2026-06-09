#pragma once
#include "ISoundPlayer.h"

#include "ISoundPlayer.h"

namespace OhmioControl
{
	class SoundPlayerGstreamer : public ISoundPlayer
	{
	public:
		SoundPlayerGstreamer();
		~SoundPlayerGstreamer();

		//ISoundPlayer interface
		virtual void PlayMessage(const std::string& soundFile, AnnouncementsDevices device) override;


	private:
		std::string GetDeviceString(ISoundPlayer::AnnouncementsDevices device);
	};

}


