#include "Lumen/Scene/Entity/System/SpriteRendererSystem.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

SpriteRendererSystem::SpriteRendererSystem(World &world) : System(world)
{
}

void SpriteRendererSystem::OnUpdate()
{
    auto query = Query<TransformComponent, SpriteRendererComponent>();

    for (const auto &[entity, transform, sprite] : query.Each())
    {
        Renderer::DrawQuad({transform.Position.x, transform.Position.y}, {100, 100},
                           sprite.Color);
    }
}

} // namespace Lumen