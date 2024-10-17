#pragma once

#include <string>

namespace Lumen
{

class WindowResizeEvent
{
public:
    WindowResizeEvent(int width, int height);

    [[nodiscard]] int GetWidth() const { return m_Width; }
    [[nodiscard]] int GetHeight() const { return m_Height; }
    [[nodiscard]] std::string ToString() const
    {
        return "WindowResizeEvent: " + std::to_string(m_Width) + ", " +
               std::to_string(m_Height);
    }

private:
    int m_Width, m_Height;
};

class WindowCloseEvent
{
public:
    WindowCloseEvent() = default;

    [[nodiscard]] std::string ToString() const { return "WindowCloseEvent"; }
};

} // namespace Lumen