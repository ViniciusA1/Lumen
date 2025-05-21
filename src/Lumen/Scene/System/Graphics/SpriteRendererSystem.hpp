#pragma once

#include "Lumen/Scene/System/DrawSystem.hpp"

namespace Lumen
{

class SpriteRendererSystem : public DrawSystem
{
public:
    SpriteRendererSystem(World &world);

    void OnDraw() final;
};

} // namespace Lumen