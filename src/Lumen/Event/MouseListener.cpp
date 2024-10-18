#include "Lumen/Event/MouseListener.hpp"

namespace Lumen
{

void MouseListener::OnMouseMoved(MouseMovedEvent &event)
{
    if (m_MouseMovedAction.Func)
    {
        m_MouseMovedAction(event.GetX(), event.GetY());
    }
}

void MouseListener::OnMouseScrolled(MouseScrolledEvent &event)
{
    if (m_MouseScrolledAction.Func)
    {
        m_MouseScrolledAction(event.GetXOffset(), event.GetYOffset());
    }
}

void MouseListener::OnMouseButtonPressed(MouseButtonPressedEvent &event)
{
    auto it = m_MouseButtonPressedMap.find(event.GetMouseButton());
    if (it != m_MouseButtonPressedMap.end())
    {
        it->second(event.GetX(), event.GetY());
    }
}

void MouseListener::OnMouseButtonReleased(MouseButtonReleasedEvent &event)
{
    auto it = m_MouseButtonReleasedMap.find(event.GetMouseButton());
    if (it != m_MouseButtonReleasedMap.end())
    {
        it->second(event.GetX(), event.GetY());
    }
}

void MouseListener::BindMovedAction(const MouseAction &action)
{
    m_MouseMovedAction = action;
}

void MouseListener::BindScrolledAction(const MouseAction &action)
{
    m_MouseScrolledAction = action;
}

void MouseListener::BindButtonPressedAction(MouseCode button, const MouseAction &action)
{
    m_MouseButtonPressedMap[button] = action;
}

void MouseListener::BindButtonReleasedAction(MouseCode button, const MouseAction &action)
{
    m_MouseButtonReleasedMap[button] = action;
}

void MouseListener::UnbindMovedAction()
{
    m_MouseMovedAction = {};
}

void MouseListener::UnbindScrolledAction()
{
    m_MouseScrolledAction = {};
}

void MouseListener::UnbindButtonPressedAction(MouseCode button)
{
    m_MouseButtonPressedMap.erase(button);
}

void MouseListener::UnbindButtonReleasedAction(MouseCode button)
{
    m_MouseButtonReleasedMap.erase(button);
}

} // namespace Lumen