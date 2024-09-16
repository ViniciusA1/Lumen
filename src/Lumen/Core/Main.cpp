#include "Lumen/Core/Application.hpp"

int main(int argc, const char **argv)
{
    auto &app =
        Lumen::Application::Create<Lumen::Application>({{"Lumen", 800, 600}});
    app.Run();
    return 0;
}