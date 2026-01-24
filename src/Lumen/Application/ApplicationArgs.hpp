#pragma once

#include "ApplicationMode.hpp"
#include "Lumen/Application/WindowFlags.hpp"
#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/File/Path.hpp"
#include "Lumen/Math/Vector2.hpp"

#include <string>

namespace Lumen
{

struct ApplicationArgs
{
    std::string Title = "Application";
    Vector2 Resolution = {1280, 720};
    AssetHandle Icon;
    WindowFlags Flags = WindowFlags::Resizable;
    int TargetFPS = 60;
    ApplicationMode Mode = ApplicationMode::None;
    Path RootDirectory;
    Path AssetDirectory;
    Path StartScene;

    [[nodiscard]] bool IsValid() const
    {
        return Mode != ApplicationMode::None && !RootDirectory.IsEmpty();
    }
};

} // namespace Lumen