#pragma once

#include "commonInclude.h"
#include <set>
namespace OhmioTcp
{
	//! This is the 'chat room' that is used for the communication
	//
	//! Manages a list of all the participant (clients) and send messages to all,
	//! Note that it relies on the participants to join and leave the room.
	class Room
	{
	public:
		Room();
		~Room();


		//! A participant is joining the conversation
		//!
		//! should be notified on all new messages
		//! @param[in] participant - the new participant
		void join(Participant_ptr participant);

		//! A participant is leaving the conversation
		//!
		//! should NOT be notified from now on
		//! @param[in] participant - the leaving participant
		void leave(Participant_ptr participant);

		//! Send a message to all participants
		//!
		//! @param[in] msg - the message to send
		//! @param[in] sender - the participant that sent the message. So that
		//! We don't send it back. If the message originated in the vehicle the 
		//! sender is null.
		//! should probably remove when we get rid of CAN messages here
		void broadcast(std::string msg, Participant_ptr sender = NULL);

	private:
		std::set<Participant_ptr> m_participants;

	};

}

