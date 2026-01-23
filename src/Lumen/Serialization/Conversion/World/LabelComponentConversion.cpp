#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LabelComponent &label)
{
    Json json, labelJson;
    labelJson = Serialize(static_cast<const UIComponentBase &>(label));
    labelJson["Text"] << label.Text;
    labelJson["Font"] << label.Font;
    labelJson["FontSize"] << label.FontSize;
    json["Label"] << labelJson;
    return json;
}

template <> void Deserialize(const Json &json, LabelComponent &label)
{
    const Json &labelJson = json["Label"];
    Deserialize(labelJson, static_cast<UIComponentBase &>(label));
    labelJson["Text"] >> label.Text;
    labelJson["Font"] >> label.Font;
    labelJson["FontSize"] >> label.FontSize;
}

} // namespace Lumen::JsonSerializer