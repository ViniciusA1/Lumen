#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Rectangle &rect)
{
    Json json;
    json.PushBack(rect.x);
    json.PushBack(rect.y);
    json.PushBack(rect.Width);
    json.PushBack(rect.Height);
    return json;
}

template <> void Deserialize(const Json &json, Rectangle &rect)
{
    json[0] >> rect.x;
    json[1] >> rect.y;
    json[2] >> rect.Width;
    json[3] >> rect.Height;
}

} // namespace Lumen::JsonSerializer