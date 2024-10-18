#pragma once

#include "Lumen/Event/Action.hpp"
#include "Lumen/Event/MouseEvent.hpp"
#include <unordered_map>

namespace Lumen
{

using MouseAction = Action<void(int, int)>;

class MouseListener
{
public:
    void OnMouseMoved(MouseMovedEvent &event);
    void OnMouseScrolled(MouseScrolledEvent &event);
    void OnMouseButtonPressed(MouseButtonPressedEvent &event);
    void OnMouseButtonReleased(MouseButtonReleasedEvent &event);

    void BindMovedAction(const MouseAction &action);
    void BindScrolledAction(const MouseAction &action);
    void BindButtonPressedAction(MouseCode button, const MouseAction &action);
    void BindButtonReleasedAction(MouseCode button, const MouseAction &action);

    void UnbindMovedAction();
    void UnbindScrolledAction();
    void UnbindButtonPressedAction(MouseCode button);
    void UnbindButtonReleasedAction(MouseCode button);

private:
    MouseAction m_MouseMovedAction;
    MouseAction m_MouseScrolledAction;
    std::unordered_map<MouseCode, MouseAction> m_MouseButtonPressedMap;
    std::unordered_map<MouseCode, MouseAction> m_MouseButtonReleasedMap;
};

} // namespace Lumen