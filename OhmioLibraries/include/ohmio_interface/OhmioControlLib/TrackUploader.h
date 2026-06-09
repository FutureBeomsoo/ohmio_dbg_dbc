#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include "ohmioInterfaceLib/CommonInclude.h"


// This is not used. Maybe in the future we will have a proper
// transfer mechanism for the CAN bus and we woill use it
namespace OhmioControl
{
	//! Information about a point on a track for the vehicle
	class TrackPoint
	{
	public:
		TrackPoint()
			: Latitude(0), Longitude(0), Altitude(0)
			, heading(0), speed(0), lookAhead(0), flags1(0), flags2(0)
		{} // initialize all to invalid

		double Latitude;		//!< Latitude of vehicle 
		double Longitude;		//!< Longitude of vehicle 
		double Altitude;		//!< Altitude of vehicle (future)
		double heading;			//!< Vehicle heading
		double speed;			//!< Speed to drive at
		uint16_t lookAhead;		//!< how many way points to look forward when driving
		uint64_t flags1;		//!< 64 flags
		uint64_t flags2;		//!< more flags
	};

	//! Upload track to the vehicle
	class TrackUploader
	{
	public:
		TrackUploader(std::shared_ptr<Ohmio::MessageReceiver> receiver,
			std::shared_ptr<Ohmio::MessageBuffer> sender);
		~TrackUploader();

		//! Upload a track to the vehicle
		int UploadTrack(const std::vector<TrackPoint>& track, int trackId) const;

	private:
		//! Convert the track to stream of bytes to transfer to the bus
		void ConvertToByteArray(const std::vector<TrackPoint>& track, std::vector<uint8_t>& asBytes) const;

	private:
		std::shared_ptr<Ohmio::MessageReceiver> m_receiver; //!< how we receive messages from the vehicle
		std::shared_ptr<Ohmio::MessageBuffer> m_sender; //!< how we send messages to the vehicle
	};

}

