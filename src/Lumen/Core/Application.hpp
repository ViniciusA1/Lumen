#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/Core/Window.hpp"

namespace Lumen
{

struct ApplicationArgs
{
    WindowArgs WinProperty;
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

private:
    static Scope<Application> s_Instance;
    Window m_Window;
};

} // namespace Lumen