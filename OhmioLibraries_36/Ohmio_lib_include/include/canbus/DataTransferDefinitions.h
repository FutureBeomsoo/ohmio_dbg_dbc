#ifndef OHMIO_DATA_TRANSFER_DEFINITIONS_H
#define OHMIO_DATA_TRANSFER_DEFINITIONS_H


//! What transfer actions are available?
typedef enum
{
	TRANSFER_ACTION_UPLOAD = 0,      //!< start uploading data
	TRANSFER_ACTION_DOWNLOAD,        //!< ask for the other side to start transfer
	TRANSFER_ACTION_VERIFY,          //!< finished transfer, verify the data
	TRANSFER_ACTION_VERIFY_PART,     //!< verify the data up to this point
	TRANSFER_ACTION_RESEND_FROM,     //!< we are about to restart the sending from a location

	// always add before this
	TRANSFER_ACTION_LAST
} TRANSFER_ACTIONS;

//! Error codes for the transfer
typedef enum
{
	TRANSFER_ERROR_CODE_NOERROR = 0,		//!< All good
	TRANSFER_ERROR_CODE_TIMEOUT,			//!< timeout - no reply after too long
	TRANSFER_ERROR_CODE_WRONGSTATE,			//!< got state change when in the wrong state (i.e. transfer starts twice)
	TRANSFER_ERROR_CODE_WRONGTYPE,			//!< Called with wrong sender or type
	TRANSFER_ERROR_CODE_WRONGPACKET,		//!< missing or repeating packet
	TRANSFER_ERROR_CODE_PACKETERROR,		//!< packet verification error
	TRANSFER_ERROR_CODE_VERIFICATIONERROR,	//!< failed checksum or length of data

	// always add before this
	TRANSFER_ERROR_CODE_LAST
} TRANSFER_ERROR_CODES;


//! What transfer data types do we support
typedef enum
{
	TRANSFER_DATA_TYPE_UNKOWN = 0,			//!< place holder
	TRANSFER_DATA_TYPE_TRACK_1F = 1,		//!< track points 1 forward 
	TRANSFER_DATA_TYPE_TRACK_1R = 2,        //!< track points 1 reverse 
	TRANSFER_DATA_TYPE_TRACK_2F = 3,        //!< track points 2 forward 
	TRANSFER_DATA_TYPE_TRACK_2R = 4,        //!< track points 2 reverse 


	// always add before this
	TRANSFER_DATA_TYPE_LAST
} TRANSFER_DATA_TYPES;

#endif // OHMIO_DATA_TRANSFER_DEFINITIONS_H
