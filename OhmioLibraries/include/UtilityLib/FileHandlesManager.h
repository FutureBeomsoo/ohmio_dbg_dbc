#pragma once
#include "version.h"
#include <string>


//! Monitor and manage file handles under Linux. 
//! This class is used to handle file handle leak from opencv.
//! Would be much better to not have a leak but unfortunatly Opencv 
//! cv::VideoCapture has a leak under Linux at least on the JESTON board
//! And the only solution is to monitor and mange leaks.
class FileHandlesManager
{
public:
	FileHandlesManager(int maxHandlesAllowed);
	~FileHandlesManager();

	//! Count handles and clean unusded ones if needed.
	//
	//! @param[in] lasCount - number of allocated file handles last time we counted 
	//! @return - number of allocated file handles. This number 
	//! should stay resonably constant over time 
	int CleanHandlesIfNeeded(int lasCount);



private:
	int CountHandles();
	std::string GetAllHandlesInfo();
	void CleanHandles();
	std::string showFDInfo(int fd);


private:
	int m_maxAllowed;
};

