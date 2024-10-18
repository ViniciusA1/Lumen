#pragma once

#include "Lumen/Event/Action.hpp"
#include "Lumen/Event/KeyboardEvent.hpp"
#include <unordered_map>

namespace Lumen
{

using KeyboardAction = Action<void()>;

class KeyboardListener
{
public:
    void OnKeyPressed(KeyPressedEvent &event);
    void OnKeyReleased(KeyReleasedEvent &event);

    void BindPressedAction(KeyCode key, const KeyboardAction &action);
    void BindReleasedAction(KeyCode key, const KeyboardAction &action);

    void UnbindKeyPressed(KeyCode key);
    void UnbindKeyReleased(KeyCode key);

private:
    std::unordered_map<KeyCode, KeyboardAction> m_KeyPressedMap;
    std::unordered_map<KeyCode, KeyboardAction> m_KeyReleasedMap;
};

} // namespace Lumen