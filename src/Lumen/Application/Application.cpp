#include "Lumen/Application/Application.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Input/Input.hpp"

namespace Lumen
{

Application *Application::s_Instance = nullptr;

Application::Application()
{
    s_Instance = this;
    EventBus::Subscribe<WindowResizeEvent>(BIND_EVENT(OnWindowResize));
    EventBus::Subscribe<WindowCloseEvent>(BIND_EVENT(OnWindowClose));
    EventBus::Subscribe<LayerPushEvent>(BIND_EVENT(OnLayerPush));
    EventBus::Subscribe<LayerPopEvent>(BIND_EVENT(OnLayerPop));
}

Application::~Application()
{
    m_Window.Close();
}

Application &Application::Get()
{
    return *s_Instance;
}

const ApplicationArgs &Application::GetArgs() const
{
    return m_Args;
}

ApplicationArgs &Application::GetArgs()
{
    return m_Args;
}

const Window &Application::GetWindow() const
{
    return m_Window;
}

Window &Application::GetWindow()
{
    return m_Window;
}

void Application::Run()
{
    while (m_IsRunning)
    {
        Input::PollEvents();
        Renderer::BeginDrawing();
        Renderer::ClearBackground(Color::Black);

        EventBus::ProcessEvents();

        for (auto &[layerName, layer] : m_LayerStack)
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

void Application::OnWindowResize(const WindowResizeEvent &event)
{
}

void Application::OnWindowClose(const WindowCloseEvent &event)
{
    m_IsRunning = false;
}

void Application::OnLayerPush(const LayerPushEvent &event)
{
    m_LayerStack.PushLayer(event.Layer);
}

void Application::OnLayerPop(const LayerPopEvent &event)
{
    m_LayerStack.PopLayer(event.LayerName);
}

} // namespace Lumen