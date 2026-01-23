#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Vector3 &vec)
{
    Json json;
    json.PushBack(vec.x);
    json.PushBack(vec.y);
    json.PushBack(vec.z);
    return json;
}

template <> void Deserialize(const Json &json, Vector3 &vec)
{
    json[0] >> vec.x;
    json[1] >> vec.y;
    json[2] >> vec.z;
}

} // namespace Lumen::JsonSerializer