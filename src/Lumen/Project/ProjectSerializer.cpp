#include "Lumen/Project/ProjectSerializer.hpp"

#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool ProjectSerializer::Deserialize(Project &project, const Path &path)
{
    Yaml yaml = Yaml::FromFile(path);
    if (yaml.IsNull())
        return false;

    yaml >> project;
    project.RootDirectory = path.ParentPath().ParentPath();

    return true;
}

bool ProjectSerializer::Serialize(const Project &project, const Path &path)
{
    Yaml yaml;
    yaml << project;
    return yaml.ToFile(path);
}

} // namespace Lumen