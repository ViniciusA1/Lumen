#include "Lumen/Application/ApplicationArgsSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool ApplicationArgsSerializer::Deserialize(ApplicationArgs &args, const Path &path)
{
    Yaml yaml = Yaml::FromFile(path);
    if (yaml.IsNull())
        return false;

    yaml >> args;
    args.RootDirectory = path.ParentPath().ParentPath();

    return true;
}

bool ApplicationArgsSerializer::Serialize(const ApplicationArgs &args, const Path &path)
{
    Yaml yaml;
    yaml << args;
    return yaml.ToFile(path);
}

} // namespace Lumen