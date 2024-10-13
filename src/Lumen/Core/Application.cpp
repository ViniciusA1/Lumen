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
        for (Ref<Layer> &layer : m_LayerStack)
        {
            if (layer->IsVisible())
            {
                layer->OnUpdate();
                layer->OnDraw();
            }
        }
        Renderer::EndDrawing();
    }
}

void Application::PushLayer(const Ref<Layer> &layer)
{
    m_LayerStack.PushLayer(layer);
}

void Application::PushOverlay(const Ref<Layer> &overlay)
{
    m_LayerStack.PushOverlay(overlay);
}

} // namespace Lumen