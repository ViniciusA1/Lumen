#pragma once

#include "Lumen/Core/LayerStack.hpp"
#include "Lumen/Core/Memory.hpp"
#include "Lumen/Core/Window.hpp"
#include "Lumen/Event/LayerEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"

namespace Lumen
{

struct ApplicationArgs
{
    WindowArgs WinArgs;
};

class Application
{
public:
    template <typename T> static Ref<T> Create(const ApplicationArgs &args)
    {
        Ref<T> instance = CreateRef<T>(args);
        s_Instance = std::static_pointer_cast<Application>(instance);
        return instance;
    }

    Application(const ApplicationArgs &args);
    ~Application();

    static Application &Get() { return *s_Instance; }
    Window &GetWindow() { return m_Window; }

    void Run();

protected:
    void OnWindowResize(const WindowResizeEvent &event);
    void OnWindowClose(const WindowCloseEvent &event);
    void OnLayerPush(const LayerPushEvent &event);
    void OnLayerPop(const LayerPopEvent &event);

    static Ref<Application> s_Instance;
    bool m_IsRunning = true;
    Window m_Window;
    LayerStack m_LayerStack;
};

} // namespace Lumen