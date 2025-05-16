#pragma once

#include "Lumen/Core/Enum.hpp"

namespace Lumen
{

enum class WindowFlags
{
    VSyncHint = 0x00000040,
    FullScreenMode = 0x00000002,
    Resizable = 0x00000004,
    Undecorated = 0x00000008,
    Hidden = 0x00000080,
    Minimized = 0x00000200,
    Maximized = 0x00000400,
    Unfocused = 0x00000800,
    TopMost = 0x00001000,
    AlwaysRun = 0x00000100,
    Transparent = 0x00000010,
    HighDPI = 0x00002000,
    MousePassThrough = 0x00004000,
    BorderlessWindowedMode = 0x00008000,
    MSAA4xHint = 0x00000020,
    InterlacedHint = 0x00010000
};

ENUM_ENABLE_BITMASK(WindowFlags)

} // namespace Lumen