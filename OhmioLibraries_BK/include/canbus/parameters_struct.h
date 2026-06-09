#ifndef _PARAMETERS_STRUCT_H    /* Guard against multiple inclusion */
#define _PARAMETERS_STRUCT_H

typedef struct 
{
    uint16_t lookAheadDistance;                 //'' 25 look ahead distance in waypoints during driving if the path ahead of us is straight; if value is increased corner cutting becomes worse; range: min 1 max 100
    uint16_t minLookAheadDistance;              //'' 2 as a minimum we look ahead by 2 waypoints even for the max curve in our path; range min 1 max 100
    uint8_t lookAheadEndAlgo;                   //   0 this parameter selects the lookAhead calculation at the end of the track: 0: the lookahead is calculated from track +extension and only limited to avoid looking over the extended track, 1: the values from 0 are compared at the end to a ramp going from loockahed distance down to 1 and the lowest value is taken, 2-26: the last 25 values + extension are set to this value -1 range: 0-26
    uint8_t headingFilterLength;                //'' 16 number of values used for the sliding average filter that filters the heading as it is calculated during heading postProcessing (range: min=4 max=128)
    uint8_t locationFilterLength;               //'' 16 number of values used for the sliding average filter that filteres the longitude and latitude values after a direct recording (if the speed during recording is slower we can increase this value) (range: min=4 max=64)
    float distance;                             //'' 0.2128 distance between 2 drive waypoints in m (range min 0.01   max 2.0
    float speedIncreaseStep;                    //'' 40 speed rampup in mm/s; during post Processing any speed increase will be radually using this value from one waypoint to the next; rang min: 10  max 1000
    uint8_t rightHandDrive;                     //'' any value other than 0 are indicated as right hand drive
    uint16_t requetAcceptStopDist;              //+  500 for general vehicle; 1500 for Lotte#5
    uint16_t manualSteerFilLength;              //+  16 filter length for filtering the manual steering value from the joystick (assuming a 10ms update from joystick the delay will be 8ms)
    float speedIncStepManual;                   //   40 speed rampup in mm/s; during manual drive any speed increase will be gradually using this value from stop to the next speed; rang min: 10  max 1000
    float maxSpeed;                             //+  7000 maximum speed used to calculate the postProc speed in m/s  range: min 100  max 27000
    float reserved1;                            //+  
    uint8_t noWPforPathExtension;               //+  5 in order to look ahead when approaching the track end artificial points need to be available after the track end point; this value defines how many points will be generated; range: 0..255 
    uint8_t approachSpeedDist;                  //   5 how far from the last waypoint is the speed set to approach speed (which is usually very low range: 0...255
    float approachSpeed;                        //   100 thi is the speed used at the end of the track or when approaching a stop in mm/s
} POST_PROC_PARAM_t;

typedef struct
{
    float wheelRadius;                          //'' 0.22 wheel radius in m    range: min 0.1 max 1.0
    float heading_kp;                           //'' 1.8 kp factor for heading PID filter   range: min: 0.1  max: 5.0
    float heading_ki;                           //'' 0.0 ki factor for heading PID filter  shall be 0 all the time
    float heading_kd;                           //'' 0.0 kd factor for heading PID filter  shall be 0 all the time
    float brake_ki;                             //'' 0.0 ki factor for braking PID
    float maxSpeed;                             //+  5000 maximum speed during drive speed in m/s  range: min 1000  max 5000
    float minSpeed;                             //+350 min driving speed needs to be more than 100rpm for motor to start drive
    uint16_t speedIncreaseStepDrive;            //'' 5 speed rampup in mm/s after speed has been reduced during driving due to unexpected steering action range: min 1 max 1000
    uint8_t steeringType;                       //'' 0 used to identify the steering rack type
    uint32_t obstDeceleration;             // 1400 deceleration used when approaching an obstacle which is still far away
} DRIVE_PARAM_t;


#endif /* _PARAMETERS_STRUCT_H */

