#include "Lumen/World/System/UI/UIDrawSystem.hpp"
#include "Lumen/World/Component/ComponentGroup.hpp"
#include "Lumen/World/System/UI/UIComponentFunc.hpp"
#include "Lumen/World/World.hpp"

namespace Lumen
{

UIDrawSystem::UIDrawSystem(World &world) : DrawSystem(world)
{
}

void UIDrawSystem::OnDraw()
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
                    DrawUIComponent<Component>(
                        transform, manager.GetComponent<Component>(childEntity));
                }
            });
        }
    }
}

} // namespace Lumen