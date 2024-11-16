#include "Lumen/Editor/Project/ProjectManager.hpp"
#include "Lumen/Editor/Project/ProjectSerializer.hpp"
#include "Lumen/File/FileSystem.hpp"
#include <algorithm>

namespace Lumen
{

Project ProjectManager::s_ActiveProject = ProjectConfig{};
std::vector<Project> ProjectManager::s_ProjectList;

void ProjectManager::New(const Path &path, const std::string &name)
{
    ProjectConfig config = {name.empty() ? path.GetStem().ToString() : name, path,
                            path / "Assets", path / "Scenes" / "Main.scene"};

    FileSystem::CreateDirectories(config.AssetDirectory / "Scenes");

    Project newProject = {config};
    s_ProjectList.push_back(newProject);
    Save(newProject);
    SaveProjectList();
}

void ProjectManager::Load(const Path &path)
{
    if (IsLoaded(path))
    {
        return;
    }

    Project loadedProject({});
    ProjectSerializer serializer;

    if (serializer.DeserializeProject(loadedProject, path))
    {
        s_ProjectList.push_back(loadedProject);
        SaveProjectList();
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
        FileSystem::RemoveAll(project.GetConfig().RootDirectory);
        s_ProjectList.erase(it);
        SaveProjectList();
    }
}

bool ProjectManager::IsLoaded(const Path &path)
{
    for (const auto &project : s_ProjectList)
    {
        if (project.GetConfig().RootDirectory == path)
        {
            return true;
        }
    }

    return false;
}

void ProjectManager::LoadProjectList()
{
    ProjectSerializer serializer;
    if (serializer.DeserializeProjectList(s_ProjectList, {"."}))
    {
    }
}

void ProjectManager::SaveProjectList()
{
    ProjectSerializer serializer;
    if (serializer.SerializeProjectList(s_ProjectList, {"."}))
    {
    }
}

void ProjectManager::SortProjectList(ProjectSortOption sortOption)
{
    switch (sortOption)
    {
    case ProjectSortOption::LastModified:
        std::sort(s_ProjectList.begin(), s_ProjectList.end(),
                  [](const Project &a, const Project &b) {
                      return a.GetConfig().LastModified < b.GetConfig().LastModified;
                  });
        break;
    case ProjectSortOption::Name:
        std::sort(s_ProjectList.begin(), s_ProjectList.end(),
                  [](const Project &a, const Project &b) {
                      return a.GetConfig().Name < b.GetConfig().Name;
                  });
        break;
    }
}

} // namespace Lumen