#include "Lumen/UI/Style/StyleSerializer.hpp"
#include "Lumen/File/Serializer/JsonSerializer.hpp"

namespace Lumen
{

bool StyleSerializer::Serialize(const Path &path, const Style &style)
{
    Json json;
    json << style;
    bool result = json.ToFile(path);
    return result;
}

bool StyleSerializer::Deserialize(const Path &path, Style &style)
{
    Json json = Json::FromFile(path);

    if (json.IsNull())
        return false;

    json >> style;
    return true;
}

} // namespace Lumen