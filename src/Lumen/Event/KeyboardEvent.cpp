#include "Lumen/Event/KeyboardEvent.hpp"

namespace Lumen
{

KeyEvent::KeyEvent(KeyCode keycode) : m_KeyCode(keycode)
{
}

KeyPressedEvent::KeyPressedEvent(KeyCode keycode, int repeatCount)
    : KeyEvent(keycode), m_RepeatCount(repeatCount)
{
}

KeyReleasedEvent::KeyReleasedEvent(KeyCode keycode) : KeyEvent(keycode)
{
}

} // namespace Lumen