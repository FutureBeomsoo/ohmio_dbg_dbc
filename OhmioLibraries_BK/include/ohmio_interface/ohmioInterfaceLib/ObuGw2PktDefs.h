#ifndef OBUGW2_PKTDEFS_HPP_
#define OBUGW2_PKTDEFS_HPP_


#define V2X_IF_SIGNATURE	 0x1609


#ifdef _WINDOWS
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
#else
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

typedef enum
{
	V2X_IF_TX_V2X_MSG 	= 0x1000,	// host -> OBU, event comes from OBU only when error.
	V2X_IF_RX_V2X_MSG,				// OBU -> host
	V2X_IF_CLEAR_RSU_V2X_MSG,		// host -> OBU, empty all V2X message files on RSU.
	V2X_IF_UPLOAD_RSU_V2X_MSG,		// host -> OBU
	V2X_IF_EVENT		= 0x2000,	// OBU -> host
	V2X_IF_SYSTEM		= 0x3000,	// host -> OBU, system reboot, etc.
	V2X_IF_WAVE_CFG		= 0x4000,	// host <-> OBU, config for WAVE channel.
	V2X_IF_TYPE_MAX
} V2X_IF_PKT_TYPE_E;

typedef enum
{
	V2X_IF_EVENT_OK = 0x0001,
	V2X_IF_EVENT_OP_WRONG_INPUT,
	V2X_IF_EVENT_OP_NOT_SUPPORT,
	V2X_IF_EVENT_OP_NOT_READY,
	V2X_IF_EVENT_OP_FAIL,
	V2X_IF_EVENT_NO_RESOURCE,
	V2X_IF_EVENT_INTERNAL_ERROR,
	V2X_IF_EVENT_CERT_CHANGED,
	V2X_IF_EVENT_MAX
} V2X_IF_EVENT_E;

typedef enum
{
	V2X_IF_SYSTEM_CHECK_WAVE_STATE = 0x0001,
	V2X_IF_SYSTEM_REBOOT,
	V2X_IF_SYSTEM_CFG_NET,
	V2X_IF_SYSTEM_ANNEX,		// minor supplementary functions.
	V2X_IF_SYSTEM_MAX
} V2X_IF_SYSTEM_E;

PACK(typedef struct
{
	uint16_t signature;	// (@ref V2X_IF_SIGNATURE)
	uint16_t type;		// packet type (@ref V2X_IF_PKT_TYPE_E)
	uint16_t seq;		// 0 is reserved for V2X_IF_RX_V2X_MSG. OBU just copies it which host sent.
	uint16_t len;		// payload length
	uint32_t reserved;	// SHOULD be 0 when tx to OBU.
}) V2X_IF_PKT_HDR_T;


#pragma warning( push )
#pragma warning( disable : 4200 )

PACK(typedef struct
{
	V2X_IF_PKT_HDR_T hdr;
	uint8_t payload[];
}) V2X_IF_PKT_T;

PACK(typedef struct
{
	uint16_t event;			// V2X_IF_EVENT_E
	int16_t reserved;
	int8_t reserved2[];
} ) V2X_IF_PAYLOAD_EVENT_T;


PACK(typedef struct
{
	uint16_t cmd;			// V2X_IF_SYSTEM_E
	int8_t params[];
} ) V2X_IF_PAYLOAD_SYSTEM_T;


PACK(typedef struct {
	char  section[64];	// "wave_provider_radio", "wave_provider_service", "wave_user_radio", "wave_user_service"
	uint8_t data[];
} )  V2X_IF_PAYLOAD_WAVE_CFG_T;

#pragma warning( pop )


#endif /* OBUGW2_PKTDEFS_HPP_ */
