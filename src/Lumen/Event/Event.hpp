#pragma once

#include <string>

namespace Lumen
{

enum class EventType
{
    WindowClose = 0,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

enum EventCategory
{
    EventCategoryApplication = 1 << 0,
    EventCategoryInput = 1 << 1,
    EventCategoryKeyboard = 1 << 2,
    EventCategoryMouse = 1 << 3,
    EventCategoryMouseButton = 1 << 4
};

class Event
{
public:
    bool Handled = false;

    virtual ~Event() = default;

    [[nodiscard]] virtual EventType GetType() const = 0;
    [[nodiscard]] virtual int GetCategoryFlags() const = 0;
    [[nodiscard]] virtual std::string ToString() const = 0;

    bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
};

class EventDispatcher
{
public:
    EventDispatcher(Event &event);

    template <typename T, typename F> bool Dispatch(const F &func)
    {
        if (m_Event.GetType() == T::GetStaticType())
        {
            m_Event.Handled = func(static_cast<T &>(m_Event));
            return true;
        }
        return false;
    }

private:
    Event &m_Event;
};

} // namespace Lumen