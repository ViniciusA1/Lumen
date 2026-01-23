#include "Lumen/Serialization/Conversion/Project/ProjectConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Project &project)
{
    Json json;
    json["Name"] << project.Name;
    json["LastModified"] << project.LastModified;
    json["WorkingDirectory"] << project.WorkingDirectory;
    json["ConfigDirectory"] << project.ConfigDirectory;
    json["AssetDirectory"] << project.AssetDirectory;
    json["SceneDirectory"] << project.SceneDirectory;
    json["StartScene"] << project.StartScene;
    return json;
}

template <> void Deserialize(const Json &json, Project &project)
{
    json["Name"] >> project.Name;
    json["LastModified"] >> project.LastModified;
    json["WorkingDirectory"] >> project.WorkingDirectory;
    json["ConfigDirectory"] >> project.ConfigDirectory;
    json["AssetDirectory"] >> project.AssetDirectory;
    json["SceneDirectory"] >> project.SceneDirectory;
    json["StartScene"] >> project.StartScene;
}

} // namespace Lumen::JsonSerializer