#pragma once

#include "Lumen/Scene/System/DrawSystem.hpp"

namespace Lumen
{

class ModelRendererSystem : public DrawSystem
{
public:
    ModelRendererSystem(World &world);

    void OnDraw() final;
};

} // namespace Lumen