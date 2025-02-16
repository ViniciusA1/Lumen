#include "Lumen/Project/ProjectSerializer.hpp"

#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool ProjectSerializer::Deserialize(Project &project, const Path &path)
{
    Path configPath = path / "config/ProjectConfig.lproj";

    Yaml yaml = Yaml::FromFile(configPath);
    if (yaml.IsNull())
        return false;

    yaml >> project;
    project.RootDirectory = path;

    return true;
}

bool ProjectSerializer::Serialize(const Project &project, const Path &path)
{
    Path configPath = path / "ProjectConfig.lproj";

    Yaml yaml;
    yaml << project;
    return yaml.ToFile(configPath);
}

} // namespace Lumen