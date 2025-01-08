#include "Lumen/Project/ProjectSerializer.hpp"

#include "yaml-cpp/yaml.h"
#include <fstream>

namespace Lumen
{

bool ProjectSerializer::Deserialize(Project &project, const Path &path)
{
    Path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node config = YAML::LoadFile(configPath.String());

        project.Name = config["Name"].as<std::string>();
        project.LastModified = config["LastModified"].as<std::string>();
        project.RootDirectory = path;
        project.WorkingDirectory = config["WorkingDirectory"].as<std::string>();
        project.AssetDirectory = config["AssetDirectory"].as<std::string>();
        project.StartScene = config["StartScene"].as<std::string>();
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

bool ProjectSerializer::Serialize(const Project &project, const Path &path)
{
    Path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node configNode;
        configNode["Name"] = project.Name;
        configNode["LastModified"] = project.LastModified;
        configNode["WorkingDirectory"] = project.WorkingDirectory.String();
        configNode["AssetDirectory"] = project.AssetDirectory.String();
        configNode["StartScene"] = project.StartScene.String();

        std::ofstream configFile(configPath.String());
        configFile << configNode;
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

} // namespace Lumen