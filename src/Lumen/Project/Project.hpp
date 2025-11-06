#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Scene/SceneType.hpp"

namespace Lumen
{

enum class ProjectSortOption
{
    LastModified,
    Name
};

class Project
{
public:
    std::string Name;
    std::string LastModified;
    SceneType Type;
    Path RootDirectory;
    Path WorkingDirectory;
    Path ConfigDirectory;
    Path AssetDirectory;
    Path SceneDirectory;
    Path StartScene;

public:
    [[nodiscard]] bool IsValid() const;

    bool operator==(const Project &other) const;
};

} // namespace Lumen