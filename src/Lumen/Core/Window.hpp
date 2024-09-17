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

    [[nodiscard]] std::string GetTitle() const { return m_WinData.Title; }
    [[nodiscard]] unsigned int GetWidth() const { return m_WinData.Width; }
    [[nodiscard]] unsigned int GetHeight() const { return m_WinData.Height; }
    [[nodiscard]] bool IsRunning() const;

private:
    WindowArgs m_WinData;
};

} // namespace Lumen