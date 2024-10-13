#include "Lumen/Core/Time.hpp"
#include <raylib.h>

namespace Lumen
{

void Time::Wait(double seconds)
{
    ::WaitTime(seconds);
}

double Time::GetTime()
{
    return ::GetTime();
}

float Time::GetDeltaTime()
{
    return ::GetFrameTime();
}

} // namespace Lumen