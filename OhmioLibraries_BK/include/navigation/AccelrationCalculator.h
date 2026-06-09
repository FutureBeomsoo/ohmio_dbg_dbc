#pragma once


//! Calculate the requirements for timed track
//
//! Call this function once, then call GetSpeed() and GetLocation() to get the 
//! speed and location for every time.
//! This will set the speed profile for starting at 0 speed, accelerating according to 
//! our formula, driving at constant speed and decelerating at the same rate to get back to 0 speed at 
//! the end of the track. The speed is calculated for the minimal jerk trajectory
//! X = (10 * t^3 - 15 * t^4 + 6 * t^5) (for normilazed t and x in [0,1] range)
//! All parameters are in m and sec.
//! This function initialize all the internal state so that it can calculate all the speeds and locations.
//! The function does no check if the acceleration and the length are valid or reasonable.
//! The speed is capped by what can be gain in the requested acceleration and length
//! @param[in] acceleration - the acceleration we want to follow (0.5 is a good value for our motor). 
//! in m/sec^2. must be >0.
//! @param[in] speed - the top speed we want to get to (m/sec)
//! @param[in] length - length of the track (m)
//! @return the full time to drive the track
float CreateSpeedProfile(float acceleration, float speed, float length);



//! Where should we be at the requested time
//
//! @param[in] time - time (seconds) to calculate for
//! @return expected distance from track start (m) at this time
float GetLocationForTimedDriving(float time);

//! What speed should we drive at for the requested time
//
//! @param[in] time - time (seconds) to calculate for
//! @return expected speed (m/sec) at this time
float GetSpeedForTimedDriving(float time);


