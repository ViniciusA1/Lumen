#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "ProjectSerializer.hpp"
#include <algorithm>
#include <filesystem>

namespace Lumen
{

Project ProjectManager::s_ActiveProject = ProjectConfig{};
std::vector<Project> ProjectManager::s_ProjectList;

void ProjectManager::New(const std::filesystem::path &path, const std::string &name)
{
    ProjectConfig config = {.Name = name.empty() ? path.stem().string() : name,
                            .RootDirectory = path,
                            .AssetDirectory = path / "Assets",
                            .StartScene = path / "Scenes" / "Main.scene"};

    std::filesystem::create_directories(config.AssetDirectory);
    std::filesystem::create_directories(config.AssetDirectory / "Scenes");

    s_ActiveProject = {config};
    s_ProjectList.emplace_back(config);

    Save();
}

void ProjectManager::Load(const std::filesystem::path &path)
{
    Project loadedProject({});
    ProjectSerializer serializer;

    if (serializer.DeserializeProject(loadedProject, path))
    {
        s_ActiveProject = loadedProject;
    }
}

void ProjectManager::Save(Project &project)
{
    ProjectSerializer serializer;
    if (serializer.SerializeProject(project, project.GetConfig().RootDirectory))
    {
    }
}

void ProjectManager::Delete(Project &project)
{
    auto it = std::find(s_ProjectList.begin(), s_ProjectList.end(), project);
    if (it != s_ProjectList.end())
    {
        s_ProjectList.erase(it);
    }
}

void ProjectManager::LoadProjectList()
{
    ProjectSerializer serializer;
    if (serializer.DeserializeProjectList(s_ProjectList, "."))
    {
    }
}

void ProjectManager::SaveProjectList()
{
    ProjectSerializer serializer;
    if (serializer.SerializeProjectList(s_ProjectList, "."))
    {
    }
}

} // namespace Lumen