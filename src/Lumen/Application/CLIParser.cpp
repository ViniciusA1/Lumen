#include "Lumen/Application/CLIParser.hpp"
#include "Lumen/File/FileSystem.hpp"
#include "Lumen/Serialization/Json.hpp"

#include <iostream>

namespace Lumen
{

CLIResult CLIParser::Parse(int argc, const char **argv)
{
    CLIResult result;

    if (argc <= 1)
    {
        HelpCommand();
        return result;
    }

    const std::string first = argv[1];

    if (!first.starts_with('-'))
    {
        RunCommand(first.c_str(), result);
        return result;
    }

    if (first == "--new")
    {
        if (argc < 3)
        {
            std::cerr << "Error: --new requires a path\n";
            HelpCommand();
            return result;
        }

        NewCommand(argv[2]);
        return result;
    }

    if (first == "--run")
    {
        if (argc < 3)
        {
            std::cerr << "Error: --run requires a project path\n";
            HelpCommand();
            return result;
        }

        RunCommand(argv[2], result);
        return result;
    }

    if (first == "--editor")
    {
        if (argc < 3)
        {
            std::cerr << "Error: --editor requires a project path\n";
            HelpCommand();
            return result;
        }

        EditorCommand(argv[2], result);
        return result;
    }

    if (first == "--help")
    {
        HelpCommand();
        return result;
    }

    if (first == "--version")
    {
        VersionCommand();
        return result;
    }

    std::cerr << "Unknown command: " << first << "\n";
    HelpCommand();
    return result;
}

void CLIParser::NewCommand(const Path &path)
{
    if (FileSystem::Exists(path))
    {
        std::cerr << "Error: path already exists: " << path.String() << "\n";
        return;
    }

    std::cout << "Creating new Lumen project at: " << path.String() << "\n";

    FileSystem::CreateDirectories(path / "assets/scene");
    FileSystem::CreateDirectories(path / "assets/script");
    FileSystem::CreateDirectories(path / "config");

    ApplicationArgs args = {
        .Title = path.Filename().String(),
        .Resolution = {1280, 720},
        .Icon = 0,
        .Flags = WindowFlags::Resizable,
        .TargetFPS = 0,
        .Mode = ApplicationMode::Runtime,
        .RootDirectory = path,
        .AssetDirectory = "assets",
        .StartScene = "scene/main_scene.lscene",
    };

    SerializationResult result = Json::ToFile(path / "application_args.lumen", args);

    if (result.IsOk())
        std::cout << "Project created successfully.\n";
    else
    {
        for (const auto &message : result.GetMessages())
            std::cout << message.Message << '\n';
    }
}

bool CLIParser::LoadProject(const Path &path, CLIResult &result)
{
    if (!FileSystem::Exists(path))
    {
        std::cerr << "Error: project path does not exist: " << path.String() << "\n";
        return false;
    }

    if (!FileSystem::IsDirectory(path))
    {
        std::cerr << "Error: project path isn't a folder: " << path.String() << "\n";
        return false;
    }

    SerializationResult serResult =
        Json::FromFile(path / "application_args.lumen", result.Args);

    if (!serResult.IsOk())
    {
        for (const auto &message : serResult.GetMessages())
            std::cerr << message.Message << '\n';

        return false;
    }

    result.Args.RootDirectory = path;
    return true;
}

void CLIParser::RunCommand(const Path &path, CLIResult &result)
{
    if (!LoadProject(path, result))
        return;

    result.Args.Mode = ApplicationMode::Runtime;
    result.ShouldRun = true;
}

void CLIParser::EditorCommand(const Path &path, CLIResult &result)
{
    if (!LoadProject(path, result))
        return;

    result.Args.Mode = ApplicationMode::Editor;
    result.ShouldRun = true;
}

void CLIParser::HelpCommand()
{
    std::cout << "Lumen Engine\n\n"
                 "Usage:\n"
                 "  lumen --new <path>\n"
                 "  lumen --run <path>\n"
                 "  lumen --editor <path>\n\n"
                 "Commands:\n"
                 "  --new       Create a new project\n"
                 "  --run       Run a project\n"
                 "  --editor    Start editor mode\n"
                 "  --help      Show this help\n"
                 "  --version   Show version information\n";
}

void CLIParser::VersionCommand()
{
    std::cout << "Lumen Engine version 0.1.0\n";
}

} // namespace Lumen