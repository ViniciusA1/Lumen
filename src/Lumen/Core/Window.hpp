#pragma once

#include <string>

namespace Lumen
{

struct WindowArgs
{
    std::string Title;
    unsigned int Width;
    unsigned int Height;

    WindowArgs(std::string title, unsigned int width, unsigned int height)
        : Title(std::move(title)), Width(width), Height(height)
    {
    }
};

class Window
{
public:
    Window(WindowArgs args);
    ~Window();

private:
    WindowArgs m_WinData;
};

} // namespace Lumen