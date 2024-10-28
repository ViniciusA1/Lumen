#include "Lumen/Scene/Entity/System/MovementSystem.hpp"
#include "Lumen/Core/Time.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

MovementSystem::MovementSystem(World &world) : System(world)
{
}

void MovementSystem::OnUpdate()
{
    auto query = Query<TransformComponent, VelocityComponent>();

    for (auto [entity, transform, velocity] : query.Each())
    {
        transform.Position += velocity.Velocity * Time::GetDeltaTime();
    }
}

} // namespace Lumen