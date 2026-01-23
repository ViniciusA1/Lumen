#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Vector4 &vec)
{
    Json json;
    json.PushBack(vec.x);
    json.PushBack(vec.y);
    json.PushBack(vec.z);
    json.PushBack(vec.w);
    return json;
}

template <> void Deserialize(const Json &json, Vector4 &vec)
{
    json[0] >> vec.x;
    json[1] >> vec.y;
    json[2] >> vec.z;
    json[3] >> vec.w;
}

} // namespace Lumen::JsonSerializer