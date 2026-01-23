#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const NameComponent &name)
{
    Json json;
    json["Name"] << name.Name;
    return json;
}

template <> void Deserialize(const Json &json, NameComponent &name)
{
    json["Name"] >> name.Name;
}

} // namespace Lumen::JsonSerializer