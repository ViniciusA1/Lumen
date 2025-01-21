#include "Lumen/File/Serializer/Conversions/ProjectConversion.hpp"

#include "Lumen/File/Serializer/Conversions/FileConversion.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const Project &project)
{
    Json json;

    json["Name"] << project.Name;
    json["LastModified"] << project.LastModified;
    json["WorkingDirectory"] << project.WorkingDirectory;
    json["AssetDirectory"] << project.AssetDirectory;
    json["StartScene"] << project.StartScene;

    return json;
}

template <> void Deserialize(const Json &json, Project &project)
{
    json["Name"] >> project.Name;
    json["LastModified"] >> project.LastModified;
    json["WorkingDirectory"] >> project.WorkingDirectory;
    json["AssetDirectory"] >> project.AssetDirectory;
    json["StartScene"] >> project.StartScene;
}

} // namespace Lumen::JsonSerializer

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Project &project)
{
    Yaml yaml;

    yaml["Name"] << project.Name;
    yaml["LastModified"] << project.LastModified;
    yaml["WorkingDirectory"] << project.WorkingDirectory;
    yaml["AssetDirectory"] << project.AssetDirectory;
    yaml["StartScene"] << project.StartScene;

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Project &project)
{
    yaml["Name"] >> project.Name;
    yaml["LastModified"] >> project.LastModified;
    yaml["WorkingDirectory"] >> project.WorkingDirectory;
    yaml["AssetDirectory"] >> project.AssetDirectory;
    yaml["StartScene"] >> project.StartScene;
}

} // namespace Lumen::YamlSerializer