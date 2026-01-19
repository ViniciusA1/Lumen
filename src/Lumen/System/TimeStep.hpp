#pragma once

namespace Lumen
{

class TimeStep
{
public:
    constexpr explicit TimeStep(float time = 0.0f);

    [[nodiscard]] constexpr float GetSeconds() const;
    [[nodiscard]] constexpr float GetMilliseconds() const;

    constexpr TimeStep operator+(TimeStep other) const;
    constexpr TimeStep operator-(TimeStep other) const;
    constexpr TimeStep operator*(float scalar) const;
    constexpr TimeStep operator/(float scalar) const;

    constexpr TimeStep &operator+=(TimeStep other);
    constexpr TimeStep &operator-=(TimeStep other);
    constexpr TimeStep &operator*=(float scalar);
    constexpr TimeStep &operator/=(float scalar);

    constexpr bool operator==(const TimeStep &other) const;
    constexpr bool operator!=(const TimeStep &other) const;
    constexpr bool operator>(const TimeStep &other) const;
    constexpr bool operator<(const TimeStep &other) const;
    constexpr bool operator>=(const TimeStep &other) const;
    constexpr bool operator<=(const TimeStep &other) const;

private:
    float m_Time;
};

} // namespace Lumen

#include "Lumen/System/TimeStep.inl"