#include "Lumen/Event/KeyboardListener.hpp"

namespace Lumen
{

void KeyboardListener::OnKeyPressed(KeyPressedEvent &event)
{
    auto it = m_KeyPressedMap.find(event.GetKeyCode());
    if (it != m_KeyPressedMap.end())
    {
        it->second();
    }
}

void KeyboardListener::OnKeyReleased(KeyReleasedEvent &event)
{
    auto it = m_KeyReleasedMap.find(event.GetKeyCode());
    if (it != m_KeyReleasedMap.end())
    {
        it->second();
    }
}

void KeyboardListener::BindPressedAction(KeyCode key, const KeyboardAction &action)
{
    m_KeyPressedMap[key] = action;
}

void KeyboardListener::BindReleasedAction(KeyCode key, const KeyboardAction &action)
{
    m_KeyReleasedMap[key] = action;
}

void KeyboardListener::UnbindKeyPressed(KeyCode key)
{
    m_KeyPressedMap.erase(key);
}

void KeyboardListener::UnbindKeyReleased(KeyCode key)
{
    m_KeyReleasedMap.erase(key);
}

} // namespace Lumen