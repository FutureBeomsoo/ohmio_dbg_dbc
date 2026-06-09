#pragma once
#include "version.h"

#include<string>
#include<vector>

//! A simple class to read csv files. Code borrowed from:
//! https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
class csvReader
{
private:
	std::vector<std::string> m_data;

public:
	csvReader();
	~csvReader();

	std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);
	std::string const& operator[](std::size_t index) const;
	std::size_t size() const;
	void readNextRow(std::istream& str);
};

std::istream& operator>>(std::istream& str, csvReader& data);
