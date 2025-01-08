#pragma once

#include "Lumen/File/Path.hpp"

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
    Path RootDirectory;
    Path WorkingDirectory;
    Path AssetDirectory;
    Path StartScene;

public:
    Project() = default;
    Project(std::string name, std::string lastModified, Path rootDirectory,
            Path workingDirectory, Path assetDirectory, Path startScene);

    bool operator==(const Project &other) const;
};

} // namespace Lumen