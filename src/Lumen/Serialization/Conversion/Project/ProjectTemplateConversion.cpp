#include "Lumen/Serialization/Conversion/Project/ProjectConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const ProjectTemplate &projTemplate)
{
    Json json;

    json["Name"] << projTemplate.Name;
    json["Description"] << projTemplate.Description;
    json["Type"] << projTemplate.Type;
    json["WorkingDirectory"] << projTemplate.WorkingDirectory;
    json["ConfigDirectory"] << projTemplate.ConfigDirectory;
    json["AssetDirectory"] << projTemplate.AssetDirectory;
    json["StartScene"] << projTemplate.StartScene;

    return json;
}

template <> void Deserialize(const Json &json, ProjectTemplate &projTemplate)
{
    json["Name"] >> projTemplate.Name;
    json["Description"] >> projTemplate.Description;
    json["Type"] >> projTemplate.Type;
    json["WorkingDirectory"] >> projTemplate.WorkingDirectory;
    json["ConfigDirectory"] >> projTemplate.ConfigDirectory;
    json["AssetDirectory"] >> projTemplate.AssetDirectory;
    json["StartScene"] >> projTemplate.StartScene;
}

} // namespace Lumen::JsonSerializer