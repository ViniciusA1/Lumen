#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ButtonComponent &button)
{
    Json json, buttonJson;
    buttonJson = Serialize(static_cast<const UIComponentBase &>(button));
    buttonJson << button.Label;
    buttonJson["Texture"] << button.Texture;
    json["Button"] << buttonJson;
    return json;
}

template <> void Deserialize(const Json &json, ButtonComponent &button)
{
    const Json &buttonJson = json["Button"];
    Deserialize(buttonJson, static_cast<UIComponentBase &>(button));
    buttonJson >> button.Label;
    buttonJson["Texture"] >> button.Texture;
}

} // namespace Lumen::JsonSerializer