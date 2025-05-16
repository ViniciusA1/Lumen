#pragma once

#include "Lumen/Core/WindowFlags.hpp"
#include "Lumen/Graphics/Texture.hpp"

#include <string>

namespace Lumen
{

struct WindowArgs
{
    std::string Title = "Application";
    int Width = 1280;
    int Height = 720;
    Texture2D Icon;
    WindowFlags Flags = WindowFlags::Resizable;
    int TargetFPS = 60;
};

} // namespace Lumen