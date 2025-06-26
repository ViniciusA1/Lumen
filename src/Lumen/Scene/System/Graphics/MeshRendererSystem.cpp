#include "Lumen/Scene/System/Graphics/MeshRendererSystem.hpp"
#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Graphics/Renderer.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

MeshRendererSystem::MeshRendererSystem(World &world) : DrawSystem(world)
{
}

void MeshRendererSystem::OnDraw()
{
    const auto query = Query<TransformComponent, MeshRendererComponent>();

    for (const auto &[entity, transform, meshRenderer] : query.Each())
    {
        Renderer::DrawMesh(transform, AssetManager::Get<Mesh>(meshRenderer.Mesh),
                           AssetManager::Get<Material>(meshRenderer.Material));
    }
}

} // namespace Lumen