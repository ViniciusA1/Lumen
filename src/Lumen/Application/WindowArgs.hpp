#pragma once

#include "Lumen/Application/WindowFlags.hpp"
#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Math/Vector2.hpp"

#include <string>

namespace Lumen
{

struct WindowArgs
{
    std::string Title = "Application";
    Vector2 Resolution = {1280, 720};
    AssetHandle Icon;
    WindowFlags Flags = WindowFlags::Resizable;
    int TargetFPS = 60;
};

} // namespace Lumen