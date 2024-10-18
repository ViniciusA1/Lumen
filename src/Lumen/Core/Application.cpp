#include "Lumen/Core/Application.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Test/TestLayer.hpp"

namespace Lumen
{

Scope<Application> Application::s_Instance = nullptr;

Application::Application(const ApplicationArgs &args) : m_Window(args.WinArgs)
{
    PushLayer(CreateRef<TestLayer>());
}

void Application::Run()
{
    Renderer::SetClearColor(Color::Black);
    while (m_Window.IsRunning())
    {
        Event::PollEvents(m_EventQueue);
        Renderer::Clear();
        Renderer::BeginDrawing();

        Renderer::DrawFPS({0, 0}, 20, Color::Green);

        for (Event &event : m_EventQueue)
        {
            for (Ref<Layer> &layer : m_LayerStack)
            {
                m_EventDispatcher.Dispatch(*layer, event);
                if (event.Handled)
                    break;
            }
        }

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