#include "Lumen/Scene/System/UI/UIDrawSystem.hpp"
#include "Lumen/Scene/Component/ComponentGroup.hpp"

namespace Lumen
{

UIDrawSystem::UIDrawSystem(World &world) : DrawSystem(world)
{
}

void UIDrawSystem::OnDraw()
{
    UIComponentGroup::ForEachComponent([this]<typename Component> {
        const auto query = Query<TransformComponent, Component>();
        for (const auto &[entity, transform, component] : query.Each())
        {
            DrawUIComponent<Component>(transform, component);
        }
    });
}

} // namespace Lumen