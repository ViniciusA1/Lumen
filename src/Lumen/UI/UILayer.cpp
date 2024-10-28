#include "Lumen/UI/UILayer.hpp"

namespace Lumen
{

UILayer::UILayer(std::string name, bool isVisible) : Layer(std::move(name), isVisible)
{
}

void UILayer::OnDraw()
{
}

} // namespace Lumen