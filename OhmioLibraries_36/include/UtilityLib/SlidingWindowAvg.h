#pragma once
#include "version.h"
namespace MathHelper
{
	//! Calculate sliding window avearge
	class SlidingWindowAvg
	{
	public:
		//! Calculate the sliding window average
		//
		//! For every point out[i] = 1/filterHalfSize * sum{ in[i-filterHalfSize], .. in[i + filterHalfSize]}.
		//! For now edge locations (i < filterHalfSize) and (i < in.size() - filterHalfSize) are not 
		//! filtered at all.
		//! @param[in,out] filtered - the unfiltered data in and the filtred data out
		//! @param[in] filterHalfSize - size of the filter
		template <class T> void CalculateSlidingAverage(std::vector<T>& filtered, size_t filterHalfSize)
		{
			if (filtered.size() <= filterHalfSize * 2)
			{	// no data to work with
				return;
			}

			std::vector<T> unfiltered;
			CopyInput(filtered, unfiltered);
			T initialSum = CalculateInitialSum(unfiltered, filterHalfSize);
			Slide(filtered, unfiltered, filterHalfSize, initialSum);
		}

	private: 
		template <class T> void CopyInput(const std::vector<T>& filtered, std::vector<T>& unfiltered)
		{
			unfiltered.clear();
			unfiltered.insert(unfiltered.begin(), filtered.begin(), filtered.end());
		}

		template <class T> T CalculateInitialSum(const std::vector<T>& unfiltered, size_t filterHalfSize)
		{
			T sum = 0;
			for (size_t i = 0; i <= filterHalfSize * 2; ++i)
			{
				sum += unfiltered[i];
			}

			return sum;
		}

		template <class T> void Slide(std::vector<T>& filtered, const std::vector<T>& unfiltered, size_t filterHalfSize, T initialSum)
		{
			T sum = initialSum;
			const double mulitplier = 1.0 / (filterHalfSize * 2 + 1);
			for (size_t i = filterHalfSize; i < filtered.size() - filterHalfSize; ++i)
			{
				filtered[i] = (T)(sum * mulitplier); // get the average
				// slide
				sum -= unfiltered[i - filterHalfSize];
				size_t lastIdx = i + filterHalfSize + 1;
				if (lastIdx < unfiltered.size())
				{
					sum += unfiltered[lastIdx];
				}
			}
		}

	};	
}