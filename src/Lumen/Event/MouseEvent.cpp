#include "Lumen/Event/MouseEvent.hpp"

namespace Lumen
{

MouseMovedEvent::MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y)
{
}

MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset)
    : m_XOffset(xOffset), m_YOffset(yOffset)
{
}

MouseButtonEvent::MouseButtonEvent(int button, float mouseX, float mouseY)
    : m_Button(button), m_MouseX(mouseX), m_MouseY(mouseY)
{
}

MouseButtonPressedEvent::MouseButtonPressedEvent(int button, float mouseX, float mouseY)
    : MouseButtonEvent(button, mouseX, mouseY)
{
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button, float mouseX, float mouseY)
    : MouseButtonEvent(button, mouseX, mouseY)
{
}

} // namespace Lumen