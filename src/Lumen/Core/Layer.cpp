#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

Layer::Layer(std::string name, bool visible)
    : m_Name(std::move(name)), m_IsVisible(visible)
{
}

void Layer::AddKeyboardListener(const KeyboardListener &listener)
{
    m_KeyboardListener.push_back(listener);
}

void Layer::AddMouseListener(const MouseListener &listener)
{
    m_MouseListener.push_back(listener);
}

} // namespace Lumen