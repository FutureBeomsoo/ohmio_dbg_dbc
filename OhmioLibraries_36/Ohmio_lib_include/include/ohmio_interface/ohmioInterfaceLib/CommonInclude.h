#pragma once

#include <cstdint>
#include <memory>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <cstring>
#include <set>

//! all of the ohmio interface, See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/972685321/Modular+design+of+the+ohmio+interface
namespace Ohmio
{
	enum class CanBuses
	{
		MainCan = 0,	//!< the main Can bus
		CanP = 1,	//!< the peripheral can bus

		// Always put more values above this
		lastCan		//!< just for enumeration
	};

	//! A can message
	class CAN_MSG
	{
	public:
		CAN_MSG(uint64_t messageId = 0, CanBuses bus = CanBuses::MainCan) 
			: busId(bus), id(messageId), length(8), loopBack(false), data({ 0,0,0,0,0,0,0,0 }) {}
		~CAN_MSG() {};
		CanBuses busId;		//!< which bus this message belong to
		uint64_t id;		//!< message id from enum COMMON_CAN
		uint8_t length;		//!< how many bytes are used in this message
		bool loopBack;		//!< if true feed the message back to the read buffer when writing (to update listeners)
		std::array<uint8_t, 8> data;	//!< the message data

		//! Copy the data to uint8_t buf[8] for interpreting message using dbc_can.h
		void CopyData(uint8_t* buf) const
		{
			memcpy(buf, &(data[0]), sizeof(data));
		}
		//! Copy the data from uint8_t buf[8] for sending message using dbc_can.h
		void CopyFrom(const uint8_t* buf)
		{
			memcpy(&(data[0]), buf, sizeof(data));
		}
	};


	//! List of all the driving lights in the vehicle. 
	enum class DrivingLightItem
	{
		FrontMainBeamHeadlampRight = 0,
		FrontMainBeamHeadlampLeft,
		FrontDippedBeamHeadlampRight,
		FrontDippedBeamHeadlampLeft,
		FrontDayTimeRunningLampRight,
		FrontDayTimeRunningLampLeft,
		FrontDirectionIndicatorLampRight,
		FrontSideDirectionIndicatorLampRight,
		FrontDirectionIndicatorLampLeft,
		FrontSideDirectionIndicatorLampLeft,
		FrontpositionLampRight,
		FrontpositionLampLeft,
		FrontEndOutlineMarkerLampRight,
		FrontEndOutlineMarkerLampLeft,
		RearStopLampRight,
		RearStopLampLeft,
		RearSubBrakeLamp,
		RearReversingLampRight,
		RearReversingLampLeft,
		RearDirectionIndicatorLampRight,
		RearDirectionIndicatorLampLeft,
		RearTailLightRight,
		RearTailLightLeft,
		RearRegistrationPlatelamp,
		RearEndOutlineMarkerLampRight,
		RearEndOutlineMarkerLampLeft,
		ReverseSoundBeeper,		// we treat the reversing 'beep' as a light

		numControlledLights,	// lights before this are controlled by rules
		InternalLight,			// This is not a driving light but is tangled with light message so we need to have it

		// Always put more values above this
		CountLights //!< just for enumeration
	};



	//! the state of an oval light. the brightness and error of R,G,B
	//
	//! Nate that we only use the RGB mode for oval lights
	class OvalLightState
	{
	public:
		OvalLightState() : wasSet(false)
		{
			for (int i = 0; i < 3; ++i )
			{
				brightness[i] = 0;
				errors[i] = 0;
			}
		}
		std::array<uint8_t,3> brightness;		//!< brightness in [0, 255]. 0 for off 255 for full on
		std::array<uint8_t, 3> errors;			//!< 0 for OK, otherwise error code
		bool wasSet;							//!< true if this was set
	};


	const std::string defaultServerAddress = "0.0.0.0:1234"; //!< the default address for the vehicle



	//! Results of track upload
	enum class TrackUploadState
	{
		sucess = 0,			//!< load sucess
		inProgress,			//!< currently loading a track
		fileReadError,		//!< error reading track file
		trackTooLong,		//!< track file is too long
		trackInvalid,		//!< track has invalid features
		uploadError,		//!< error in upload 
		obstacleUpload,		//!< uploading obstacle files to shared drive
		managementBlock,	//!< track uploading blocked by managements (outside interface control) 


		// always add above this
		last
	};

	// forward declarations
	class MessageReceiver;
	class IMessageObserver;
	class MessageBuffer;
	class CanbusLoop;
	class ICanBus;
	class CommunicationManager;
	class TcpServer;
	class SafetyRegulator;
	class VersionsInfo;
	class ILightToCanTranslator;
	class HardwareDetector;
	class MixedLightMessageHandler;
	class IV2Xhandler;
	class IV2XConsumer;
	class ParametersInterface;
	class NameTranslator;
	class TrackUploader;
	class VersionsStatus;
	class SharedDriveChecker;
}
