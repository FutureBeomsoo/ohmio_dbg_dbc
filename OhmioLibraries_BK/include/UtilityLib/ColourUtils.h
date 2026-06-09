#pragma once
#include "version.h"
#include <opencv2/opencv.hpp>
#include <vector>


//! Helper for generating colours
class ColourUtilities
{
	static std::vector<cv::Vec3b> randomColours;

public:
	//! Get a unique colur
	//
	//! The first time this is called for an ID it creates a new colour. Next time
	//! it will get the same colour. Colour 0 is alwas balck
	static cv::Vec3b GetColour(unsigned int id);
	static cv::Scalar ConvertUnitVectorToColour(cv::Vec3d unit);
};
