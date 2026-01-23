#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const IDComponent &id)
{
    Json json;
    json["ID"] << id.ID;
    return json;
}

template <> void Deserialize(const Json &json, IDComponent &id)
{
    json["ID"] >> id.ID;
}

} // namespace Lumen::JsonSerializer