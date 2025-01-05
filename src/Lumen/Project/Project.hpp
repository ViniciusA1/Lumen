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
    Path AssetDirectory;
    Path StartScene;

public:
    Project() = default;
    Project(std::string Name, std::string LastModified, Path RootDirectory,
            Path AssetDirectory, Path StartScene);

    bool operator==(const Project &other) const;
};

} // namespace Lumen