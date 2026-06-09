#pragma once
#include "UtilityLib/RunInThreadForever.h"
#include "ISoundPlayer.h"
#include <deque>
#include <map>


namespace OhmioControl
{
	class AnnouncementsControl : public Threading::RunInThreadForever
	{
	public:
		AnnouncementsControl(std::shared_ptr<ISoundPlayer> player);
		~AnnouncementsControl();

		//! Set location for sound files
		//
		//! @param[in] path - location of the sound files
		void SetFilePath(std::string path);

		//! Play a message on sound system
		//
		//! @param[in] soundFile - file to play. May be full path or name of file in the location of all the announcements
		//! @param[in] device - play it internal or external speaker
		//! @param[in] skipQueue - if true play it as soon as possible don't put at the end of the queue
		void SoundAnnouncement(std::string soundFile, ISoundPlayer::AnnouncementsDevices device, bool skipQueue = false);


	protected:
		//! RunInThreadForever interface
		virtual void RunLoopOnce() override;
		virtual std::string GetDiagnosticName() override;
		virtual int GetWatchdogPeriod() override;

	private:
		//! Get the next messages to play for each device
		void GetNextSounds(std::map<ISoundPlayer::AnnouncementsDevices, std::string> &toPlay);


		//! Get the full path for the sound file
		std::string GetSoundName(const std::string& soundFile);

	private:
		std::string m_path;		//!< where to look for sound files. If empty we expect full path
		std::map<ISoundPlayer::AnnouncementsDevices, std::deque<std::string>> m_soundsToPlay;		//!< FIFO of message to sound
		std::mutex m_mutex;						//!< for locking the buffer  
		std::shared_ptr<ISoundPlayer> m_player;
	};
}
