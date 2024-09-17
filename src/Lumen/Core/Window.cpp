#include "Lumen/Core/Window.hpp"
#include <raylib.h>

namespace Lumen
{

static bool s_IsCreated = false;

Window::Window(WindowArgs args) : m_WinData(std::move(args))
{
    if (s_IsCreated == false)
    {
        InitWindow(args.Width, args.Height, args.Title.c_str());
        s_IsCreated = true;
    }
}

Window::~Window()
{
    if (s_IsCreated == true)
    {
        CloseWindow();
        s_IsCreated = false;
    }
}

bool Window::IsRunning() const
{
    return !WindowShouldClose();
}

} // namespace Lumen