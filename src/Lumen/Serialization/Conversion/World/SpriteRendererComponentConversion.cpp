#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const SpriteRendererComponent &sprite)
{
    Json json, spriteJson;
    spriteJson["Color"] << sprite.Color;
    spriteJson["Texture"] << sprite.Texture;
    json["Sprite"] << spriteJson;
    return json;
}

template <> void Deserialize(const Json &json, SpriteRendererComponent &sprite)
{
    const Json &spriteJson = json["Sprite"];
    spriteJson["Color"] >> sprite.Color;
    spriteJson["Texture"] >> sprite.Texture;
}

} // namespace Lumen::JsonSerializer