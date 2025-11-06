#include "Lumen/Layer/Layer.hpp"

namespace Lumen
{

Layer::Layer(std::string name, bool visible)
    : m_Name(std::move(name)), m_IsVisible(visible)
{
}

bool Layer::IsVisible() const
{
    return m_IsVisible;
}

std::string Layer::GetName() const
{
    return m_Name;
}

void Layer::SetVisible(bool visible)
{
    m_IsVisible = visible;
}

} // namespace Lumen