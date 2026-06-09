// Keep track of the min, max and average times for a timed
// section

#pragma once
#include "version.h"
#include <cmath> // TODO should move to some common incvlude

namespace NTiming_NS
{
	class MinMaxAvgTime
	{
	public:
		MinMaxAvgTime()
		{
			Reset();
		}
		virtual ~MinMaxAvgTime() {}

		void Reset()
		{
			Min = 1000000;
			Max = 0;
			m_Sum = 0;
			m_SumSquare = 0;
			m_NumberOfSamplesForAverage = 0;
		}

		void AddTime(double time)
		{
			if (time < Min)
			{
				Min = time;
			}
			if (time > Max)
			{
				Max = time;
			}
			m_Sum += time;
			m_SumSquare += (time*time);
			m_NumberOfSamplesForAverage++;
		}

		unsigned long GetNumberOfSamples()
		{
			return m_NumberOfSamplesForAverage;
		}

		double GetAverage()
		{
			if (m_NumberOfSamplesForAverage > 0)
			{
				return m_Sum / m_NumberOfSamplesForAverage;
			}
			return 0.0;
		}

		double GetStd()
		{
			if (m_NumberOfSamplesForAverage > 0)
			{
				double meanSquare = m_SumSquare / m_NumberOfSamplesForAverage;
				double mean = m_Sum / m_NumberOfSamplesForAverage;
				double var = meanSquare - mean * mean;
				return std::sqrt(var);
			}
			return 0.0;

		}

		double GetMin()
		{
			return Min;
		}

		double GetMax()
		{
			return Max;
		}

		double GetSum()
		{
			return m_Sum;
		}

	private:
		double Min;
		double Max;
		double m_Sum;
		double m_SumSquare;
		unsigned long m_NumberOfSamplesForAverage;
	};

}
