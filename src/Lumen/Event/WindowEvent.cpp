#include "Lumen/Event/WindowEvent.hpp"

namespace Lumen
{

WindowResizeEvent::WindowResizeEvent(int width, int height)
    : m_Width(width), m_Height(height)
{
}

} // namespace Lumen