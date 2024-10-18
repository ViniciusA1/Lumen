#pragma once

#include "Lumen/Core/LayerStack.hpp"
#include "Lumen/Core/Memory.hpp"
#include "Lumen/Core/Window.hpp"
#include "Lumen/Event/EventDispatcher.hpp"
#include "Lumen/Event/EventQueue.hpp"

namespace Lumen
{

struct ApplicationArgs
{
    WindowArgs WinArgs;
};

class Application
{
public:
    template <typename T> static T &Create(const ApplicationArgs &args)
    {
        s_Instance = Scope<T>(new T(args));
        return *s_Instance;
    }

    Application(const ApplicationArgs &args);
    ~Application() = default;

    static Application &Get() { return *s_Instance; }
    Window &GetWindow() { return m_Window; }

    void Run();

    void PushLayer(const Ref<Layer> &layer);
    void PushOverlay(const Ref<Layer> &overlay);

private:
    static Scope<Application> s_Instance;
    Window m_Window;
    LayerStack m_LayerStack;
    EventQueue m_EventQueue;
    EventDispatcher m_EventDispatcher;
};

} // namespace Lumen