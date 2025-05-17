#pragma once

#include "Lumen/Input/KeyCode.hpp"

#include <string>

namespace Lumen
{

class KeyEvent
{
public:
    [[nodiscard]] KeyCode GetKeyCode() const { return m_KeyCode; }

protected:
    KeyEvent(KeyCode keycode);

    KeyCode m_KeyCode;
};

class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(KeyCode keycode, int repeatCount);

    [[nodiscard]] int GetRepeatCount() const { return m_RepeatCount; }
    [[nodiscard]] std::string ToString() const
    {
        return "KeyPressedEvent: " + std::to_string(static_cast<int>(m_KeyCode)) + " (" +
               std::to_string(m_RepeatCount) + " repeats)";
    }

private:
    int m_RepeatCount;
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(KeyCode keycode);

    [[nodiscard]] std::string ToString() const
    {
        return "KeyReleasedEvent: " + std::to_string(static_cast<int>(m_KeyCode));
    }
};

} // namespace Lumen