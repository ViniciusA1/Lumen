#pragma once

#include "Lumen/Core/Layer.hpp"

namespace Lumen
{

class LUILayer : public Layer
{
public:
    LUILayer(std::string name, bool isVisible = true);

    void OnDraw() override;
    virtual void OnLUIDraw() {};
};

} // namespace Lumen