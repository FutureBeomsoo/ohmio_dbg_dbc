#pragma once
#include "version.h"

#include <opencv2/opencv.hpp>

namespace LineUtilities
{
	//! Intersect two lines defined by 2 points on each line
	//
	//! Any point on the line 1 (o1, p1) can be written as X = o1 + t * (p1 - o1). if t= 0 this is o1, if t =1 this is p1.
	//! to be on the line 2 (o2, p2) we also want the triangle (o2, p2, X) to have 0 area so (X - o2) cross (p2 - o2) = 0
	//! put  X = o1 + t * (p1 - o1) in the second equation and we get
	//! t = -(o1-o2).cross(p2 - o2)/(p1 - o1).cross(p2 - o2)
	//! @param[in] o1 - point of the first line 
	//! @param[in] p1 - second point of the first line 
	//! @param[in] o2 - point of the second line 
	//! @param[in] p2 - second of the second line 
	//! @param[out] intersection - the intersection point
	//! @return true if the lines intersect, false if not
	template<class T> bool IntersectLines(cv::Point_<T> o1, cv::Point_<T> p1, cv::Point_<T> o2, cv::Point_<T> p2, cv::Point_<T>& intersection)
	{
		cv::Point_<T> line1 = p1 - o1;
		cv::Point_<T> line2 = p2 - o2;
		cv::Point_<T> d = o2 - o1;
		double denumerator = line1.cross(line2);
		if (fabs(denumerator) <1e-8)
		{ // too close to parallel
			return false;
		}

		double t = d.cross(line2) / denumerator;
		intersection = o1 + t * line1;
		return true;
	}

	//! Intersect a line segment with a ray
	//
	//! Any point on the line 1 (o1, p1) can be written as X = o1 + t * (p1 - o1). if t= 0 this is o1, if t =1 this is p1.
	//! to be on the line 2 (o2, p2) we also want the triangle (o2, p2, X) to have 0 area so (X - o2) cross (p2 - o2) = 0
	//! put  X = o1 + t * (p1 - o1) in the second equation and we get
	//! t = -(o1-o2).cross(p2 - o2)/(p1 - o1).cross(p2 - o2)
	//! @param[in] segmentStart - starting point of the segment 
	//! @param[in] segmentEnd - end point of the segment
	//! @param[in] origin - origin of the second line 
	//! @param[in] angle - direction (in radians, [0, 2PI]) of the ray  
	//! @param[out] intersection - the intersection point
	//! @return true if the ray intersects the segment
	template<class T> bool IntersectWithLineSegment(cv::Point_<T> segmentStart, cv::Point_<T> segmentEnd, cv::Point_<T> origin, double angle, cv::Point_<T>& intersection)
	{
		cv::Point_<T> line1 = segmentEnd - segmentStart;
		cv::Point_<T> line2(cos(angle), sin(angle));
		cv::Point_<T> d = origin - segmentStart;
		double denumerator = line1.cross(line2);
		if (fabs(denumerator) <1e-8)
		{ // too close to parallel
			return false;
		}

		double t = d.cross(line2) / denumerator;
		intersection = segmentStart + t * line1;
		return (0 <= t && t <= 1.0); // inside the segment only if t is inside [0, 1]
	}

	//! Calculate line equation
	//
	//! Calcualte the equation aX+bY+c=0 of the line defined by 2 points
	//! we want to find (a,b,c) so that aX+bY+c=0 goes via the 2 points.
	//! we only need 2 parameters so we are free to choose the 3rd.
	//! Mark dX = X1-X0, dY = Y1-Y0. every point on the line sutisfy
	//! (Y-Y0)/(X-X0) = dY/dX ==> dY*X - dX*Y + dX*Y0 - dY*X0 = 0
	//! so a = dY, b = -dX, c = dX*Y0 - dY*X0
	//! @param[in] line - the line defined by 2 points on the line
	//! @return cv::Point2d(a, b, c)
	template<class T> cv::Point3_<T> FindLineEquationFromPoints(const std::pair<cv::Point_<T>, cv::Point_<T>>& line)
	{
		double dY = line.second.y - line.first.y;
		double dX = line.second.x - line.first.x;
		cv::Point3d equation;
		equation.x = dY;
		equation.y = -dX;
		equation.z = dX * line.first.y - dY * line.first.x;

		return equation;
	}

	////! Calculate a unit vector prependicular to a line defined by 2 points
	////
	////! @param[in] line - the linde as a vector
	////! @return unit vector prependicular to the points. 
	////! Pointing to the right ig you stand in a looking to b
	//template<class T> cv::Point_<T> PrependicularLine(cv::Point_<T> line)
	//{
	//	cv::Point_<T> prep(line.y, -line.x);
	//	double denumerator = cv::norm(prep);
	//	if (denumerator > 1e-8)
	//	{ // too short
	//		prep /= denumerator;
	//	}

	//	return prep;
	//}


	//! Project a line to a plane parallel to axes
	//
	//! Any point on the line is defined by l=p1+t(p2-p1). Points on the parallel plane
	//! are defined by l[index] = D. This is used to calculate t and then the result
	//! @param[in] p1 - point of the line 
	//! @param[in] p2 - second point of the line
	//! @param[in] planeDistance - the value of the plane 
	//! @param[in] planeIndex - which axis we want (0-X,1-Y,2-Z)  
	//! @return the projected point on the plane
	template<class T> cv::Vec<T, 3> ProjectToPlane(cv::Vec<T, 3> p1, cv::Vec<T, 3> p2, T planeDistance, int planeIndex)
	{
		if (planeIndex < 0 || planeIndex > 2)
		{
			return cv::Vec<T, 3>(0, 0, 0); // invalid
		}
		 
		cv::Vec<T, 3> direction = p2 - p1;
		T denumerator = direction[planeIndex];
		if (fabs(denumerator) < 1e-8)
		{ // too close to parallel
			return cv::Vec<T, 3>(0, 0, 0); // invalid
		}
		T t = (planeDistance - p1[planeIndex]) / denumerator;


		return p1 + t * direction;
	}



	//! Line drawing algorithm in 3D
	//
	//! from https://gist.github.com/yamamushi/5823518
	//! uses Bresenham's algorithm to generate the 3 dimensional points on the line from 'start' to 'end' (inclusieve)
	//! resulting points are stored in 'theLine'
	template<class T> void CreateLine3D(cv::Point3_<T> start, cv::Point3_<T> end, std::vector<cv::Point3i>& theLine)
	{
		int i, dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;


		cv::Point3i point = start;
		dx = (int)(end.x - start.x);
		dy = (int)(end.y - start.y);
		dz = (int)(end.z - start.z);
		x_inc = (dx < 0) ? -1 : 1;
		l = abs(dx);
		y_inc = (dy < 0) ? -1 : 1;
		m = abs(dy);
		z_inc = (dz < 0) ? -1 : 1;
		n = abs(dz);
		dx2 = l << 1;
		dy2 = m << 1;
		dz2 = n << 1;

		theLine.clear();
		int lineLength = std::max(std::max(abs(dx), abs(dy)), abs(dz));
		theLine.reserve(lineLength);


		if ((l >= m) && (l >= n)) {
			err_1 = dy2 - l;
			err_2 = dz2 - l;
			for (i = 0; i <= l; i++) {
				theLine.push_back(point);
				if (err_1 > 0) {
					point.y += y_inc;
					err_1 -= dx2;
				}
				if (err_2 > 0) {
					point.z += z_inc;
					err_2 -= dx2;
				}
				err_1 += dy2;
				err_2 += dz2;
				point.x += x_inc;
			}
		}
		else if ((m >= l) && (m >= n)) {
			err_1 = dx2 - m;
			err_2 = dz2 - m;
			for (i = 0; i <= m; i++) {
				theLine.push_back(point);
				if (err_1 > 0) {
					point.x += x_inc;
					err_1 -= dy2;
				}
				if (err_2 > 0) {
					point.z += z_inc;
					err_2 -= dy2;
				}
				err_1 += dx2;
				err_2 += dz2;
				point.y += y_inc;
			}
		}
		else {
			err_1 = dy2 - n;
			err_2 = dx2 - n;
			for (i = 0; i <= n; i++) {
				theLine.push_back(point);
				if (err_1 > 0) {
					point.y += y_inc;
					err_1 -= dz2;
				}
				if (err_2 > 0) {
					point.x += x_inc;
					err_2 -= dz2;
				}
				err_1 += dy2;
				err_2 += dx2;
				point.z += z_inc;
			}
		}

	}


	//! calculate the (square) distance between a point (pointX,pointY) and the line from (startX, startY) to (endX, endY)
	//
	//! see https://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
	//! Note that we return the square distance to save the processing time of sqrt()
	//! also we return the distance to the line not to the segment. If the nearest point on the line is outside the segment
	//! we will measure the distance to that point. To measure distance to segment limit 'u' to [0,1] 
	//! @param[in] start - start of the line segment
	//! @param[in] start - start of the line segment
	//! @param[in] end - end of the line segment
	//! @param[in] thePoint - point to measure distance from
	//! @param[in] segment - if set the true measure distance to segment, otherwise to the infinite line
	//! @return the distance squared (to avoid sqrt if not needed)
	template<class T> double DistanceToLine(const cv::Point_<T>& start,
		const cv::Point_<T>& end, const cv::Point_<T>& thePoint, 
		bool segment = false)
	{
		cv::Point_<T> p = end - start;
		double norm = p.ddot(p);
		cv::Point_<T> diff = thePoint - start;
		double u = diff.ddot(p) / norm;
		if (segment)
		{
			u = std::min(std::max(u, 0.0), 1.0);
		}
		cv::Point_<T> nearest = start + u * p;
		cv::Point_<T> distance = nearest - thePoint;
		return distance.ddot(distance);
	}


}