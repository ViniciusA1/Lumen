#include "Lumen/Core/Window.hpp"
#include <raylib.h>

namespace Lumen
{

static unsigned int s_InstanceAmount = 0;

Window::Window(WindowArgs args) : m_WinData(std::move(args))
{
    if (s_InstanceAmount == 0)
    {
        ::SetWindowState(Enum::ToInt(m_WinData.Flags));
        ::InitWindow(args.Width, args.Height, m_WinData.Title.c_str());
        ::SetTargetFPS(m_WinData.TargetFPS);
    }
    s_InstanceAmount++;
}

Window::~Window()
{
    if (s_InstanceAmount == 1)
    {
        ::CloseWindow();
    }
    s_InstanceAmount--;
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

Texture2D Window::GetIcon() const
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
    return {(float)m_WinData.Width, (float)m_WinData.Height};
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
    m_WinData.Icon = icon;
}

void Window::SetMaxSize(int width, int height)
{
    ::SetWindowMaxSize(width, height);
}

void Window::SetMinSize(int width, int height)
{
    ::SetWindowMinSize(width, height);
}

void Window::SetOpacity(float opacity)
{
    ::SetWindowOpacity(opacity);
}

void Window::SetPosition(int x, int y)
{
    ::SetWindowPosition(x, y);
}

void Window::SetSize(int width, int height)
{
    m_WinData.Width = width;
    m_WinData.Height = height;
    ::SetWindowSize(width, height);
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

} // namespace Lumen