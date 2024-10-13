#pragma once

#include "Lumen/Event/Event.hpp"

namespace Lumen
{

class KeyEvent : public Event
{
public:
    [[nodiscard]] int GetKeyCode() const { return m_KeyCode; }
    [[nodiscard]] int GetCategoryFlags() const override
    {
        return (EventCategoryKeyboard | EventCategoryInput);
    }

protected:
    KeyEvent(int keycode);

    int m_KeyCode;
};

class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(int keycode, int repeatCount);

    static EventType GetStaticType() { return EventType::KeyPressed; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] int GetRepeatCount() const { return m_RepeatCount; }
    [[nodiscard]] std::string ToString() const override
    {
        return "KeyPressedEvent: " + std::to_string(m_KeyCode) + " (" +
               std::to_string(m_RepeatCount) + " repeats)";
    }

private:
    int m_RepeatCount;
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(int keycode);

    static EventType GetStaticType() { return EventType::KeyReleased; }
    [[nodiscard]] EventType GetType() const override { return GetStaticType(); }
    [[nodiscard]] std::string ToString() const override
    {
        return "KeyReleasedEvent: " + std::to_string(m_KeyCode);
    }
};

} // namespace Lumen