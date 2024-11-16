#include "Lumen/Core/Application.hpp"
#include "Lumen/Core/Input.hpp"
#include "Lumen/Core/Log.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/UI/UI.hpp"

namespace Lumen
{

Ref<Application> Application::s_Instance = nullptr;

Application::Application(const ApplicationArgs &args) : m_Window(args.WinArgs)
{
    UI::Init();
    EventBus::Subscribe<WindowResizeEvent>(BIND_EVENT(OnWindowResize));
    EventBus::Subscribe<WindowCloseEvent>(BIND_EVENT(OnWindowClose));
    Log::Init();
}

Application::~Application()
{
    UI::Shutdown();
}

void Application::Run()
{
    Renderer::SetClearColor(Color::Black);
    Renderer::CreateRenderTexture();

    while (m_IsRunning)
    {
        Input::PollEvents();
        Renderer::BeginDrawing();
        UI::Begin();
        Renderer::Clear();

        Renderer::DrawFPS({0, 0}, 20, Color::Green);

        for (Ref<Layer> &layer : m_LayerStack)
        {
            if (layer->IsVisible())
            {
                layer->OnUpdate();
                layer->OnDraw();
            }
        }

        UI::End();
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

void Application::OnWindowResize(const WindowResizeEvent &event)
{
}

void Application::OnWindowClose(const WindowCloseEvent &event)
{
    m_IsRunning = false;
}

} // namespace Lumen