#include "Lumen/Application/Window.hpp"

#include "raylib.h"

namespace Lumen
{

static unsigned int s_InstanceAmount = 0;

Window::Window(WindowArgs args) : m_WinData(std::move(args))
{
    if (s_InstanceAmount == 0)
    {
        ::SetWindowState(Enum::ToInt(m_WinData.Flags));
        ::InitWindow(m_WinData.Resolution.x, m_WinData.Resolution.y,
                     m_WinData.Title.c_str());
        ::SetTargetFPS(m_WinData.TargetFPS);
    }
    s_InstanceAmount++;
}

bool Window::IsCursorHidden() const
{
    return ::IsCursorHidden();
}

bool Window::IsCursorOnScreen() const
{
    return ::IsCursorOnScreen();
}

bool Window::IsFocused() const
{
    return ::IsWindowFocused();
}

bool Window::IsFullscreen() const
{
    return ::IsWindowFullscreen();
}

bool Window::IsHidden() const
{
    return IsWindowHidden();
}

bool Window::IsMaximized() const
{
    return ::IsWindowMaximized();
}

bool Window::IsMinimized() const
{
    return ::IsWindowMinimized();
}

bool Window::IsReady() const
{
    return ::IsWindowReady();
}

bool Window::IsResized() const
{
    return ::IsWindowResized();
}

bool Window::IsRunning() const
{
    return !::WindowShouldClose();
}

bool Window::IsStateEnabled(WindowFlags flag) const
{
    return ::IsWindowState(static_cast<unsigned>(flag));
}

AssetHandle Window::GetIcon() const
{
    return m_WinData.Icon;
}

std::string Window::GetClipboardText() const
{
    return ::GetClipboardText();
}

Vector2 Window::GetPosition() const
{
    ::Vector2 position = ::GetWindowPosition();
    return {position.x, position.y};
}

Vector2 Window::GetSize() const
{
    return m_WinData.Resolution;
}

std::string Window::GetTitle() const
{
    return m_WinData.Title;
}

void Window::SetFocused()
{
    ::SetWindowFocused();
}

void Window::SetIcon(const Texture2D &icon)
{
    Image iconImage(::LoadImageFromTexture(icon));
    ::SetWindowIcon(iconImage);
    m_WinData.Icon = icon.GetHandle();
}

void Window::SetMaxSize(int width, int height)
{
    ::SetWindowMaxSize(width, height);
}

void Window::SetMaxSize(const Vector2 &size)
{
    ::SetWindowMaxSize(size.x, size.y);
}

void Window::SetMinSize(int width, int height)
{
    ::SetWindowMinSize(width, height);
}

void Window::SetMinSize(const Vector2 &size)
{
    ::SetWindowMinSize(size.x, size.y);
}

void Window::SetOpacity(float opacity)
{
    ::SetWindowOpacity(opacity);
}

void Window::SetPosition(int x, int y)
{
    ::SetWindowPosition(x, y);
}

void Window::SetPosition(const Vector2 &position)
{
    ::SetWindowPosition(position.x, position.y);
}

void Window::SetSize(int width, int height)
{
    m_WinData.Resolution.x = width;
    m_WinData.Resolution.y = height;
    ::SetWindowSize(width, height);
}

void Window::SetSize(const Vector2 &size)
{
    m_WinData.Resolution = size;
    ::SetWindowSize(size.x, size.y);
}

void Window::SetState(WindowFlags flag)
{
    ::SetWindowState(static_cast<unsigned>(flag));
}

void Window::SetTitle(const std::string &title)
{
    m_WinData.Title = title;
    ::SetWindowTitle(title.c_str());
}

void Window::ClearWindowState(WindowFlags flag)
{
    ::ClearWindowState(static_cast<unsigned>(flag));
}

void Window::DisableCursor()
{
    ::DisableCursor();
}

void Window::EnableCursor()
{
    ::EnableCursor();
}

void Window::HideCursor()
{
    ::HideCursor();
}

void Window::MaximizeWindow()
{
    ::MaximizeWindow();
}

void Window::MinimizeWindow()
{
    ::MinimizeWindow();
}

void Window::RestoreWindow()
{
    ::RestoreWindow();
}

void Window::ShowCursor()
{
    ::ShowCursor();
}

void Window::ToggleBorderlessWindowed()
{
    ::ToggleBorderlessWindowed();
}

void Window::ToggleFullscreen()
{
    ::ToggleFullscreen();
}

void Window::Close()
{
    if (s_InstanceAmount == 1)
        ::CloseWindow();

    if (s_InstanceAmount > 0)
        s_InstanceAmount--;
}

} // namespace Lumen