#pragma once

#include "Lumen/Application/ApplicationArgs.hpp"
#include "Lumen/Application/Window.hpp"
#include "Lumen/Event/LayerEvent.hpp"
#include "Lumen/Event/WindowEvent.hpp"
#include "Lumen/Layer/LayerStack.hpp"
#include "Lumen/Memory/Memory.hpp"

namespace Lumen
{

class EngineInitializer;

class Application
{
public:
    Application(const Ref<EngineInitializer> &initializer = nullptr);
    virtual ~Application();

    [[nodiscard]] bool IsRunning() const;

    static Application &Get();
    [[nodiscard]] ApplicationArgs GetArgs() const;
    [[nodiscard]] const Window &GetWindow() const;
    Window &GetWindow();

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

    friend class EngineInitializer;
};

Ref<Application> CreateApplication();

} // namespace Lumen