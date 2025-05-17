#pragma once

#include "Lumen/Input/MouseCode.hpp"
#include <string>

namespace Lumen
{

class MouseMovedEvent
{
public:
    MouseMovedEvent(int x, int y);

    [[nodiscard]] int GetX() const { return m_MouseX; }
    [[nodiscard]] int GetY() const { return m_MouseY; }
    [[nodiscard]] std::string ToString() const
    {
        return "MouseMovedEvent: " + std::to_string(m_MouseX) + ", " +
               std::to_string(m_MouseY);
    }

private:
    int m_MouseX;
    int m_MouseY;
};

class MouseScrolledEvent
{
public:
    MouseScrolledEvent(float xOffset, float yOffset);

    [[nodiscard]] float GetXOffset() const { return m_XOffset; }
    [[nodiscard]] float GetYOffset() const { return m_YOffset; }
    [[nodiscard]] std::string ToString() const
    {
        return "MouseScrolledEvent: " + std::to_string(m_XOffset) + ", " +
               std::to_string(m_YOffset);
    }

private:
    float m_XOffset, m_YOffset;
};

class MouseButtonEvent
{
public:
    [[nodiscard]] MouseCode GetMouseButton() const { return m_Button; }
    [[nodiscard]] int GetX() const { return m_MouseX; };
    [[nodiscard]] int GetY() const { return m_MouseY; }

protected:
    MouseButtonEvent(MouseCode button, int mouseX, int mouseY);

    MouseCode m_Button;
    int m_MouseX;
    int m_MouseY;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(MouseCode button, int mouseX, int mouseY);

    [[nodiscard]] std::string ToString() const
    {
        return "MouseButtonPressedEvent: " + std::to_string(static_cast<int>(m_Button)) +
               " " + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
    }
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(MouseCode button, int mouseX, int mouseY);

    [[nodiscard]] std::string ToString() const
    {
        return "MouseButtonReleasedEvent: " + std::to_string(static_cast<int>(m_Button)) +
               " " + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
    }
};

} // namespace Lumen