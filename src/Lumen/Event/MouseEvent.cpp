#include "Lumen/Event/MouseEvent.hpp"

namespace Lumen
{

MouseMovedEvent::MouseMovedEvent(int x, int y) : m_MouseX(x), m_MouseY(y)
{
}

MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
    : m_XOffset(xOffset), m_YOffset(yOffset)
{
}

MouseButtonEvent::MouseButtonEvent(MouseCode button, int mouseX, int mouseY)
    : m_Button(button), m_MouseX(mouseX), m_MouseY(mouseY)
{
}

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode button, int mouseX, int mouseY)
    : MouseButtonEvent(button, mouseX, mouseY)
{
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode button, int mouseX,
                                                   int mouseY)
    : MouseButtonEvent(button, mouseX, mouseY)
{
}

} // namespace Lumen