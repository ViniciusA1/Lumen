#include "Lumen/Scene/System/UI/UIUpdateSystem.hpp"
#include "Lumen/Scene/Component/ComponentGroup.hpp"

namespace Lumen
{

UIUpdateSystem::UIUpdateSystem(World &world) : UpdateSystem(world)
{
}

void UIUpdateSystem::OnUpdate()
{
    UIComponentGroup::ForEachComponent([this]<typename Component> {
        const auto query = Query<TransformComponent, Component>();
        for (const auto &[entity, transform, component] : query.Each())
        {
            UpdateUIComponent<Component>(transform, component);
        }
    });
}

} // namespace Lumen