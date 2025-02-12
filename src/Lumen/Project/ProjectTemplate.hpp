#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Scene/SceneType.hpp"

namespace Lumen
{

class ProjectTemplate
{
public:
    std::string Name;
    std::string Description;
    SceneType Type;

    Path RootDirectory;
    Path WorkingDirectory;
    Path AssetDirectory;
    Path StartScene;

public:
    bool operator==(const ProjectTemplate &other) const;
};

} // namespace Lumen