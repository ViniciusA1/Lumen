#pragma once

#include "Lumen/World/System/DrawSystem.hpp"

namespace Lumen
{

class MeshRendererSystem : public DrawSystem
{
public:
    MeshRendererSystem(World &world);

    void OnDraw() final;
};

} // namespace Lumen