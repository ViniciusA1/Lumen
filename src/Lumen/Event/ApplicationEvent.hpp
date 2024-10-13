#pragma once

#include "Lumen/Event/Event.hpp"

namespace Lumen
{

class WindowResizeEvent : public Event
{
public:
    WindowResizeEvent(unsigned int width, unsigned int height);

    static EventType GetStaticType() { return EventType::WindowResize; }
    [[nodiscard]] unsigned int GetWidth() const { return m_Width; }
    [[nodiscard]] unsigned int GetHeight() const { return m_Height; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return EventCategoryApplication;
    }
    [[nodiscard]] std::string ToString() const override
    {
        return "WindowResizeEvent: " + std::to_string(m_Width) + ", " +
               std::to_string(m_Height);
    }

private:
    unsigned int m_Width, m_Height;
};

class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() = default;

    static EventType GetStaticType() { return EventType::WindowClose; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return EventCategoryApplication;
    }
    [[nodiscard]] std::string ToString() const override { return "WindowCloseEvent"; }
};

} // namespace Lumen