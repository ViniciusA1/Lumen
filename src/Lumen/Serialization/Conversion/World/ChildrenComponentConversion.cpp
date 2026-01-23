#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ChildrenComponent &children)
{
    Json json, childrenJson;

    for (const auto &childrenID : children.ChildrenID)
        childrenJson.PushBack((uint64_t)childrenID);

    json["Children"] << childrenJson;

    return json;
}

template <> void Deserialize(const Json &json, ChildrenComponent &children)
{
    const Json &childrenJson = json["Children"];

    if (childrenJson.IsNull())
        throw std::exception();

    for (const auto &childrenIDJson : childrenJson)
    {
        UUID id;
        childrenIDJson >> id;
        children.ChildrenID.push_back(id);
    }
}

} // namespace Lumen::JsonSerializer