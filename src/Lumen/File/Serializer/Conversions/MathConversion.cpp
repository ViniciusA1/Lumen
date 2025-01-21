#include "Lumen/File/Serializer/Conversions/MathConversion.hpp"

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

template <> Json Serialize(const Matrix4 &mat)
{
    Json json;

    for (auto value : mat.ToFloat16())
    {
        json.PushBack(value);
    }

    return json;
}

template <> void Deserialize(const Json &json, Matrix4 &mat)
{
    if (!json.IsArray() || json.Size() != 16)
    {
        return;
    }

    int i = 0;
    for (auto &value : mat.ToFloat16())
    {
        json[i] >> value;
    }
}

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

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Vector2 &vec)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);
    yaml.PushBack(vec.x);
    yaml.PushBack(vec.y);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Vector2 &vec)
{
    yaml[0] >> vec.x;
    yaml[1] >> vec.y;
}

template <> Yaml Serialize(const Vector3 &vec)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);
    yaml.PushBack(vec.x);
    yaml.PushBack(vec.y);
    yaml.PushBack(vec.z);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Vector3 &vec)
{
    yaml[0] >> vec.x;
    yaml[1] >> vec.y;
    yaml[2] >> vec.z;
}

template <> Yaml Serialize(const Vector4 &vec)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);
    yaml.PushBack(vec.x);
    yaml.PushBack(vec.y);
    yaml.PushBack(vec.z);
    yaml.PushBack(vec.w);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Vector4 &vec)
{
    yaml[0] >> vec.x;
    yaml[1] >> vec.y;
    yaml[2] >> vec.z;
    yaml[3] >> vec.w;
}

template <> Yaml Serialize(const Quaternion &quat)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);
    yaml.PushBack(quat.x);
    yaml.PushBack(quat.y);
    yaml.PushBack(quat.z);
    yaml.PushBack(quat.w);
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Quaternion &quat)
{
    yaml[0] >> quat.x;
    yaml[1] >> quat.y;
    yaml[2] >> quat.z;
    yaml[3] >> quat.w;
}

template <> Yaml Serialize(const Matrix4 &mat)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);

    for (auto value : mat.ToFloat16())
    {
        yaml.PushBack(value);
    }

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Matrix4 &mat)
{
    if (!yaml.IsSequence() || yaml.Size() != 16)
    {
        return;
    }

    int i = 0;
    for (auto &value : mat.ToFloat16())
    {
        yaml[i] >> value;
        i++;
    }
}

template <> Yaml Serialize(const Rectangle &rect)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);

    yaml.PushBack(rect.x);
    yaml.PushBack(rect.y);
    yaml.PushBack(rect.Width);
    yaml.PushBack(rect.Height);

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Rectangle &rect)
{
    yaml[0] >> rect.x;
    yaml[1] >> rect.y;
    yaml[2] >> rect.Width;
    yaml[3] >> rect.Height;
}

} // namespace Lumen::YamlSerializer