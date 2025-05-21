#include "Lumen/File/Serializer/Conversions/GraphicsConversion.hpp"

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

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Color &color)
{
    Yaml yaml;
    yaml.SetStyle(Yaml::EmitterStyle::Flow);
    yaml.PushBack(static_cast<int>(color.r));
    yaml.PushBack(static_cast<int>(color.g));
    yaml.PushBack(static_cast<int>(color.b));
    yaml.PushBack(static_cast<int>(color.a));
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Color &color)
{
    yaml[0] >> color.r;
    yaml[1] >> color.g;
    yaml[2] >> color.b;
    yaml[3] >> color.a;
}

} // namespace Lumen::YamlSerializer