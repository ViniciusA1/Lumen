#pragma once

namespace Lumen
{

class UI
{
public:
    static void Init();
    static void Shutdown();

    static void Begin();
    static void End();
};

} // namespace Lumen