#pragma once

#include "Lumen/Core/LayerStack.hpp"
#include "Lumen/Core/Memory.hpp"
#include "Lumen/Core/Window.hpp"
#include "Lumen/Event/LayerEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"
#include "Lumen/Project/Project.hpp"

namespace Lumen
{

struct ApplicationArgs
{
    WindowArgs WinArgs;
};

class Application
{
public:
    Application(const ApplicationArgs &args);
    ~Application();

    static Application &Get() { return *s_Instance; }
    const Project &GetProject() { return m_Project; }
    Window &GetWindow() { return m_Window; }

    void Run();

protected:
    void OnWindowResize(const WindowResizeEvent &event);
    void OnWindowClose(const WindowCloseEvent &event);
    void OnLayerPush(const LayerPushEvent &event);
    void OnLayerPop(const LayerPopEvent &event);

protected:
    static Ref<Application> s_Instance;

    Project m_Project;
    bool m_IsRunning = true;
    Window m_Window;
    LayerStack m_LayerStack;
};

Ref<Application> CreateApplication();

} // namespace Lumen