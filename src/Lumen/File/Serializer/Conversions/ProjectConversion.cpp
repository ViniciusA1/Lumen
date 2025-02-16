#include "Lumen/File/Serializer/Conversions/ProjectConversion.hpp"

#include "Lumen/File/Serializer/Conversions/FileConversion.hpp"
#include "Lumen/File/Serializer/Conversions/SceneConversion.hpp"

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
    json["StartScene"] >> project.StartScene;
}

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

namespace Lumen::YamlSerializer
{

template <> Yaml Serialize(const Project &project)
{
    Yaml yaml;

    yaml["Name"] << project.Name;
    yaml["LastModified"] << project.LastModified;
    yaml["Type"] << project.Type;
    yaml["WorkingDirectory"] << project.WorkingDirectory;
    yaml["ConfigDirectory"] << project.ConfigDirectory;
    yaml["AssetDirectory"] << project.AssetDirectory;
    yaml["StartScene"] << project.StartScene;

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, Project &project)
{
    yaml["Name"] >> project.Name;
    yaml["LastModified"] >> project.LastModified;
    yaml["Type"] >> project.Type;
    yaml["WorkingDirectory"] >> project.WorkingDirectory;
    yaml["ConfigDirectory"] >> project.ConfigDirectory;
    yaml["AssetDirectory"] >> project.AssetDirectory;
    yaml["StartScene"] >> project.StartScene;
}

template <> Yaml Serialize(const ProjectTemplate &projTemplate)
{
    Yaml yaml;

    yaml["Name"] << projTemplate.Name;
    yaml["Description"] << projTemplate.Description;
    yaml["Type"] << projTemplate.Type;
    yaml["WorkingDirectory"] << projTemplate.WorkingDirectory;
    yaml["ConfigDirectory"] << projTemplate.ConfigDirectory;
    yaml["AssetDirectory"] << projTemplate.AssetDirectory;
    yaml["StartScene"] << projTemplate.StartScene;

    return yaml;
}

template <> void Deserialize(const Yaml &yaml, ProjectTemplate &projTemplate)
{
    yaml["Name"] >> projTemplate.Name;
    yaml["Description"] >> projTemplate.Description;
    yaml["Type"] >> projTemplate.Type;
    yaml["WorkingDirectory"] >> projTemplate.WorkingDirectory;
    yaml["ConfigDirectory"] >> projTemplate.ConfigDirectory;
    yaml["AssetDirectory"] >> projTemplate.AssetDirectory;
    yaml["StartScene"] >> projTemplate.StartScene;
}

} // namespace Lumen::YamlSerializer