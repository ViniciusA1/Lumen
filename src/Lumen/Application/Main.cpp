#if false

#include "Lumen/Application/Application.hpp"
#include "Lumen/Application/CLIParser.hpp"
#include "Lumen/Application/DefaultModule.hpp"

int main(int argc, const char **argv)
{
    Lumen::CLIResult result = Lumen::CLIParser::Parse(argc, argv);
    if (!result.ShouldRun)
        return 0;

    Lumen::Application().AddModule<Lumen::DefaultModule>(result.Args).Run();

    return 0;
}

#endif