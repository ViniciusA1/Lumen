#include "Lumen/Serialization/Conversion/Application/ApplicationConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const WindowFlags &flags)
{
    Json json;
    json << static_cast<int>(flags);
    return json;
}

template <> void Deserialize(const Json &json, WindowFlags &flags)
{
    int value;
    json >> value;
    flags = static_cast<WindowFlags>(value);
}

} // namespace Lumen::JsonSerializer