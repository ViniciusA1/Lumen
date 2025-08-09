#pragma once

#include "Lumen/Scene/System/UpdateSystem.hpp"

namespace Lumen
{

class UIUpdateSystem : public UpdateSystem
{
public:
    UIUpdateSystem(World &world);

    void OnUpdate() final;
};

} // namespace Lumen