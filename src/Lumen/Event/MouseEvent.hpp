#pragma once

#include "Lumen/Event/Event.hpp"

namespace Lumen
{

class MouseMovedEvent : public Event
{
public:
    MouseMovedEvent(float x, float y);

    static EventType GetStaticType() { return EventType::MouseMoved; }
    [[nodiscard]] float GetX() const { return m_MouseX; }
    [[nodiscard]] float GetY() const { return m_MouseY; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return (EventCategoryMouse | EventCategoryInput);
    }
    [[nodiscard]] std::string ToString() const override
    {
        return "MouseMovedEvent: " + std::to_string(m_MouseX) + ", " +
               std::to_string(m_MouseY);
    }

private:
    float m_MouseX, m_MouseY;
};

class MouseScrolledEvent : public Event
{
public:
    MouseScrolledEvent(float xOffset, float yOffset);

    static EventType GetStaticType() { return EventType::MouseMoved; }
    [[nodiscard]] float GetXOffset() const { return m_XOffset; }
    [[nodiscard]] float GetYOffset() const { return m_YOffset; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return (EventCategoryMouse | EventCategoryInput);
    }
    [[nodiscard]] std::string ToString() const override
    {
        return "MouseScrolledEvent: " + std::to_string(m_XOffset) + ", " +
               std::to_string(m_YOffset);
    }

private:
    float m_XOffset, m_YOffset;
};

class MouseButtonEvent : public Event
{
public:
    [[nodiscard]] int GetMouseButton() const { return m_Button; }
    [[nodiscard]] float GetX() const { return m_MouseX; };
    [[nodiscard]] float GetY() const { return m_MouseY; }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return (EventCategoryMouse | EventCategoryInput);
    }

protected:
    MouseButtonEvent(int button, float mouseX, float mouseY);

    int m_Button;
    float m_MouseX, m_MouseY;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(int button, float mouseX, float mouseY);

    static EventType GetStaticType() { return EventType::MouseButtonPressed; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] std::string ToString() const override
    {
        return "MouseButtonPressedEvent: " + std::to_string(m_Button) + " " +
               std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
    }
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(int button, float mouseX, float mouseY);

    static EventType GetStaticType() { return EventType::MouseButtonReleased; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] std::string ToString() const override
    {
        return "MouseButtonReleasedEvent: " + std::to_string(m_Button) + " " +
               std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
    }
};

} // namespace Lumen