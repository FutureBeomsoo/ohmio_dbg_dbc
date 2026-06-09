
#ifndef OHMIO_MD5_CALCULATOR_H
#define OHMIO_MD5_CALCULATOR_H
#include <stdint.h>
#define OHMIO_MD5_CALCULATOR_VERSION 1



static int getHashCalculationVersion()
{
   return OHMIO_MD5_CALCULATOR_VERSION;
}

//! Calculate some approximation of MD5 code
//
//! Note that this does not implement the true MD5 algorithm.
//! instead we use KBDR hash http://www.partow.net/programming/hashfunctions/#BKDRHashFunction
//! \n<B>Warning</B>. If you call with a temporary variable the optimizer may optimise out 
//! the variable and the results are wrong. Adding <B>volatile</B> to the temp variable declaration may help. 
//! \code{.cpp}
//!		// This code works with Microsoft compiler but fails with GCC
//!		uint64_t onTheFlyMd5 = 0;
//!		const int pointSize = sizeof(WAY_POINT_LOC_t) / 4;
//!		std::vector<WAY_POINT_LOC_t> track(numPoints);
//!		for (int i = 0; i < numPoints; ++i)
//!		{
//!			WAY_POINT_LOC_t wp;
//!			wp.latitude = values[2 * i];
//!			wp.longitude = values[2 * i + 1];
//!			onTheFlyMd5 = hashCalculation((uint32_t *)&wp, pointSize, onTheFlyMd5);
//!		}
//!		ASSERT_EQ(onTheFlyMd5, MD5Loc); // pass on Microsoft comiler, fails with GCC
//! \endcode
//! \code{.cpp}
//!		// When we add volatile GCC is happy but still it failed in the docker installation used for CI build
//!		uint64_t onTheFlyMd5 = 0;
//!		const int pointSize = sizeof(WAY_POINT_LOC_t) / 4;
//!		std::vector<WAY_POINT_LOC_t> track(numPoints);
//!		for (int i = 0; i < numPoints; ++i)
//!		{
//!			volatile WAY_POINT_LOC_t wp;
//!			wp.latitude = values[2 * i];
//!			wp.longitude = values[2 * i + 1];
//!			onTheFlyMd5 = hashCalculation((uint32_t *)&wp, pointSize, onTheFlyMd5);
//!		}
//!		ASSERT_EQ(onTheFlyMd5, MD5Loc); // pass on Microsoft comiler and GCC, Failed in CI build
//! \endcode
//! \code{.cpp}
//!		// This code worked in all the conditions we tried 
//!		uint64_t onTheFlyMd5 = 0;
//!		const int pointSize = sizeof(WAY_POINT_LOC_t) / 4;
//!		std::vector<WAY_POINT_LOC_t> track(numPoints);
//!		for (int i = 0; i < numPoints; ++i)
//!		{
//!			onTheFlyMd5 = hashCalculation((uint32_t *)&values[2 * i], pointSize, onTheFlyMd5);
//!		}
//!		ASSERT_EQ(onTheFlyMd5, MD5Loc); // pass on all environments I tried on
//! \endcode
//! \code{.cpp}
//!		// much simpler. Just call once for the entire vector 
//!		// Note that we call with values.size() * 2 because a double is 8 bytes 
//!		std::vector<double> values; // Need to initilaize to somrthing
//!		uint64_t oneGo = hashCalculation((uint32_t *)&values[0], values.size() * 2, 0);
//!		ASSERT_EQ(PointsMD5, oneGo); // pass on all environments I tried on
//! \endcode
//! \code{.cpp}
//!		// Call for each value not needing to generate temp variables 
//!		// Note that we call with size = 2 because a double is 8 bytes 
//!		std::vector<double> values; // Need to initilaize to somrthing
//!		uint64_t singleValues = 0;
//!		for (size_t i = 0; i < values.size(); ++i)
//!		{
//!			singleValues = hashCalculation((uint32_t *)&values[i], 2, singleValues);
//!		}
//!		ASSERT_EQ(singleValues, MD5Loc); // should be the same as we got from the file
//! \endcode
//! @param[in] data - pointer to the begining of the data to calculate for
//! @param[in] length - length of data (in 4 BYTE units)
//! @param[in] currentHash - current value of the hash before adding this data
//! @return - the updated hash code
static uint64_t hashCalculation(uint32_t *data, int length, uint64_t currentHash)
{
	uint64_t p;
	uint32_t seed = 131;
	uint32_t *ptr;
	uint32_t temp;
	uint64_t hash = currentHash;

	// calculate MD5
	ptr = data;
	for (p = 0; p < length; p++)
	{
		temp = *ptr;
		hash = (hash * seed) + temp;
		ptr++;
	}

	return hash;
}

//! Calculate 8 bits crc code
//
//! from https://stackoverflow.com/questions/51752284/how-to-calculate-crc8-in-c
//! @param[in] data - pointer to the 1st byte of data
//! @param[in] length - number of bytes in the data
//! @param[in] padding - add extra bytes with 0 at the end of the data.
//! this is used when sending data in fixed size packets and the last packet
//! is not full. One party might have 0 padded data and the other not
static uint8_t CalculateCrc8(uint8_t *data, int length, int padding)
{
	uint8_t crc = 0xff;
	uint64_t i, j;
	uint8_t *ptr;
	ptr = data;
	uint64_t numberToCount = (uint64_t)length + (uint64_t)padding;

	for (i = 0; i < numberToCount; i++)
	{
		if (i < length)
		{
			crc ^= *ptr;
			ptr++;
		}
		for (j = 0; j < 8; j++) 
		{
			if ((crc & 0x80) != 0)
				crc = (uint8_t)((crc << 1) ^ 0x31);
			else
				crc <<= 1;
		}
	}
	return crc;
}

//! Calculate 16 bits crc code
//
//! from https://stackoverflow.com/questions/10564491/function-to-calculate-a-crc16-checksum
//! @param[in] data - pointer to the 1st byte of data
//! @param[in] length - number of bytes in the data
//! @param[in] padding - add extra bytes with 0 at the end of the data.
//! this is used when sending data in fixed size packets and the last packet
//! is not full. One party might have 0 padded data and the other not
static uint16_t CalculateCrc16(uint8_t *data, int length, int padding)
{
	uint8_t x;
	uint16_t crc = 0xFFFF;
	uint8_t *ptr;
	uint64_t i;
	ptr = data;

	uint64_t numberToCount = (uint64_t)length + (uint64_t)padding;

	for (i = 0; i < numberToCount; i++)
	{
		x = crc >> 8;
		if (i < length)
		{
			x = x ^ *ptr;
			ptr++;
		}
		x ^= x >> 4;
		crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x << 5)) ^ ((unsigned short)x);
	}
	return crc;
}

#endif // OHMIO_MD5_CALCULATOR_H
