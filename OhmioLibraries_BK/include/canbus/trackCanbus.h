#ifndef TRACKCANBUS_H    /* Guard against multiple inclusion */
#define TRACKCANBUS_H

//version 1.1  by merging C compilation error @14-08-2018
//version 1.2  add vehicle mode @15-08-2018
//version 1.3  add canbus id @16-08-2018

#ifdef __cplusplus 
#include <cstdint>
#include <memory>
#include <cstring>
#else
#ifndef __PC_SIM
#include "app.h"
#endif
#endif

#include <math.h>


#include "WayPointDefinitions.h"

#include "CanMessage.h"


#define ACK 0x01
#define NAK 0x02
#define MD5_CHECK   0xFFFF
#define WAIT_TIMES 0x1FFFF      //0xFFFFF takes about 27sec, 0xFFFF takes about 27ms; 0x1FFFF takes about 3sec
#define MAX_RESEND_COUNT  5


enum eRec_GPS
{
    Lat1,
    Long1,
    Lat2,
    Long2
};

typedef enum
{
    /*Application's state machine 0~4 for reception state*/
    IDLE_STATE = 0,
    /*0~4 for reception state*/
    RC_REQUEST_STATE,
    RC_HEADER_STATE,
    RC_WAYPOINT_LOC_STATE,
    RC_WAYPOINT_DRIVE_STATE,
    /* 5~8 for transmission state   */
    TM_REQUEST_STATE,
    TM_HEADER_STATE,
    TM_WAYPOINT_LOC_STATE,
    TM_WAYPOINT_DRIVE_STATE,
    //9 for special status waiting for ACK
    TM_WAIT_STATE,
   
	// always add before this location
	NUMBER_OF_TRANSMISSION_STATES
} TRANSMISSION_STATES;

typedef enum
{
    BROADCASTING = 0x0000,
    MANAGEMENTSYS = 0x0001,
    DRIVECONTROLLER,
    OBSTACLE,

}DESTINATION;

typedef enum
{
    DOWNLOAD_REC_DATA = 0x0100,
    DOWNLOAD_REC_VERIFI_DATA,                   //0x101
    UPLOAD_DRIVE_DATA_SET1,                     //0x102
    UPLOAD_DRIVE_DATA_SET2,                     //0x103
    UPLOAD_DRIVE_DATA_SET1_REVERSE,             //0x104
    UPLOAD_DRIVE_DATA_SET2_REVERSE,             //0x105
    DOWNLOAD_DRIVE_DATA_SET1,                   //0x106
    DOWNLOAD_DRIVE_DATA_SET2,                   //0x107
    DOWNLOAD_DRIVE_DATA_SET1_REVERSE,           //0x108
    DOWNLOAD_DRIVE_DATA_SET2_REVERSE,           //0x109
    DOWNLOAD_DRIVE_VERIFI_DATA_SET1,            //0x10A
    DOWNLOAD_DRIVE_VERIFI_DATA_SET2,            //0x10B
    DOWNLOAD_DRIVE_VERIFI_DATA_SET1_REVERSE,    //0x10C
    DOWNLOAD_DRIVE_VERIFI_DATA_SET2_REVERSE,    //0x10D
}CONTROLTYPE;


typedef enum
{
    TRACK_ID_ONE      = 0x00,
    TRACK_ID_TWO      = 0x10,
    TRACK_NAME_ID     = 0x20,
    TRACK_TYPE_NOWP   = 0x30,
    MD5_LOC_ONE       = 0x40,
    MD5_LOC_TWO       = 0x50,
    MD5_FULL_ONE      = 0x60,
    MD5_FULL_TWO      = 0x70,
    TRACK_LAT         = 0x80,
    TRACK_LONG        = 0x90,
    TRACK_LOOKAHEAD   = 0xA0,
    TRACK_EVENT_FLAG  = 0xB0,
    TRACK_LAT_BACK    = 0xC0,
    TRACK_LONG_BACK   = 0xD0,

	// always add before this location
	TRACK_PKT_ID_END_OF_ENUM
}WP_PKT_ID;

typedef enum
{
    RESULT_OK          = 0x00,
    PARAMETER_ERROR    = 0x01,
    PARSE_HEADER_ERROR = 0x02,
    TIMEOUT_WAIT       = 0x03,
    PARSE_LOC_ERROR    = 0x04,
    PARSE_DRIVE_ERROR  = 0x05,

}RESULT_INFO;

typedef enum
{
    TRACK_ID_LOW = 1,
    TRACK_ID_HIGH,
    TRACK_NAME,
    TRACK_TYPES_AND_NO,
    MD5_LOC_LOW,
    MD5_LOC_HIGH,
    MD5_FULL_LOW,
    MD5_FULL_HIGH,
}HEADER_INDEX;

typedef enum
{
    LATITUTE = 1,
    LONGITUDE,
    HEADING_SPEED,
    TRACK_EVENT_FLAGS,
    LATITUTE2 = 3,
    LONGITUDE2,
}WAYPOINT_INDEX;

typedef enum
{
    /* vehicle is standing in parked condition but systems are ready to go to start*/
    V_IDLE,
    /* Drive the vehicle in manual mode */
    V_MANUAL,
    /* preparation to start the vehicle in autonomouse mode*/
    V_START,
    /* Drive the stored track autonomously */
    V_DRIVE,
    /* once we have ended the drive we go to end END state which will take care of stopping and holding the car*/
    V_END,
    /* Dump log file */
    V_DUMP_LOG,
    /* Dump record */
    V_DUMP_REC,
    /* Load path */
    V_LOAD,
    /* Record new path */
    V_RECORD,
    /* Post Proc new parameter/s*/
    V_POST_PROC,
    /* Error */
    V_ERROR,

} V_STATES;

typedef struct
{
    /* The application's current state */
    TRANSMISSION_STATES state;
    TRANSMISSION_STATES preState;
    DESTINATION dest;
    CONTROLTYPE type;
    DESTINATION host;

} GLOBAL_DATA;

//typedef struct
//{
//    uint16_t id;
//    uint8_t data[8];
//}CAN_MSG;

//for public interface:
extern GLOBAL_DATA g_data;						//!< current sta\te
extern OHMIO_PATH_INFO_t g_TrackInfo;			//!< header of the current track
extern OHMIO_WAY_POINT_LOC_t g_wayPoint_loc;	//!< the current way point
extern OHMIO_WAY_POINT_DRIVE_t g_wayPoint_drv;	//!< the current way point
extern V_STATES g_vehicleState;					//!< current state of the vehicle

//state machine

//! Interpare a recieved message from the CAN bus
//
//! Get the CAN package and translate it into a 
//! meaningful data stracture. The resulting data
//! will be in one (or more) of the public interfade
//! strutures above (g_data, g_TrackInfo, g_wayPoint_loc
//! g_wayPoint_drv, g_vehicleState).
//! Most messages take more then a single CAN package. 
//! The function will assemble the data from multiple 
//! packages as they come
//! @param[in] - canMsgIn the incomming CAN pacage
//! @param[out] - canMsgOut a reply CAN package to send (in needed)
//! @return - true if this is the end of a full message 
//! and the user can use the data generated by the message.
//! false if not full message so user should wait for more parts
bool receive_Tasks(CAN_MSG *canMsgIn, CAN_MSG *canMsgOut);

uint8_t transmit_Tasks(CAN_MSG *canMsgIn, CAN_MSG *canMsgOut);
void InitializeTrackTransState (DESTINATION host);
void prepareRequest(DESTINATION dest, CONTROLTYPE type, bool bReceive);
void sendACK_NAK(uint8_t id, uint16_t code, CAN_MSG *canMsgOut);
GLOBAL_DATA GetCurrentState(void);
void setVehicleState(V_STATES v_state);
uint16_t fetchHostCanbusID(bool bNAK);
void assignValue(uint8_t *des, uint8_t *src);
void idleProcess(CAN_MSG *canMsgIn);
void resetTasks(void);

//get or set data between lib and module
void getTrackInfoData(OHMIO_PATH_INFO_t *pTrackInfo);
void setTrackInfoData(OHMIO_PATH_INFO_t *pTrackInfo);
void getWP_loc_Data(OHMIO_WAY_POINT_LOC_t *pWayPoint_loc);
void setWP_loc_Data(OHMIO_WAY_POINT_LOC_t *pWayPoint_loc);
void getWP_drv_Data(OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv);
void setWP_drv_Data(OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv);
bool getFullData(OHMIO_PATH_INFO_t *pTrackInfo, OHMIO_WAY_POINT_LOC_t *pWayPoint_loc, OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv, uint8_t *pFinished_flags);

//read or write Header 
int readHeaderToCanbus(OHMIO_PATH_INFO_t *pTrackInfo, uint8_t *trackId_Low, uint8_t *trackId_High, uint8_t *trackName, uint8_t *trackTypeNoWp,
                                                      uint8_t *MD5Loc_Low, uint8_t *MD5Loc_High, uint8_t *MD5Full_Low, uint8_t *MD5Full_High);

int writeHeaderFromCanbus(uint8_t *trackId_Low, uint8_t *trackId_High, uint8_t *trackName, uint8_t *trackTypeNoWp,  uint8_t *MD5Loc_Low, 
                          uint8_t *MD5Loc_High, uint8_t *MD5Full_Low, uint8_t *MD5Full_High, OHMIO_PATH_INFO_t *pTrackInfo);

//read or write Recorded waypoint
int readRecWaypointToCanbus(OHMIO_WAY_POINT_LOC_t *wayPoint, uint8_t *buf_lat, uint8_t *buf_long, uint8_t *buf_lat2, uint8_t *buf_long2);

int writeRecWaypointFromCanbus(uint8_t *buf_lat, uint8_t *buf_long, uint8_t *buf_lat2, uint8_t *buf_long2, OHMIO_WAY_POINT_LOC_t *wayPoint);

//read or write Drive waypoint
int readDriveWaypointToCanbus(OHMIO_WAY_POINT_DRIVE_t *wayPoint, uint8_t *buf_lat, uint8_t *buf_long, uint8_t *heading_speed, uint8_t *trackEvent_flags);

int writeDriveWaypointFromCanbus(uint8_t *buf_lat, uint8_t *buf_long, uint8_t *heading_speed, uint8_t *trackEvent_flags, OHMIO_WAY_POINT_DRIVE_t *wayPoint);


//for private interface: (only use in the library)

//convert latitude/longitude to Canbus Message type
void convertGPSToCanMsg(uint64_t real_value, uint8_t negative, uint32_t wpNo, int latOrNot, uint8_t *buf_canMsg);

//convert Canbus Message type to latitude/longitude 
void convertCanMsgToGPS(uint8_t *buf_canMsg, uint64_t *real_value, uint8_t *negative, uint32_t *wpNo);

#endif // TRACKCANBUS_H
