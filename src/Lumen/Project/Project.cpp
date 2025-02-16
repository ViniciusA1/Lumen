#include "Lumen/Project/Project.hpp"

namespace Lumen
{

Project::Project(std::string name, std::string lastModified, SceneType type,
                 Path rootDirectory, Path workingDirectory, Path configDirectory,
                 Path assetDirectory, Path startScene)
    : Name(std::move(name)), LastModified(std::move(lastModified)), Type(type),
      RootDirectory(std::move(rootDirectory)),
      WorkingDirectory(std::move(workingDirectory)),
      ConfigDirectory(std::move(configDirectory)),
      AssetDirectory(std::move(assetDirectory)), StartScene(std::move(startScene))
{
}

bool Project::IsValid() const
{
    return !Name.empty();
}

bool Project::operator==(const Project &other) const
{
    return Name == other.Name && RootDirectory == other.RootDirectory;
}

} // namespace Lumen