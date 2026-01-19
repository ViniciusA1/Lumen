#include "Lumen/System/Time.hpp"

#include "raylib.h"

namespace Lumen
{

void Time::Wait(double seconds)
{
    ::WaitTime(seconds);
}

TimeStep Time::GetTime()
{
    return TimeStep(::GetTime());
}

TimeStep Time::GetDeltaTime()
{
    return TimeStep(::GetFrameTime());
}

} // namespace Lumen