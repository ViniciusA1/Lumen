#pragma once

#include "Lumen/File/Path.hpp"

namespace Lumen
{

struct ProjectConfig
{
    std::string Name = "Untitled";
    std::string LastModified;
    Path RootDirectory;
    Path AssetDirectory;
    Path StartScene;

    ProjectConfig() = default;
    ProjectConfig(std::string name, Path rootDir, Path assetDir, Path startScene);
};

enum class ProjectSortOption
{
    LastModified,
    Name
};

class Project
{
public:
    Project(ProjectConfig config);

    inline ProjectConfig &GetConfig();
    [[nodiscard]] inline ProjectConfig GetConfig() const;
    inline bool operator==(const Project &other) const;

private:
    ProjectConfig m_Config;
};

ProjectConfig &Project::GetConfig()
{
    return m_Config;
}

inline ProjectConfig Project::GetConfig() const
{
    return m_Config;
}

bool Project::operator==(const Project &other) const
{
    return m_Config.Name == other.m_Config.Name &&
           m_Config.RootDirectory == other.m_Config.RootDirectory;
}

} // namespace Lumen