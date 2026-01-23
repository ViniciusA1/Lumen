#include "Lumen/World/System/DrawSystem.hpp"

namespace Lumen
{

DrawSystem::DrawSystem(World &world, std::string name) : System(world, std::move(name))
{
}

} // namespace Lumen