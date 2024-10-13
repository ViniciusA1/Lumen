#pragma once

namespace Lumen
{

class Time
{
public:
    Time() = delete;

    static void Wait(double seconds);
    static double GetTime();
    static float GetDeltaTime();
};

} // namespace Lumen