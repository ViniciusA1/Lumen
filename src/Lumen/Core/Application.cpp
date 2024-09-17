#include "Lumen/Core/Application.hpp"
#include "Lumen/Graphics/Renderer.hpp"

namespace Lumen
{

Scope<Application> Application::s_Instance = nullptr;

Application::Application(const ApplicationArgs &args) : m_Window(args.WinArgs)
{
}

void Application::Run()
{
    Renderer::SetClearColor(Color::Black);
    while (m_Window.IsRunning())
    {
        Renderer::Clear();
        Renderer::BeginDrawing();
        Renderer::DrawFPS({0, 0}, 20, Color::Green);
        Renderer::DrawQuad({200, 200}, {50, 50}, Color::White);
        Renderer::EndDrawing();
    }
}

} // namespace Lumen