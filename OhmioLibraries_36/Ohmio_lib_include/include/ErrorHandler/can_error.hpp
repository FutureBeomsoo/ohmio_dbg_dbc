#pragma once


extern "C"
{
	#include "canbus/dbc_CAN.h"
}
#include <bitset>
#include <map>

#include "canbus/RosMessages.hpp"

#define stringify( name ) # name

//! Error code management for the obstacle system
class ObstacleErrorCodes
{
public:
	ObstacleErrorCodes()
	{ 
		static_assert(25 == ObstaclePCErrorCode::Obstacle_NumErrorCodes, "Need to have all the error bits here");

		m_allErrors.push_back(stringify(Obstacle_front_left_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_front_top_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_front_right_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_rear_left_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_rear_top_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_rear_right_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_CAN_localisation_msg_));
		m_allErrors.push_back(stringify(Obstacle_transform_broadcaster_));
		m_allErrors.push_back(stringify(Obstacle_CAN_wheel_speed_msg_));
		m_allErrors.push_back(stringify(Obstacle_CAN_front_steering_msg_));
		m_allErrors.push_back(stringify(Obstacle_CAN_back_steering_msg_));
		m_allErrors.push_back(stringify(Obstacle_ground_segmentation_msg_));
		m_allErrors.push_back(stringify(Obstacle_obstacle_map_msg_));
		m_allErrors.push_back(stringify(Obstacle_path_planning_msg_));
		m_allErrors.push_back(stringify(Obstacle_collision_distance_msg_));
		m_allErrors.push_back(stringify(Obstacle_emergency_envelope_msg_));
		m_allErrors.push_back(stringify(Obstacle_lidar_calibration_msg_));
		m_allErrors.push_back(stringify(Obstacle_multiple_lidar_fault));
		m_allErrors.push_back(stringify(Obstacle_map_source_missing));
		m_allErrors.push_back(stringify(Obstacle_map_multiple_missing));
		m_allErrors.push_back(stringify(Obstacle_dangerous_parameter));
		m_allErrors.push_back(stringify(Obstacle_Heartbeat_detection));
		m_allErrors.push_back(stringify(Obstacle_wp_mismatch));
		m_allErrors.push_back(stringify(Obstacle_track_mismatch));
		m_allErrors.push_back(stringify(Obstacle_drv_info_comms));
		MapCodes();

		m_LidarFaultErrors.insert(FromEnum(Obstacle_front_left_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_front_top_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_front_right_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_rear_left_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_rear_top_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_rear_right_lidar_fault));
		m_LidarFaultErrors.insert(FromEnum(Obstacle_multiple_lidar_fault));

		m_LidarFaultBits.insert(Obstacle_front_left_lidar_fault);
		m_LidarFaultBits.insert(Obstacle_front_top_lidar_fault);
		m_LidarFaultBits.insert(Obstacle_front_right_lidar_fault);
		m_LidarFaultBits.insert(Obstacle_rear_left_lidar_fault);
		m_LidarFaultBits.insert(Obstacle_rear_top_lidar_fault);
		m_LidarFaultBits.insert(Obstacle_rear_right_lidar_fault);
	}

	//! to help with testing
	size_t GetNumStrings()
	{
		return m_allErrors.size();
	}

	std::vector<std::string> getAllErrorStrings()
	{
		return m_allErrors;
	}
	
	//! Get a string from a single bit error code 
	//
	//! @param[in] bitCode - only a single bit should be 1 the rest are 0
	//! @return the error code as a string
	std::string FromCode(uint64_t bitCode)
	{
		if (m_codesToStrings.end() == m_codesToStrings.find(bitCode))
		{ // not found
			return "";
		}
		return m_codesToStrings[bitCode];
	}

	//! Get a string from an error flag enum
	//
	//! @param[in] errorCode - the error enum value
	//! @return the error code as a string
	std::string FromEnum(ObstaclePCErrorCode errorEnum)
	{
		return FromCode(ToCode(errorEnum));
	}

	//! Get a list of all the messages indicated by a code 
	//
	//! Gets all the single bit codes and convert each to a string
	//! @param[in] code - the 64 bits codes
	//! @param[out] strings - all the errors as strings
	void FromCode(uint64_t code, std::vector<std::string>& strings)
	{
		strings.clear();
		uint64_t mask = 0x1;
		for (size_t i = 0; i < 64; ++i)
		{
			uint64_t theBit = code & mask;
			if (0 != theBit)
			{
				std::string asString = FromCode(theBit);
				if (!asString.empty())
				{
					strings.push_back(asString);
				}
			}
			mask = mask << 1; // next bit
		}
	}

	//! convert an error string to a 64 bit code
	//
	//! @param[in] errorString - the error string. Must be identical to 
	//! one of the strings in m_allErrors (including case)
	//! @return the corresponding error code or 0 if no match found
	uint64_t ToCode(const std::string& errorString)
	{
		if (m_stringsToCodes.end() == m_stringsToCodes.find(errorString))
		{ // not found
			return 0;
		}
		return m_stringsToCodes[errorString];
	}

	//! convert error strings to a 64 bit code
	//
	//! @param[in] errorStrings - a vector of the error strings. Must be identical to 
	//! one of the strings in m_allErrors (including case)
	//! @return the corresponding error code or 0 if no match found
	uint64_t ToCode(const std::vector<std::string>& errorStrings)
	{
		uint64_t error_code = 0;
		for (const auto& elem : errorStrings)
		{
			error_code = error_code | ToCode(elem);
		}
		return error_code;
	}

	//! convert error strings to a 64 bit code
	//
	//! @param[in] errorStrings - a set of the error strings. Must be identical to 
	//! one of the strings in m_allErrors (including case)
	//! @return the corresponding error code or 0 if no match found
	uint64_t ToCode(const std::set<std::string>& errorStrings)
	{
		uint64_t error_code = 0;
		for (const auto& elem : errorStrings)
		{
			error_code = error_code | ToCode(elem);
		}
		return error_code;
	}

	//! convert an error enum to a 64 bit code
	//
	//! @param[in] errorCode - the error code
	//! @return the corresponding error code or 0 if no match found
	uint64_t ToCode(ObstaclePCErrorCode errorCode)
	{
		return uint64_t(1) << errorCode;
	}

	//! convert multiple error enum to a 64 bit code
	//
	//! @param[in] errorCodes - a vector of the error codes. 
	//! @return the corresponding error code or 0 if no match found
	uint64_t ToCode(const std::vector<ObstaclePCErrorCode>& errorCodes)
	{
		uint64_t error_code = 0;
		for (const auto& elem : errorCodes)
		{
			error_code = error_code | ToCode(elem);
		}
		return error_code;
	}

	//! Is an error string a lidar fault?
	bool IsLidarFault(std::string errorString)
	{
		return (m_LidarFaultErrors.end() != m_LidarFaultErrors.find(errorString));
	}

	void fixMultiLidarFaultBit(uint64_t& bits)
	{
		int NumFaultyLiDARs = 0;
		for (auto bit : m_LidarFaultBits)
		{
			if ((bits & (uint64_t(1) << bit)) != 0)
		    {
			    NumFaultyLiDARs++;
		    }
		}
		if (NumFaultyLiDARs > 1)
		{
			bits = bits | (uint64_t(1) << Obstacle_multiple_lidar_fault);
		}
	}

private:
	void MapCodes()
	{
		uint64_t code = 0x1;
		for (size_t i = 0; i < m_allErrors.size(); ++i)
		{
			std::string& txt = m_allErrors[i];
			m_codesToStrings.insert(std::make_pair(code, txt));
			m_stringsToCodes.insert(std::make_pair(txt, code));
			code = code << 1; // next bit
		}
	}

private:
	std::set<std::string> m_LidarFaultErrors;	//!< a list of the error messages indicating lidar fault
	std::set<ObstaclePCErrorCode> m_LidarFaultBits;
	std::vector<std::string> m_allErrors;		//!< a list of all the error messages
	std::map<uint64_t, std::string> m_codesToStrings;	//!< to translate from an error code to string
	std::map<std::string, uint64_t> m_stringsToCodes;	//!< to translate from a string to n error code
};
