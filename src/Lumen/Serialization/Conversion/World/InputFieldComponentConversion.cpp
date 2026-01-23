#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const InputFieldComponent &inputField)
{
    Json json, inputFieldJson;
    inputFieldJson = Serialize(static_cast<const UIComponentBase &>(inputField));
    inputFieldJson << inputField.Text;
    json["InputField"] << inputFieldJson;
    return json;
}

template <> void Deserialize(const Json &json, InputFieldComponent &inputField)
{
    const Json &inputFieldJson = json["InputField"];
    Deserialize(inputFieldJson, static_cast<UIComponentBase &>(inputField));
    inputFieldJson >> inputField.Text;
}

} // namespace Lumen::JsonSerializer