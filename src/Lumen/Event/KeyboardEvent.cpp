#include "Lumen/Event/KeyboardEvent.hpp"

namespace Lumen
{

KeyEvent::KeyEvent(int keycode) : m_KeyCode(keycode)
{
}

KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount)
    : KeyEvent(keycode), m_RepeatCount(repeatCount)
{
}

KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode)
{
}

} // namespace Lumen