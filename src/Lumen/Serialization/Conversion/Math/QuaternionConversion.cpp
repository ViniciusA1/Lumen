#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Quaternion &quat)
{
    Json json;
    json.PushBack(quat.x);
    json.PushBack(quat.y);
    json.PushBack(quat.z);
    json.PushBack(quat.w);
    return json;
}

template <> void Deserialize(const Json &json, Quaternion &quat)
{
    json[0] >> quat.x;
    json[1] >> quat.y;
    json[2] >> quat.z;
    json[3] >> quat.w;
}

} // namespace Lumen::JsonSerializer