#pragma once

#include "Lumen/System/TimeStep.hpp"

namespace Lumen
{

class Time
{
public:
    Time() = delete;

public:
    static void Wait(double seconds);
    static TimeStep GetTime();
    static TimeStep GetDeltaTime();
};

} // namespace Lumen