#pragma once

#include <string>

namespace OhmioControl
{
	class ISoundPlayer
	{
	public:
		ISoundPlayer() {};
		~ISoundPlayer() {};

		enum class AnnouncementsDevices
		{
			internal = 0,
			external,

			// Always add above this line
			lastAnnouncement
		};

		//! Play a sound on a device
		//
		//! @param[in] soundFile - the sound to play
		//! @param[in] device - the output device to use
		virtual void PlayMessage(const std::string& soundFile, AnnouncementsDevices device) = 0;


	private:

	};

}
