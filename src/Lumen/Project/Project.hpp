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
    std::string Name = "Untitled";
    std::string LastModified;
    SceneType Type;
    Path RootDirectory;
    Path WorkingDirectory;
    Path AssetDirectory;
    Path StartScene;

public:
    Project() = default;
    Project(std::string name, std::string lastModified, SceneType type,
            Path rootDirectory, Path workingDirectory, Path assetDirectory,
            Path startScene);

    bool operator==(const Project &other) const;
};

} // namespace Lumen