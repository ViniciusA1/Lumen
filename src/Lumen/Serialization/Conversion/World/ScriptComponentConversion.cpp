#include "Lumen/Serialization/Conversion/World/WorldConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ScriptComponent &script)
{
    Json json, scriptJson;

    for (const auto &[name, info] : script.Components)
    {
        Json scriptInfoJson;
        scriptInfoJson << info.Data;
        scriptJson[name] << scriptInfoJson;
    }

    json["ScriptComponent"] << scriptJson;
    return json;
}

template <> void Deserialize(const Json &json, ScriptComponent &script)
{
    const Json scriptJson = json["ScriptComponent"];

    if (scriptJson.IsNull())
        throw std::exception();

    for (const auto &[key, scriptInfoJson] : scriptJson.GetKeyValues())
    {
        ScriptComponent::Info info;
        scriptInfoJson[key] >> info.Data;
        script.Components[key] = info;
    }
}

} // namespace Lumen::JsonSerializer