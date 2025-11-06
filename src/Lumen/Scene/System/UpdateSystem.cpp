#include "Lumen/Scene/System/UpdateSystem.hpp"

namespace Lumen
{

UpdateSystem::UpdateSystem(World &world, std::string name)
    : System(world, std::move(name))
{
}

} // namespace Lumen