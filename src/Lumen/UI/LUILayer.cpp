#include "Lumen/UI/LUILayer.hpp"

namespace Lumen
{

LUILayer::LUILayer(std::string name, bool isVisible) : Layer(std::move(name), isVisible)
{
}

void LUILayer::OnDraw()
{
    OnLUIDraw();
}

} // namespace Lumen