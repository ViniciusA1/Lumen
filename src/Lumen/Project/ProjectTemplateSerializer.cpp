#include "Lumen/Project/ProjectTemplateSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool ProjectTemplateSerializer::Deserialize(ProjectTemplate &projTemplate,
                                            const Path &path)
{
    Yaml yaml = Yaml::FromFile(path);
    if (yaml.IsNull())
        return false;

    yaml >> projTemplate;
    projTemplate.RootDirectory = path.ParentPath();
    return true;
}

bool ProjectTemplateSerializer::Serialize(const ProjectTemplate &projTemplate,
                                          const Path &path)
{
    Yaml yaml;
    yaml << projTemplate;
    return yaml.ToFile(path);
}

} // namespace Lumen