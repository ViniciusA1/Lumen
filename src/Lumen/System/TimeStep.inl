#pragma once

#include "Lumen/System/TimeStep.hpp"

namespace Lumen
{

constexpr TimeStep::TimeStep(float time) : m_Time(time)
{
}

constexpr float TimeStep::GetSeconds() const
{
    return m_Time / 1000.0f;
}

constexpr float TimeStep::GetMilliseconds() const
{
    return m_Time;
}

constexpr TimeStep TimeStep::operator+(TimeStep other) const
{
    return TimeStep(m_Time + other.m_Time);
}

constexpr TimeStep TimeStep::operator-(TimeStep other) const
{
    return TimeStep(m_Time - other.m_Time);
}

constexpr TimeStep TimeStep::operator*(float scalar) const
{
    return TimeStep(m_Time * scalar);
}

constexpr TimeStep TimeStep::operator/(float scalar) const
{
    return TimeStep(m_Time / scalar);
}

constexpr TimeStep &TimeStep::operator+=(TimeStep other)
{
    m_Time += other.m_Time;
    return *this;
}

constexpr TimeStep &TimeStep::operator-=(TimeStep other)
{
    m_Time -= other.m_Time;
    return *this;
}

constexpr TimeStep &TimeStep::operator*=(float scalar)
{
    m_Time *= scalar;
    return *this;
}

constexpr TimeStep &TimeStep::operator/=(float scalar)
{
    m_Time /= scalar;
    return *this;
}

constexpr bool TimeStep::operator==(const TimeStep &other) const
{
    return m_Time == other.m_Time;
}

constexpr bool TimeStep::operator!=(const TimeStep &other) const
{
    return m_Time != other.m_Time;
}

constexpr bool TimeStep::operator>(const TimeStep &other) const
{
    return m_Time > other.m_Time;
}

constexpr bool TimeStep::operator<(const TimeStep &other) const
{
    return m_Time < other.m_Time;
}

constexpr bool TimeStep::operator>=(const TimeStep &other) const
{
    return m_Time >= other.m_Time;
}

constexpr bool TimeStep::operator<=(const TimeStep &other) const
{
    return m_Time <= other.m_Time;
}

} // namespace Lumen
