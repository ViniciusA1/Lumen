#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

Layer::Layer(std::string name, bool visible)
    : m_Name(std::move(name)), m_IsVisible(visible)
{
}

} // namespace Lumen