#pragma once



//! Calculate the next speed request
//
//! using the Intelligent Driver Model. 
//! See https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/3159195650/Speed+control+for+following
//! Call this function periodically to get the desired driving speed based on
//! the track speed, the current speed, the distance to obstacle and the speed of the obstacle.
//! All speeds are in m/sec, all distances are in m.
//! distance to stop line and obstacle are separated because a moving obstacle before 
//! a stop line may result in higher speed. And we want to get all the way to the stop line but need 
//! a gap from obstacles.
//! @param[in] currentSpeed - the actual speed we are driving now.
//! @param[in] trackSpeed - the desired speed (from track file or joystick)
//! @param[in] stopDistance - distance to nearest stop line. Any value over 900 is considered infinite. 
//! @param[in] obsDistance - distance to obstacle. Any value over 900 is considered infinite
//! @param[in] movingAway - obstacle is moving away. Do not decelerate for it.
//! @return the speed for this time step
float CalcualteSpeedIdm(float currentSpeed, float trackSpeed, float stopDistance, float obsDistance, int movingAway);


//! For testing reset the current state so that tests are not influenced by prev tests.
//! On the vehicle this is not needed because the current state is updated continuously  
void ResetIdm();