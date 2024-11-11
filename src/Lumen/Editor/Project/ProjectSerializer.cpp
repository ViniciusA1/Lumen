#include "Lumen/Editor/Project/ProjectSerializer.hpp"
#include "yaml-cpp/yaml.h"
#include <fstream>

namespace Lumen
{

bool ProjectSerializer::SerializeProject(Project &project,
                                         const std::filesystem::path &path)
{
    ProjectConfig &config = project.GetConfig();
    std::filesystem::path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node configNode;
        configNode["Name"] = config.Name;
        configNode["RootDirectory"] = config.RootDirectory.string();
        configNode["AssetDirectory"] = config.AssetDirectory.string();
        configNode["StartScene"] = config.StartScene.string();

        std::ofstream configFile(configPath);
        configFile << configNode;
    }
    catch (const YAML::Exception &e)
    {
        return false;
    }

    return true;
}

bool ProjectSerializer::DeserializeProject(Project &project,
                                           const std::filesystem::path &path)
{
    ProjectConfig &projectConfig = project.GetConfig();
    std::filesystem::path configPath = path / "ProjectConfig.lproj";

    try
    {
        YAML::Node config = YAML::LoadFile(configPath.string());

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
                                             const std::filesystem::path &path)
{
    std::filesystem::path projectListPath = path / "ProjectList.lumen";

    try
    {
        YAML::Emitter out;
        out << YAML::BeginSeq;

        for (auto &project : projectList)
        {
            out << YAML::BeginMap;
            out << YAML::Key << "path" << YAML::Value
                << project.GetConfig().RootDirectory.string();
            out << YAML::EndMap;
        }

        out << YAML::EndSeq;

        std::ofstream outFile(projectListPath);
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
                                               const std::filesystem::path &path)
{
    std::filesystem::path projectListPath = path / "ProjectList.lumen";

    if (!std::filesystem::exists(projectListPath))
    {
        std::ofstream outFile(projectListPath);
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
        YAML::Node root = YAML::LoadFile(projectListPath.string());

        projectList.clear();

        for (const auto &projectNode : root)
        {
            if (projectNode["path"])
            {
                auto pathString = projectNode["path"].as<std::string>();
                Project loadedProject({});
                ProjectSerializer serializer;
                if (serializer.DeserializeProject(loadedProject, pathString))
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