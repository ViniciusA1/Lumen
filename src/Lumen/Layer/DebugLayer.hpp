#pragma once

#include "Lumen/Layer/Layer.hpp"

namespace Lumen
{

class DebugLayer : public Layer
{
public:
    DebugLayer(std::string name, bool isVisible = true);

    void OnDraw() override;
    virtual void OnLUIDraw() {};
};

} // namespace Lumen