#include "Lumen/Core/Window.hpp"

namespace Lumen
{

Window::Window(WindowArgs args) : m_WinData(std::move(args))
{
}

} // namespace Lumen