#pragma once
#include "version.h"


#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES // needed for the definition of M_PI
#endif
#include <math.h>
#include <numeric>
#include <opencv2/opencv.hpp>
#include <Eigen/Geometry>

//! Helper functions for math
namespace MathHelper
{ 
	//! return +-1 according to sign, sign(0) is +1
	template <class T> constexpr T sign(T x)
	{
		return (x < 0) ? -1 : 1;
	}

    //! Square a number
    template <typename T> constexpr T sqr(const T x)
    {
        return x * x;
    }

    //! If the value of v is within [lo, hi], returns v; otherwise returns the nearest boundary.
    template<class T>
    constexpr const T& clamp(const T& v, const T& lo, const T& hi)
    {
        return std::min(std::max(v, lo), hi);
    }

    // return type forces angle conversion to promote int to double,
    // while still allowing classes like cv::Vec3d with operator* to be passed to the functions
	template<class T>
    typename std::conditional<std::is_integral<T>::value, double, T>::type RadiansToDegrees(T x) { return x * (180.0 / M_PI); };
    template<class T>
    typename std::conditional<std::is_integral<T>::value, double, T>::type DegreesToRadians(T x) { return x * (M_PI / 180.0); };

    //! Normalize an angle in degrees to the range (-180, 180]
    template<class T>
    T normalizeDegrees(T angle)
    {
        angle = fmod(angle, 360.0);
        if (angle > 180.0)
        {
            angle -= 360.0;
        }
        else if (angle <= -180.0)
        {
            angle += 360.0;
        }
        return angle;
    }

    //! Normalize an angle in degrees to the range [0, 360)
    template<class T>
    T normalizeDegreesPositive(T angle)
    {
        angle = fmod(angle, 360.0);
        if (angle < 0)
        {
            angle += 360.0;
        }
        return angle;
    }

    //! Normalize an angle in radians to the range (-pi, +pi]
    template<class T>
    T normalizeRadians(T angle)
    {
        angle = fmod(angle, 2 * M_PI);
        if (angle > M_PI)
        {
            angle -= 2 * M_PI;
        }
        else if (angle <= -M_PI)
        {
            angle += 2 * M_PI;
        }
        return angle;
    }

	//! Calculate difference between 2 angles in radians
	//
	//! @param[in] a1 - first andle in radians 
	//! @param[in] a2 - second andle in radians
	//! @return the angle between the two (radians) in range [0, pi]
	inline double AngleDiff(double a1, double a2)
	{
		double diff = fabs(a1 - a2);
		if (diff > M_PI)
		{
			diff = M_PI*2 - diff;
		}
		return diff;
	}


	//! Calculate the average of an STD container
	//
	//! Not suitable for very large data. for large data use https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance 
	template <typename Container, typename T = typename std::decay<decltype(*std::begin(std::declval<Container>()))>::type>
	T mean(Container && c)
	{
		auto b = std::begin(c), e = std::end(c);
		auto size = std::distance(b, e);
		if (size <= 0)
		{
			return T(0);
		}
		auto sum = std::accumulate(b, e, T(0));
		auto m = sum / size;
		return T(m);
	}

	//! Calculate the average and variance of an STD container
	//
	//! Not suitable for very large data. for large data use https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance 
	template <typename Container, typename T = typename std::decay<decltype(*std::begin(std::declval<Container>()))>::type>
	T meanAndVar(Container && c, T& var)
	{
		auto b = std::begin(c), e = std::end(c);
		auto size = std::distance(b, e);
		if (size <= 0)
		{
			var = T(0);
			return T(0);
		}
		auto m = mean(c);

		var = T();
		std::for_each(b, e, [&](const double d) {
			var += (d - m) * (d - m);
		});

		if (size > 1)
		{
			size--;
		}
		var /= size;

		return T(m);
	}

	//! Calculate the average and variance for a container holding cv::Vec<>. Can't use meanAndVar becuse the initialization of the cv::Vec
	//
	//! Not suitable for very large data. for large data use https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance 
	template <typename Container, class T, int depth>	cv::Vec<T, depth> meanAndVarCvVect(Container && c, cv::Vec<T, depth>& var)
	{
		cv::Vec<T, depth> m;
		for (int i = 0; i < depth; ++i)
		{
			m[i] = 0;
			var[i] = 0;
		}

		auto b = std::begin(c), e = std::end(c);
		auto size = std::distance(b, e);
		if (size <= 0)
		{
			return m;
		}
		std::for_each(b, e, [&](const cv::Vec<T, depth> d)
		{
			m += d;
		});

		m /= (T)size;
		std::for_each(b, e, [&](const cv::Vec<T, depth> d)
		{
			var += (d - m).mul(d - m);
		});
		if (size > 1)
		{
			size--;
		}
		var /= (T)size;
		return m;
	}


	//! calculate the radius of curvature from 3 points
	//
	//! see https://en.wikipedia.org/wiki/Menger_curvature#Definition
	//! We are looking for the radius of the circle through the 3 points.
	//! radius = |a-b|*|b-c|*|c-a| / (4 * triangle area)
	//! @param[in] a - one of the 3 points to fit a circle through
	//! @param[in] b - one of the 3 points to fit a circle through
	//! @param[in] c - one of the 3 points to fit a circle through
	//! @return the radius of curvature
	template<class T> double RadiusOfCurvature(const cv::Point_<T>& a,
		const cv::Point_<T>& b, const cv::Point_<T>& c)
	{
		cv::Point_<T> ab = a - b;
		cv::Point_<T> ac = a - c;
		cv::Point_<T> bc = b - c;
		
		double area = fabs(ab.cross(ac)); // the cross product is 2*area 
		if (area < 1e-8)
		{ // the points are almost on a line
			return std::numeric_limits<double>::max(); // any large number will do
		}

		double dist = ab.ddot(ab) * ac.ddot(ac) * bc.ddot(bc);
		return sqrt(dist) / (area * 2.0);
	}

    //! Extract yaw angle from a 3x3 rotation matrix
    //! Equivalent to quaternionToEuler(Eigen::Quaterniond{rot}).z()
    inline double getYawFromRotationMatrix(const Eigen::Matrix3d& rot)
    {
        return std::atan2(rot(1, 0), rot(0, 0));
    }

    //! convert a quaternion to euler angles
    //! https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
	//! @param[in] q - quaternion to convert
    //! @return euler angles: roll, pitch, yaw
    Eigen::Vector3d quaternionToEuler(const Eigen::Quaterniond& q);
    
}
