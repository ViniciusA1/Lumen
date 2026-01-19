#include "Lumen/Layer/DebugLayer.hpp"

namespace Lumen
{

DebugLayer::DebugLayer(std::string name, bool isVisible)
    : Layer(std::move(name), isVisible)
{
}

void DebugLayer::OnDraw()
{
    OnLUIDraw();
}

} // namespace Lumen