#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const SceneType &type)
{
    Json json;
    json << static_cast<int>(type);
    return json;
}

template <> void Deserialize(const Json &json, SceneType &type)
{
    int typeInt;
    json >> typeInt;
    type = static_cast<SceneType>(typeInt);
}

} // namespace Lumen::JsonSerializer