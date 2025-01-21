#include "Lumen/File/Serializer/Conversions/GraphicsConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Color &color)
{
    Json json;
    json["r"] << color.r;
    json["g"] << color.g;
    json["b"] << color.b;
    json["a"] << color.a;
    return json;
}

template <> void Deserialize(const Json &json, Color &color)
{
    json["r"] >> color.r;
    json["g"] >> color.g;
    json["b"] >> color.b;
    json["a"] >> color.a;
}

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Color &color)
{
    Yaml yaml;
    yaml["r"] << color.r;
    yaml["g"] << color.g;
    yaml["b"] << color.b;
    yaml["a"] << color.a;
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Color &color)
{
    yaml["r"] >> color.r;
    yaml["g"] >> color.g;
    yaml["b"] >> color.b;
    yaml["a"] >> color.a;
}

} // namespace Lumen::YamlSerializer