#pragma once

// Helper for converting doubles to integers when sending over CAN
#include <assert.h>



//! Limit a uint64_t to the right number of bits
//
//! @param[in] value - the value before limitting
//! @param[in] numBits - num of bits in the output message
//! @return value limited in range [0, 2^numBits -1]
inline static uint64_t LimitUnsigned(uint64_t value, int numBits)
{
	uint64_t maxValue = ((uint64_t)0x1 << numBits) - 1;
	if (value > maxValue)
	{
		return maxValue;
	}
	
	return value;
}

//! Limit a int64_t to the right number of bits
//
//! @param[in] value - the value before limiting
//! @param[in] numBits - num of bits in the output message
//! @return value limited in range [-2^(numBits-1) - 1, 2^(numBits-1) - 1]
inline static int64_t LimitSigned(int64_t value, int numBits)
{
	int64_t maxValue = ((uint64_t)0x1 << (numBits-1)) - 1;
	if (value < -maxValue)
	{
		return -maxValue;
	}
	if (value > maxValue)
	{
		return maxValue;
	}

	return value;
}


//! Convert a double to uint64_t (unsigned)
//
//! @param[in] value - the value to round
//! @param[in] quantization - quantization step
//! @return the rounded value as unsigned
inline static uint64_t RoundUnsigned(double value, double quantization)
{
	assert(value >= 0);
	return (uint64_t)((value + (quantization/2)) / quantization);
}


//! Convert a double to uint64_t (unsigned) and limit to representable range
//
//! @param[in] value - the value to round
//! @param[in] quantization - quantization step
//! @param[in] numBits - num of bits in the output message
//! @return the rounded value as unsigned
inline static uint64_t RoundLimitUnsigned(double value, double quantization, int numBits)
{
	assert(value >= 0);
	uint64_t unlimited = RoundUnsigned(value, quantization);
	return LimitUnsigned(unlimited, numBits);
}

//! Convert a double to int64_t (signed)
//
//! @param[in] value - the value to round
//! @param[in] quantization - quantization step
//! @return the rounded value as signed
inline static int64_t RoundSigned(double value, double quantization)
{
	double rounding = (value >= 0) ? quantization / 2 : -quantization / 2;
	return (int64_t)((value + rounding) / quantization);
}

//! Convert a double to int64_t (signed) and limit to representable range
//
//! @param[in] value - the value to round
//! @param[in] quantization - quantization step
//! @param[in] numBits - num of bits in the output message
//! @return the rounded value as unsigned
inline static int64_t RoundLimitSigned(double value, double quantization, int numBits)
{
	int64_t unlimited = RoundSigned(value, quantization);
	return LimitSigned(unlimited, numBits);
}
