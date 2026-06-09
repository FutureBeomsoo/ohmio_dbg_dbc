#pragma once
#include "version.h"

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>

//! Helper for writing JSON output using rapidjson
namespace JasonHelper
{
	//! Scoped object writer. The constructor starts an object on the writer. The destructor ends the object
	//! Note that the top most object has to be unnamed and any other object must have a name
	class JasonWriteObjectHelper
	{
	public:
		JasonWriteObjectHelper(rapidjson::Writer<rapidjson::StringBuffer>& writer, std::string name);
		~JasonWriteObjectHelper();

	private:
		rapidjson::Writer<rapidjson::StringBuffer>& m_writer;
	};

	//! Scoped array writer. The constructor starts an array on the writer. The destructor ends the array.
	//! Note that array requires a name
	class JasonWriteArrayHelper
	{
	public:
		JasonWriteArrayHelper(rapidjson::Writer<rapidjson::StringBuffer>& writer, std::string name);
		~JasonWriteArrayHelper();

	private:
		rapidjson::Writer<rapidjson::StringBuffer>& m_writer;
	};
}


