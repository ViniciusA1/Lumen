#include "Lumen/Project/ProjectTemplateSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool ProjectTemplateSerializer::Deserialize(ProjectTemplate &projTemplate,
                                            const Path &path)
{
    Path configPath = path / "ProjectTemplate.ltempl";

    Yaml yaml = Yaml::FromFile(configPath);
    if (yaml.IsNull())
        return false;

    yaml >> projTemplate;
    projTemplate.RootDirectory = path;
    return true;
}

bool ProjectTemplateSerializer::Serialize(const ProjectTemplate &projTemplate,
                                          const Path &path)
{
    Path configPath = path / "ProjectTemplate.ltempl";
    Yaml yaml;
    yaml << projTemplate;
    return yaml.ToFile(configPath);
}

} // namespace Lumen