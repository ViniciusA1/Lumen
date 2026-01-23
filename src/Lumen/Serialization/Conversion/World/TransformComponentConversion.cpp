#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const TransformComponent &transform)
{
    Json json, transformJson;
    transformJson["Position"] << transform.Position;
    transformJson["Rotation"] << transform.Rotation;
    transformJson["Scale"] << transform.Scale;
    json["Transform"] << transformJson;
    return json;
}

template <> void Deserialize(const Json &json, TransformComponent &transform)
{
    const Json &transformJson = json["Transform"];
    transformJson["Position"] >> transform.Position;
    transformJson["Rotation"] >> transform.Rotation;
    transformJson["Scale"] >> transform.Scale;
}

} // namespace Lumen::JsonSerializer