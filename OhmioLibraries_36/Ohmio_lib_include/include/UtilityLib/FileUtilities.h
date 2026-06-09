#pragma once
#include "version.h"
#include <string>
#include <vector>


//! Helper for file operations. Should support windows and Linux.
//
//! Should be replaced with calls to std::filesystem
class FileUtilities
{
public:

	//! Find all the files (not folders) in a folder
	//
	//! @param[in] folder - the folder to look in.
	//! @param[out] fileNames - a list of all the detected files
	static void FindAllFiles(std::string folder, std::vector<std::string>& fileNames);

	//! Find all the files (not folders) in a folder matching some wildcard.
	//
	//! Currently only for windows
	//! @param[in] folder - the folder to look in.
	//! @param[in] wildcard - the wildcard. For example *.png, image_*.*, *.*
	//! @param[out] fileNames - a list of all the detected files
	static void FindAllFilesWithWildCard(std::string folder, std::string wildcard, std::vector<std::string>& fileNames);

	//! Is a file or folder exist?
	//
	//! @param[in] name - the file or folder to find
	//! @return true if file or folder exist
	static bool exists(std::string name);



	//! Is a folder exist?
	//
	//! @param[in] name - the file or folder to find
	//! @return true if folder exist
	static bool FolderExists(const std::string& folderPath);

	//! Create directory  
	//
	//! @param[in] name - the nae of the directory to create.
	//! if the name contains '/' it will create the directory hierarchy as needed 
	//! @return false if failed.
	static bool create_directories(std::string name);

	//! Create a directory  
	//
	//! @param[in] name - the nae of the directory to create.
	//! Will only create a single folder not a hierarchy
	//! If the folder already exist will do nothing
	static void CreateFolder(const std::string& folderPath);

	//! remove directory  
	//
	//! @param[in] name - the directory to remove.
	//! remove all sub directories and files 
	//! @return false if failed.
	static bool remove_directory(std::string name);


	//! clean directory  
	//
	//! @param[in] folderPath - the directory to clean.
	//! remove all sub directories and files 
	//! @return false if failed.
	static bool EmptyFolder(const std::string& folderPath);


	enum CopyFolderMode { Overwrite, Merge };
	//! Copy a folder
	//
	//! @param[in] source - the directory to copy.
	//! @param[in] destination - copy to.
	//! @param[in] CopyFolderMode - what to do with existing file Overwrite or keep existing.
	static bool CopyFolder(const std::string& source, const std::string& destination, CopyFolderMode = Overwrite);

	//! Get the full path for AiResource.
	//
	//! No unit tests because this is used in many tests and these tests will fail if this one does
	static std::string GetAiResourcesPath()
	{
		std::string aiRoot = "";
#ifdef  _WINDOWS  
		char *pValue;
		size_t len;
		_dupenv_s(&pValue, &len, "AiResource");
		aiRoot = pValue;
#else// not windows so we can assume Linux
		aiRoot = std::getenv("AiResource");
#endif // ! _WINDOWS  
		return aiRoot;
	}


private:
	//! helper function to remove '/' and '\'
	static void RemoveTrailingSlashes(std::string& directoryPath);

};

