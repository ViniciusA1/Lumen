#include "Lumen/Editor/Project/Project.hpp"

namespace Lumen
{

ProjectConfig::ProjectConfig(std::string name, Path rootDir, Path assetDir,
                             Path startScene)
    : Name(std::move(name)), RootDirectory(std::move(rootDir)),
      AssetDirectory(std::move(assetDir)), StartScene(std::move(startScene))
{
}

Project::Project(ProjectConfig config) : m_Config(std::move(config))
{
}

} // namespace Lumen