#pragma once

#include "Lumen/Scene/Entity/System/System.hpp"

namespace Lumen
{

class SpriteRendererSystem : public System
{
public:
    SpriteRendererSystem(World &world);

    void OnUpdate() override;
};

} // namespace Lumen