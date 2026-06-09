#pragma once

#include <vector>

//! Both wheel steering bicycle trajectory prediction
class TrajectoryPredictor
{
public:
    TrajectoryPredictor(double wheel_base);

    class WheelMotion
    {
    public:
        double m_Speed; //!< m/s
        double m_Acceleration; //!< m/s2
        double m_SteeringAngle; //!< rad
        double m_SteeringRate; //!< rad/s
        WheelMotion(double Speed, double Acceleration, double SteeringAngle, double SteeringRate);
    };

    class TrajectoryPoint
    {
    public:
        double m_X; //!< m
        double m_Y; //!< m
        double m_Heading; //!< radian
        double m_Time; //!< sec
        TrajectoryPoint(double x, double y, double heading, double time);
    };

    void setInitialPose(const TrajectoryPoint& initial_pose);

    // exactEndpoint: force it to always finish at time = initial + Duration, even if it's not a multiple of
    // TimeStep or the translation is small
    void calcVehicleCenterTrajectory(const WheelMotion& FrontWheelMotion,
                                        const WheelMotion& RearWheelMotion,
                                        double Duration, // sec
                                        std::vector<TrajectoryPoint> &Trajectory,
                                        double TimeStep = 0.05, // sec
                                        bool exactEndpoint = false);

    TrajectoryPoint getRelativePose(double velocity,
                                    double acceleration,
                                    double frontSteering,
                                    double rearSteering,
                                    double duration);

    double getYawRate(double velocity, double frontSteering, double rearSteering);

private:
    double m_WheelBase;
    TrajectoryPoint m_InitialPose;

    TrajectoryPoint calcNextCenterTrajectoryPoint(const TrajectoryPoint& CurrentPose, // current vehicle center pose
                                                    double FrontSteeringAngle, double FrontDistanceStep,
                                                    double RearSteeringAngle, double RearDistanceStep);
};

