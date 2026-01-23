#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ParentComponent &parent)
{
    Json json;
    json["Parent"] << parent.ParentID;
    return json;
}

template <> void Deserialize(const Json &json, ParentComponent &parent)
{
    json["Parent"] >> parent.ParentID;
}

} // namespace Lumen::JsonSerializer