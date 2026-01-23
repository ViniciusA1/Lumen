#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const AudioSourceComponent &audioSource)
{
    Json json, audioSourceJson;
    audioSourceJson["Audio"] << audioSource.Audio;
    json["AudioSource"] << audioSourceJson;
    return json;
}

template <> void Deserialize(const Json &json, AudioSourceComponent &audioSource)
{
    const Json &audioSourceJson = json["AudioSource"];
    audioSourceJson["Audio"] >> audioSource.Audio;
}

} // namespace Lumen::JsonSerializer