#include "Lumen/UI/LUIStyleSerializer.hpp"
#include "Lumen/File/Serializer/JsonSerializer.hpp"

namespace Lumen
{

bool LUIStyleSerializer::Serialize(const Path &path, const LUI::Style &style)
{
    Json json;
    json << style;
    bool result = json.ToFile(path);
    return result;
}

bool LUIStyleSerializer::Deserialize(const Path &path, LUI::Style &style)
{
    Json json = Json::FromFile(path);

    if (json.IsNull())
        return false;

    json >> style;
    return true;
}

} // namespace Lumen