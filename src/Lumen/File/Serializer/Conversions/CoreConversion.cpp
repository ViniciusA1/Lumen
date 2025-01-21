#include "Lumen/File/Serializer/Conversions/CoreConversion.hpp"

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

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const UUID &uuid)
{
    Yaml yaml;
    yaml << (uint64_t)uuid;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, UUID &uuid)
{
    uint64_t id = uuid;
    yaml >> id;
    uuid = id;
}

} // namespace Lumen::YamlSerializer