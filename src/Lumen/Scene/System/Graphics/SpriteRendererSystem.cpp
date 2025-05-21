#include "Lumen/Scene/System/Graphics/SpriteRendererSystem.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

SpriteRendererSystem::SpriteRendererSystem(World &world) : DrawSystem(world)
{
}

void SpriteRendererSystem::OnDraw()
{
    auto query = Query<TransformComponent, SpriteRendererComponent>();

    for (const auto &[entity, transform, sprite] : query.Each())
    {
        Renderer::DrawQuad(transform, sprite.Color);
    }
}

} // namespace Lumen