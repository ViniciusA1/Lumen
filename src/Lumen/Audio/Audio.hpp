#pragma once

namespace Lumen
{

class Audio
{
public:
    Audio() = delete;

public:
    static void Init();
    static void Shutdown();
};

} // namespace Lumen