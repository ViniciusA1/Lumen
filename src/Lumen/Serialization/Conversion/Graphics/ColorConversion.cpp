#include "Lumen/Serialization/Conversion/Graphics/GraphicsConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Color &color)
{
    Json json;
    json.PushBack(static_cast<int>(color.r));
    json.PushBack(static_cast<int>(color.g));
    json.PushBack(static_cast<int>(color.b));
    json.PushBack(static_cast<int>(color.a));
    return json;
}

template <> void Deserialize(const Json &json, Color &color)
{
    json[0] >> color.r;
    json[1] >> color.g;
    json[2] >> color.b;
    json[3] >> color.a;
}

} // namespace Lumen::JsonSerializer