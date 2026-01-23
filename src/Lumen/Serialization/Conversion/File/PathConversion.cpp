#include "Lumen/Serialization/Conversion/File/FileConversion.hpp"

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