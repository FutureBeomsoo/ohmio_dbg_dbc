#ifndef TRACKCANBUS_H    /* Guard against multiple inclusion */
#define TRACKCANBUS_H


// #######################################################################################
// Do not touch this code!
// this is copied from code used for QT management to talk directly over CAN bus to upload 
// tracks. 
// I don't know why it works and it is very hard to debug
// #######################################################################################


//version 1.1  by merging C compilation error @14-08-2018
//version 1.2  add vehicle mode @15-08-2018
//version 1.3  add canbus id @16-08-2018

#include <cstdint>
#include <memory>
#include <cstring>
#include <math.h>

#include "track_utilities/WayPointDefinitions.h"
#include "CommonInclude.h"


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

    MANAGE_CONTROL_DATA = 0x650,
    MANAGE_ACK,
    MANAGE_TRACK_DATA,

    DRIVE_CONTROL_DATA = 0x660,
    DRIVE_ACK,
    DRIVE_TRACK_DATA,

    OBSTACLE_CONTROL_DATA = 0x670,
    OBSTACLE_ACK,
    OBSTACLE_TRACK_DATA,

}CAN_ID;

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


//for public interface:
extern GLOBAL_DATA g_data;
extern OHMIO_PATH_INFO_t g_TrackInfo;
extern OHMIO_WAY_POINT_LOC_t g_wayPoint_loc;
extern OHMIO_WAY_POINT_DRIVE_t g_wayPoint_drv;
extern V_STATES g_vehicleState;

//state machine
void receive_Tasks_ifs(Ohmio::CAN_MSG *canMsgIn, Ohmio::CAN_MSG *canMsgOut);
uint8_t transmit_Tasks_ifs(Ohmio::CAN_MSG *canMsgIn, Ohmio::CAN_MSG *canMsgOut);
void InitializeTrackTransState_ifs(DESTINATION host);
void prepareRequest_ifs(DESTINATION dest, CONTROLTYPE type, bool bReceive);
void sendACK_NAK_ifs(uint8_t id, uint16_t code, Ohmio::CAN_MSG *canMsgOut);
GLOBAL_DATA GetCurrentState_ifs(void);
void setVehicleState_ifs(V_STATES v_state);
uint16_t fetchHostCanbusID_ifs(bool bNAK);
void assignValue_ifs(uint8_t *des, uint8_t *src);
void idleProcess_ifs(Ohmio::CAN_MSG *canMsgIn);
void resetTasks_ifs(void);

//get or set data between lib and module
void getTrackInfoData_ifs(OHMIO_PATH_INFO_t *pTrackInfo);
void setTrackInfoData_ifs(OHMIO_PATH_INFO_t *pTrackInfo);
void getWP_loc_Data_ifs(OHMIO_WAY_POINT_LOC_t *pWayPoint_loc);
void setWP_loc_Data_ifs(OHMIO_WAY_POINT_LOC_t *pWayPoint_loc);
void getWP_drv_Data_ifs(OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv);
void setWP_drv_Data_ifs(OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv);
bool getFullData_ifs(OHMIO_PATH_INFO_t *pTrackInfo, OHMIO_WAY_POINT_LOC_t *pWayPoint_loc, OHMIO_WAY_POINT_DRIVE_t *pWayPoint_drv, uint8_t *pFinished_flags);

//read or write Header 
int readHeaderToCanbus_ifs(OHMIO_PATH_INFO_t *pTrackInfo, uint8_t *trackId_Low, uint8_t *trackId_High, uint8_t *trackName, uint8_t *trackTypeNoWp,
                                                      uint8_t *MD5Loc_Low, uint8_t *MD5Loc_High, uint8_t *MD5Full_Low, uint8_t *MD5Full_High);

int writeHeaderFromCanbus_ifs(uint8_t *trackId_Low, uint8_t *trackId_High, uint8_t *trackName, uint8_t *trackTypeNoWp,  uint8_t *MD5Loc_Low,
                          uint8_t *MD5Loc_High, uint8_t *MD5Full_Low, uint8_t *MD5Full_High, OHMIO_PATH_INFO_t *pTrackInfo);

//read or write Recorded waypoint
int readRecWaypointToCanbus_ifs(OHMIO_WAY_POINT_LOC_t *wayPoint, uint8_t *buf_lat, uint8_t *buf_long, uint8_t *buf_lat2, uint8_t *buf_long2);

int writeRecWaypointFromCanbus_ifs(uint8_t *buf_lat, uint8_t *buf_long, uint8_t *buf_lat2, uint8_t *buf_long2, OHMIO_WAY_POINT_LOC_t *wayPoint);

//read or write Drive waypoint
int readDriveWaypointToCanbus_ifs(OHMIO_WAY_POINT_DRIVE_t *wayPoint, uint8_t *buf_lat, uint8_t *buf_long, uint8_t *heading_speed, uint8_t *trackEvent_flags);

int writeDriveWaypointFromCanbus_ifs(uint8_t *buf_lat, uint8_t *buf_long, uint8_t *heading_speed, uint8_t *trackEvent_flags, OHMIO_WAY_POINT_DRIVE_t *wayPoint);


//for private interface: (only use in the library)

//convert latitude/longitude to Canbus Message type
void convertGPSToCanMsg_ifs(uint64_t real_value, uint8_t negative, uint32_t wpNo, int latOrNot, uint8_t *buf_canMsg);

//convert Canbus Message type to latitude/longitude 
void convertCanMsgToGPS_ifs(uint8_t *buf_canMsg, uint64_t *real_value, uint8_t *negative, uint32_t *wpNo);

//check drive data 4 packs
bool checkWaypoint_ifs();

#endif
