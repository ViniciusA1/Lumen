#pragma once

#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

class UILayer : public Layer
{
public:
    UILayer(std::string name, bool isVisible = true);

    void OnDraw() override;
    virtual void OnUIDraw() {};
};

} // namespace Lumen