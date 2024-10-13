#include "Lumen/Event/ApplicationEvent.hpp"

namespace Lumen
{

WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
    : m_Width(width), m_Height(height)
{
}

} // namespace Lumen