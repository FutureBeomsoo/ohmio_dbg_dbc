#pragma once
#include "version.h"
#include <string>
#include <vector>


class StringUtilities
{
public:
	StringUtilities(void);
	~StringUtilities(void);

	static std::string GetExtensionFromFile(const std::string& fileName);
	static std::string StripExtensionFromFile(const std::string& fileName);
	static std::string GetPathFromFile(const std::string& fileName);
	static std::string StripPathFromFile(const std::string& fileName);
	static bool IsStringFullPath(const std::string& pathName);
	static std::string trim(const std::string& source);

	// convert string to lower case
	static std::string ToLower(const std::string& source);

	static void ParseString(const std::string& line, char seperator, std::vector<std::string>& parsedStringOutput);
	static std::string ConvertIntToZeroPaddedString(int number, int numDigits);
	static int FindStringInList(const std::vector<std::string>& stringList, const std::string& stringToFind);
	static bool StringToBool(const std::string& boolString);
	static std::string BoolToString(bool boolString);
	static std::string BoolToStringTrueFalse(bool boolString);
	static int ReadIntNumberFromStringIgnoringAllNonDigits(const std::string& StringWithInt);

	static void StringToVectorFloat(const std::string& text, char seperator, std::vector<float>& numbers);
	static void StringToVectorDouble(const std::string& text, char seperator, std::vector<double>& numbers);
	static void StringToVectorInt(const std::string& text, char seperator, std::vector<int>& numbers);
	static float StringToFloat(const std::string& text);
	static double StringToDouble(const std::string& text);
	static long StringToInt(const std::string& text);

	// todo template these
	static std::string floatToString(float number);
	static std::string intToString(int number);

};