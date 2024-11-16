#include "Lumen/Editor/Project/ProjectSerializer.hpp"
#include "yaml-cpp/yaml.h"
#include <fstream>

namespace Lumen
{

bool ProjectSerializer::SerializeProject(Project &project, const Path &path)
{
    ProjectConfig &config = project.GetConfig();
    Path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node configNode;
        configNode["Name"] = config.Name;
        configNode["RootDirectory"] = config.RootDirectory.ToString();
        configNode["AssetDirectory"] = config.AssetDirectory.ToString();
        configNode["StartScene"] = config.StartScene.ToString();

        std::ofstream configFile(configPath.ToString());
        configFile << configNode;
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

bool ProjectSerializer::DeserializeProject(Project &project, const Path &path)
{
    ProjectConfig &projectConfig = project.GetConfig();
    Path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node config = YAML::LoadFile(configPath.ToString());

        projectConfig.Name = config["Name"].as<std::string>();
        projectConfig.RootDirectory = path;
        projectConfig.AssetDirectory = config["AssetDirectory"].as<std::string>();
        projectConfig.StartScene = config["StartScene"].as<std::string>();
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

bool ProjectSerializer::SerializeProjectList(std::vector<Project> &projectList,
                                             const Path &path)
{
    Path projectListPath = path / "ProjectList.lumen";

    try
    {
        YAML::Emitter out;
        out << YAML::BeginSeq;

        for (auto &project : projectList)
        {
            out << YAML::BeginMap;
            out << YAML::Key << "path" << YAML::Value
                << project.GetConfig().RootDirectory.ToString();
            out << YAML::EndMap;
        }

        out << YAML::EndSeq;

        std::ofstream outFile(projectListPath.ToString());
        if (outFile.is_open())
        {
            outFile << out.c_str();
            outFile.close();
        }
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

bool ProjectSerializer::DeserializeProjectList(std::vector<Project> &projectList,
                                               const Path &path)
{
    Path projectListPath = path / "ProjectList.lumen";

    if (!std::filesystem::exists(projectListPath))
    {
        std::ofstream outFile(projectListPath.ToString());
        if (outFile.is_open())
        {
            YAML::Emitter out;
            out << YAML::BeginSeq;
            out << YAML::EndSeq;
            outFile << out.c_str();
            outFile.close();
            return true;
        }
    }

    try
    {
        YAML::Node root = YAML::LoadFile(projectListPath.ToString());

        projectList.clear();

        for (const auto &projectNode : root)
        {
            if (projectNode["path"])
            {
                auto pathString = projectNode["path"].as<std::string>();
                Project loadedProject({});
                ProjectSerializer serializer;
                if (serializer.DeserializeProject(loadedProject, {pathString}))
                {
                    projectList.push_back(loadedProject);
                }
            }
        }
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

} // namespace Lumen