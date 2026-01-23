#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AudioListenerComponent &audioListener)
{
    Json json, audioListenerJson;
    json["AudioListener"] << audioListenerJson;
    return json;
}

template <> void Deserialize(const Json &json, AudioListenerComponent &audioListener)
{
    const Json &audioListenerJson = json["AudioListener"];
    audioListenerJson >> audioListener;
}

} // namespace Lumen::JsonSerializer