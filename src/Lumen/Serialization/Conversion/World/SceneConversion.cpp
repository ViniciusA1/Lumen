#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Ref<Scene> &scene)
{
    Json sceneNode;

    return sceneNode;
}

template <> void Deserialize(const Json &json, Ref<Scene> &scene)
{
}

} // namespace Lumen::JsonSerializer