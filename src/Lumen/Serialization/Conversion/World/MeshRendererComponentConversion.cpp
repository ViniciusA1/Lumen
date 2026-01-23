#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const MeshRendererComponent &mesh)
{
    Json json, meshJson;
    meshJson["Mesh"] << mesh.Mesh;
    json["MeshRenderer"] << meshJson;
    return json;
}

template <> void Deserialize(const Json &json, MeshRendererComponent &mesh)
{
    const Json &meshJson = json["MeshRenderer"];
    meshJson["Mesh"] >> mesh.Mesh;
}

} // namespace Lumen::JsonSerializer