#pragma once

#include "Lumen/Application/CLIResult.hpp"
#include "Lumen/File/Path.hpp"

namespace Lumen
{

class CLIParser
{
public:
    CLIParser() = delete;

public:
    static CLIResult Parse(int argc, const char **argv);

private:
    static void NewCommand(const Path &path);
    static bool LoadProject(const Path &path, CLIResult &result);
    static void RunCommand(const Path &path, CLIResult &result);
    static void EditorCommand(const Path &path, CLIResult &result);
    static void HelpCommand();
    static void VersionCommand();
};

} // namespace Lumen