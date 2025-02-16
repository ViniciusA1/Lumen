#include "Lumen/Scene/SceneSerializer.hpp"
#include "Lumen/File/Serializer/YamlSerializer.hpp"

namespace Lumen
{

bool SceneSerializer::Deserialize(Ref<Scene> &scene, const Path &path)
{
    Yaml yaml = Yaml::FromFile(path);
    if (yaml.IsNull())
        return false;

    yaml >> scene;
    scene->SetPath(path);
    return true;
}

bool SceneSerializer::Serialize(const Ref<Scene> &scene, const Path &path)
{
    Yaml yaml;
    yaml << scene;
    return yaml.ToFile(path);
}

} // namespace Lumen