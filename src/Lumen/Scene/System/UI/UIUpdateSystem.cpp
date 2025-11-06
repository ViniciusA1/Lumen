#include "Lumen/Scene/System/UI/UIUpdateSystem.hpp"
#include "Lumen/Scene/Component/ComponentGroup.hpp"
#include "Lumen/Scene/System/UI/UIComponentFunc.hpp"
#include "Lumen/Scene/World.hpp"

namespace Lumen
{

UIUpdateSystem::UIUpdateSystem(World &world) : UpdateSystem(world)
{
}

void UIUpdateSystem::OnUpdate()
{
    auto query = Query<TransformComponent, CanvasComponent, ChildrenComponent>();

    for (const auto &[entity, transform, canvas, children] : query.Each())
    {
        for (const auto &childEntityID : children.ChildrenID)
        {
            auto &manager = m_ParentWorld.GetEntityManager();
            auto childEntity = manager.GetEntity(childEntityID);

            UIComponentGroup::ForEachComponent([&]<typename Component> {
                if (manager.HasComponent<Component>(childEntity))
                {
                    UpdateUIComponent<Component>(
                        transform, manager.GetComponent<Component>(childEntity));
                }
            });
        }
    }
}

} // namespace Lumen