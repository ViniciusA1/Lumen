#include "Lumen/Application/Application.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterApplication();
static void RegisterApplicationArgs();
static void RegisterWindow();
static void RegisterWindowArgs();

void RegisterApplicationAPI()
{
    RegisterApplication();
    RegisterApplicationArgs();
    RegisterWindow();
    RegisterWindowArgs();
}

static void RegisterApplication()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Application>("Application")
        .StaticMethod("global", &Application::Get)
        .Property("args", &Application::GetArgs)
        .Property("window", &Application::GetWindow);
}

static void RegisterApplicationArgs()
{
    ScriptEngine::GetInstance()
        ->RegisterType<ApplicationArgs>("ApplicationArgs")
        .Constructors<ApplicationArgs()>()
        .Property("title", &ApplicationArgs::Title)
        .Property("resolution", &ApplicationArgs::Resolution)
        .Property("icon", &ApplicationArgs::Icon)
        .Property("flags", &ApplicationArgs::Flags)
        .Property("target_fps", &ApplicationArgs::TargetFPS)
        .Property("root_directory", &ApplicationArgs::RootDirectory)
        .Property("asset_directory", &ApplicationArgs::AssetDirectory)
        .Property("start_scene", &ApplicationArgs::StartScene);
}

static void RegisterWindow()
{
    auto &engine = ScriptEngine::GetInstance();

    engine->RegisterEnum<WindowFlags>("WindowFlags")
        .Value("VSyncHint", WindowFlags::VSyncHint)
        .Value("FullScreenMode", WindowFlags::FullScreenMode)
        .Value("Resizable", WindowFlags::Resizable)
        .Value("Undecorated", WindowFlags::Undecorated)
        .Value("Hidden", WindowFlags::Hidden)
        .Value("Minimized", WindowFlags::Minimized)
        .Value("Maximized", WindowFlags::Maximized)
        .Value("Unfocused", WindowFlags::Unfocused)
        .Value("TopMost", WindowFlags::TopMost)
        .Value("AlwaysRun", WindowFlags::AlwaysRun)
        .Value("Transparent", WindowFlags::Transparent)
        .Value("HighDPI", WindowFlags::HighDPI)
        .Value("MousePassThrough", WindowFlags::MousePassThrough)
        .Value("BorderlessWindowedMode", WindowFlags::BorderlessWindowedMode)
        .Value("MSAA4xHint", WindowFlags::MSAA4xHint)
        .Value("InterlacedHint", WindowFlags::InterlacedHint);

    engine->RegisterType<Window>("Window")
        .Method("is_cursor_hidden", &Window::IsCursorHidden)
        .Method("is_cursor_on_screen", &Window::IsCursorOnScreen)
        .Method("is_focused", &Window::IsFocused)
        .Method("is_fullscreen", &Window::IsFullscreen)
        .Method("is_hidden", &Window::IsHidden)
        .Method("is_maximized", &Window::IsMaximized)
        .Method("is_minimized", &Window::IsMinimized)
        .Method("is_ready", &Window::IsReady)
        .Method("is_resized", &Window::IsResized)
        .Method("is_running", &Window::IsRunning)
        .Method("is_state_enabled", &Window::IsStateEnabled)
        .Property("icon", &Window::GetIcon)
        .Property("clipboard_text", &Window::GetClipboardText)
        .Property("position", &Window::GetPosition,
                  static_cast<void (Window::*)(const Vector2 &)>(&Window::SetPosition))
        .Property("size", &Window::GetSize,
                  static_cast<void (Window::*)(const Vector2 &)>(&Window::SetSize))
        .Property("title", &Window::GetTitle, &Window::SetTitle)
        .Method("set_focused", &Window::SetFocused)
        .Method("set_icon", &Window::SetIcon)
        .Method("set_max_size",
                static_cast<void (Window::*)(int, int)>(&Window::SetMaxSize),
                static_cast<void (Window::*)(const Vector2 &)>(&Window::SetMaxSize))
        .Method("set_min_size",
                static_cast<void (Window::*)(int, int)>(&Window::SetMinSize),
                static_cast<void (Window::*)(const Vector2 &)>(&Window::SetMinSize))
        .Method("set_opacity", &Window::SetOpacity)
        .Method("set_state", &Window::SetState)
        .Method("clear_window_state", &Window::ClearWindowState)
        .Method("disable_cursor", &Window::DisableCursor)
        .Method("enable_cursor", &Window::EnableCursor)
        .Method("hide_cursor", &Window::HideCursor)
        .Method("maximize_window", &Window::MaximizeWindow)
        .Method("minimize_window", &Window::MinimizeWindow)
        .Method("restore_window", &Window::RestoreWindow)
        .Method("show_cursor", &Window::ShowCursor)
        .Method("toggle_borderless_windowed", &Window::ToggleBorderlessWindowed)
        .Method("toggle_fullscreen", &Window::ToggleFullscreen);
}

static void RegisterWindowArgs()
{
    ScriptEngine::GetInstance()
        ->RegisterType<WindowArgs>("WindowArgs")
        .Constructors<WindowArgs()>()
        .Property("title", &WindowArgs::Title)
        .Property("resolution", &WindowArgs::Resolution)
        .Property("icon", &WindowArgs::Icon)
        .Property("flags", &WindowArgs::Flags)
        .Property("target_fps", &WindowArgs::TargetFPS);
}

} // namespace Lumen