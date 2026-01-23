#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const UntaggedComponent &tag)
{
    Json json;
    json["Untagged"] << tag.Name;
    return json;
}

template <> void Deserialize(const Json &json, UntaggedComponent &tag)
{
    json["Untagged"] >> tag.Name;
}

template <> Json Serialize(const EnemyTagComponent &tag)
{
    Json json;
    json["EnemyTag"] << tag.Name;
    return json;
}

template <> void Deserialize(const Json &json, EnemyTagComponent &tag)
{
    json["EnemyTag"] >> tag.Name;
}

template <> Json Serialize(const MainCameraTagComponent &tag)
{
    Json json;
    json["MainCameraTag"] << tag.Name;
    return json;
}

template <> void Deserialize(const Json &json, MainCameraTagComponent &tag)
{
    json["MainCameraTag"] >> tag.Name;
}

template <> Json Serialize(const PlayerTagComponent &tag)
{
    Json json;
    json["PlayerTag"] << tag.Name;
    return json;
}

template <> void Deserialize(const Json &json, PlayerTagComponent &tag)
{
    json["PlayerTag"] >> tag.Name;
}

} // namespace Lumen::JsonSerializer