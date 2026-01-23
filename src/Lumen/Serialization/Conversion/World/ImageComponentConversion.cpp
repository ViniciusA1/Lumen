#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ImageComponent &image)
{
    Json json, imageJson;
    imageJson = Serialize(static_cast<const UIComponentBase &>(image));
    imageJson["Texture"] << image.Texture;
    json["Image"] << imageJson;
    return json;
}

template <> void Deserialize(const Json &json, ImageComponent &image)
{
    const Json &imageJson = json["Image"];
    Deserialize(imageJson, static_cast<UIComponentBase &>(image));
    imageJson["Texture"] >> image.Texture;
}

} // namespace Lumen::JsonSerializer