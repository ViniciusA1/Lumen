#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const CheckboxComponent &checkbox)
{
    Json json, checkboxJson;
    checkboxJson = Serialize(static_cast<const UIComponentBase &>(checkbox));
    checkboxJson["Value"] << checkbox.Value;
    json["Checkbox"] << checkboxJson;
    return json;
}

template <> void Deserialize(const Json &json, CheckboxComponent &checkbox)
{
    const Json &checkboxJson = json["Checkbox"];
    Deserialize(checkboxJson, static_cast<UIComponentBase &>(checkbox));
    checkboxJson["Value"] >> checkbox.Value;
}

} // namespace Lumen::JsonSerializer