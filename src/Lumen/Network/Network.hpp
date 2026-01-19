#pragma once

namespace Lumen
{

class Network
{
public:
    Network() = delete;

public:
    static void Init();
    static void Shutdown();
};

} // namespace Lumen