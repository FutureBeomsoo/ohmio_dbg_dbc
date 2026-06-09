#pragma once
#include "IModuleClient.h"

namespace OhmioTcp
{
	class AnnouncementsClient : public IModuleClient
	{
	public:
		AnnouncementsClient();
		~AnnouncementsClient();


		//! Create a request to play a message on sound system
		//
		//! @param[in] soundFile - file to play. May be full path or name of file in the location of all the announcements
		//! @param[in] device - play it internal or external speaker
		//! @param[in] skipQueue - if true play it as soon as possible don't put at the end of the queue
		//! @return the message to send to the server for playing the announcement
		std::string CreateSoundRequest(std::string soundFile, int device, bool skipQueue = false);

		// IModuleClient interface
		virtual void ProcessMessageFromClient(int command, const std::vector<std::string>& arguments) override;
		std::string GetModuleName() const override;
		virtual ModuleNames GetModuleId() const override;

	protected:
		// IModuleClient interface
		void SendPollingRequests() override;

	private:

	};
}


