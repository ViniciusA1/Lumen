#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const UIComponentBase &base)
{
    Json json, colorsJson;
    json["State"] << static_cast<int>(base.State);
    colorsJson["Idle"] << base.Colors[0];
    colorsJson["Hovered"] << base.Colors[1];
    colorsJson["Pressed"] << base.Colors[2];
    colorsJson["Disabled"] << base.Colors[3];
    json["Colors"] << colorsJson;
    return json;
}

template <> void Deserialize(const Json &json, UIComponentBase &base)
{
    const Json &colorsJson = json["Colors"];
    int stateInt;
    json["State"] >> stateInt;
    base.State = static_cast<UIComponentState>(stateInt);
    colorsJson["Idle"] >> base.Colors[0];
    colorsJson["Hovered"] >> base.Colors[1];
    colorsJson["Pressed"] >> base.Colors[2];
    colorsJson["Disabled"] >> base.Colors[3];
}

} // namespace Lumen::JsonSerializer