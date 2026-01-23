#include "Lumen/Serialization/Conversion/System/SystemConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const UUID &uuid)
{
    Json json;
    json << (uint64_t)uuid;
    return json;
}

template <> void Deserialize(const Json &json, UUID &uuid)
{
    uint64_t id = uuid;
    json >> id;
    uuid = id;
}

} // namespace Lumen::JsonSerializer