#include "Lumen/Core/Application.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Core/Input.hpp"
#include "Lumen/Core/Log.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Project/ProjectSerializer.hpp"
#include "Lumen/UI/UI.hpp"

namespace Lumen
{

Ref<Application> Application::s_Instance = nullptr;

Application::Application(const ApplicationArgs &args) : m_Window(args.WinArgs)
{
    s_Instance = Ref<Application>(this);

    ProjectSerializer().Serialize(m_Project, ".");
    AssetManager::SetWorkingDirectory(m_Project.AssetDirectory);

    EventBus::Subscribe<WindowResizeEvent>(BIND_EVENT(OnWindowResize));
    EventBus::Subscribe<WindowCloseEvent>(BIND_EVENT(OnWindowClose));
    EventBus::Subscribe<LayerPushEvent>(BIND_EVENT(OnLayerPush));
    EventBus::Subscribe<LayerPopEvent>(BIND_EVENT(OnLayerPop));

    UI::Init();
    Log::Init();
}

Application::~Application()
{
    UI::Shutdown();
}

void Application::Run()
{
    Renderer::CreateDefaultRenderTexture();

    while (m_IsRunning)
    {
        Input::PollEvents();
        Renderer::BeginDrawing();
        UI::BeginUI();
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

        Renderer::DrawFPS({0, 0}, 20, Color::Green);

        UI::EndUI();
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
    m_LayerStack.PushLayer(event.GetLayer());
}

void Application::OnLayerPop(const LayerPopEvent &event)
{
    m_LayerStack.PopLayer(event.GetLayerName());
}

} // namespace Lumen