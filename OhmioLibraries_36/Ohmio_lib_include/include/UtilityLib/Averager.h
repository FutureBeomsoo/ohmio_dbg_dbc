#pragma once

namespace MathHelper
{

//! Helper for calculating mean
class Averager
{
public:
    //! clears the counter but leaves the existing value
    //! next add() will replace it
    void resetCount()
    {
        m_n = 0;
    }

    void add(double x)
    {
        m_n += 1.0;
        m_mean += (x - m_mean) / m_n;
    }

    void add(const Averager& other)
    {
        m_n += other.m_n;
        if (m_n > 0.0)
        {
            m_mean += (other.m_mean - m_mean) * other.m_n / m_n;
        }
    }

    double getMean() const { return m_mean; }

private:
    double m_n{0.0};
    double m_mean{0.0};
};

}