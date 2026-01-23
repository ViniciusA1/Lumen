#include "Lumen/Serialization/Conversion/Math/MathConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Matrix4 &mat)
{
    Json json;

    for (auto value : mat.ToFloat16())
        json.PushBack(value);

    return json;
}

template <> void Deserialize(const Json &json, Matrix4 &mat)
{
    if (!json.IsArray() || json.GetSize() != 16)
        return;

    int i = 0;
    for (auto &value : mat.ToFloat16())
    {
        json[i] >> value;
        i++;
    }
}

} // namespace Lumen::JsonSerializer