#pragma once

#include <string>

namespace Lumen
{

class WindowResizeEvent
{
public:
    WindowResizeEvent(int width, int height);

    [[nodiscard]] unsigned int GetWidth() const { return m_Width; }
    [[nodiscard]] unsigned int GetHeight() const { return m_Height; }
    [[nodiscard]] std::string ToString() const
    {
        return "WindowResizeEvent: " + std::to_string(m_Width) + ", " +
               std::to_string(m_Height);
    }

private:
    unsigned int m_Width, m_Height;
};

class WindowCloseEvent
{
public:
    WindowCloseEvent() = default;

    [[nodiscard]] std::string ToString() const { return "WindowCloseEvent"; }
};

} // namespace Lumen