#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const SliderComponent &slider)
{
    Json json, sliderJson;
    sliderJson = Serialize(static_cast<const UIComponentBase &>(slider));
    sliderJson["MinValue"] << slider.MinValue;
    sliderJson["MaxValue"] << slider.MaxValue;
    sliderJson["Value"] << slider.Value;
    json["Slider"] << sliderJson;
    return json;
}

template <> void Deserialize(const Json &json, SliderComponent &slider)
{
    const Json &sliderJson = json["Slider"];
    Deserialize(sliderJson, static_cast<UIComponentBase &>(slider));
    sliderJson["MinValue"] >> slider.MinValue;
    sliderJson["MaxValue"] >> slider.MaxValue;
    sliderJson["Value"] >> slider.Value;
}

} // namespace Lumen::JsonSerializer