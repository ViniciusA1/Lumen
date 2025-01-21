#include "Lumen/File/Serializer/Conversions/FileConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Path &path)
{
    Json json;
    json << path.String();
    return json;
}

template <> void Deserialize(const Json &json, Path &path)
{
    std::string tmp = path.String();
    json >> tmp;
    path = tmp;
}

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Path &path)
{
    Yaml yaml;
    yaml << path.String();
    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Path &path)
{
    std::string tmp = path.String();
    yaml >> tmp;
    path = tmp;
}

} // namespace Lumen::YamlSerializer