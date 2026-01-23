#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Vector2 &vec)
{
    Json json;
    json.PushBack(vec.x);
    json.PushBack(vec.y);
    return json;
}

template <> void Deserialize(const Json &json, Vector2 &vec)
{
    json[0] >> vec.x;
    json[1] >> vec.y;
}

} // namespace Lumen::JsonSerializer