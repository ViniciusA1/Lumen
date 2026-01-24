#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"
#include "Lumen/Application/Window.hpp"
#include "Lumen/Event/LayerEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"
#include "Lumen/Layer/LayerStack.hpp"

namespace Lumen
{

class Application
{
public:
    Application();
    virtual ~Application();

    [[nodiscard]] bool IsRunning() const;

    [[nodiscard]] static Application &Get();
    [[nodiscard]] const ApplicationArgs &GetArgs() const;
    [[nodiscard]] ApplicationArgs &GetArgs();
    [[nodiscard]] const Window &GetWindow() const;
    [[nodiscard]] Window &GetWindow();

    template <typename T, typename... Args> inline Application &AddModule(Args &&...args);

    virtual void Run();

protected:
    void OnWindowResize(const WindowResizeEvent &event);
    void OnWindowClose(const WindowCloseEvent &event);
    void OnLayerPush(const LayerPushEvent &event);
    void OnLayerPop(const LayerPopEvent &event);

protected:
    static Application *s_Instance;

    ApplicationArgs m_Args;

    bool m_IsRunning = true;
    Window m_Window;
    LayerStack m_LayerStack;
};

template <typename T, typename... Args>
Application &Application::AddModule(Args &&...args)
{
    T(*this, std::forward<Args>(args)...).Build();
    return *this;
}

} // namespace Lumen