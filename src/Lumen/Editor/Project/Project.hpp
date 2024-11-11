#pragma once

#include <filesystem>

namespace Lumen
{

struct ProjectConfig
{
    std::string Name = "Untitled";
    std::filesystem::path RootDirectory;
    std::filesystem::path AssetDirectory;
    std::filesystem::path StartScene;

    ProjectConfig() = default;
};

class Project
{
public:
    Project(ProjectConfig config);

    inline ProjectConfig &GetConfig();
    inline bool operator==(const Project &other) const;

private:
    ProjectConfig m_Config;
};

ProjectConfig &Project::GetConfig()
{
    return m_Config;
}

bool Project::operator==(const Project &other) const
{
    return m_Config.Name == other.m_Config.Name &&
           m_Config.RootDirectory == other.m_Config.RootDirectory;
}

} // namespace Lumen