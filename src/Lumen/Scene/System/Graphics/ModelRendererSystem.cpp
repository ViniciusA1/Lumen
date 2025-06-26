#include "Lumen/Scene/System/Graphics/ModelRendererSystem.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

ModelRendererSystem::ModelRendererSystem(World &world) : DrawSystem(world)
{
}

void ModelRendererSystem::OnDraw()
{
    auto query = Query<TransformComponent, ModelRendererComponent>();

    for (const auto &[entity, transform, modelRenderer] : query.Each())
    {
        Renderer::DrawModel(transform, AssetManager::Get<Model>(modelRenderer.Model),
                            Color::White);
    }
}

} // namespace Lumen