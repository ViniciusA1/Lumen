#pragma once

#include "Lumen/Application/Application.hpp"

extern Lumen::Ref<Lumen::Application> Lumen::CreateApplication();

int main(int argc, const char **argv)
{
    auto app = Lumen::CreateApplication();
    app->Run();
    return 0;
}