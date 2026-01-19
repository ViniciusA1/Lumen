#pragma once

#include "Lumen/Scene/System/System.hpp"

namespace Lumen
{

class UpdateSystem : public System
{
public:
    UpdateSystem(World &world, std::string name = "UpdateSystem");

    virtual void OnUpdate() = 0;
};

} // namespace Lumen