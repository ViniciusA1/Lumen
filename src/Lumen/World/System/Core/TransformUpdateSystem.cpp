#include "Lumen/World/System/Core/TransformUpdateSystem.hpp"
#include "Lumen/Event/EventBus.hpp"
#include "Lumen/World/World.hpp"

namespace Lumen
{

TransformUpdateSystem::TransformUpdateSystem(World &world) : UpdateSystem(world)
{
}

void TransformUpdateSystem::OnCreate()
{
    EventBus::Subscribe<AddChildEvent>(BIND_EVENT(OnAddChild));
    EventBus::Subscribe<RemoveChildEvent>(BIND_EVENT(OnRemoveChild));
    EventBus::Subscribe<ReparentEvent>(BIND_EVENT(OnReparent));
}

void TransformUpdateSystem::OnUpdate()
{
    SyncCamera();
}

void TransformUpdateSystem::SyncCamera()
{
    const auto query = Query<TransformComponent, CameraComponent>();

    for (const auto &[entity, transform, camera] : query.Each())
    {
        const Vector3 right = Vector3::Right(transform.Rotation);
        const Vector3 forward = Vector3::Forward(transform.Rotation);
        const Vector3 up = Vector3::Up(forward, right);

        camera.Position = transform.Position;
        camera.Target = transform.Position + forward;
        camera.Up = up;
    }
}

void TransformUpdateSystem::OnAddChild(const AddChildEvent &event)
{
    auto &manager = m_ParentWorld.GetEntityManager();
    auto parent = manager.GetEntity(event.ParentID);
    auto child = manager.GetEntity(event.ChildID);

    if (!manager.HasComponent<ParentComponent>(child))
        manager.AddComponent<ParentComponent>(child, event.ParentID);
    else
        manager.GetComponent<ParentComponent>(child).ParentID = event.ParentID;

    if (!manager.HasComponent<ChildrenComponent>(parent))
        manager.AddComponent<ChildrenComponent>(parent).ChildrenID.push_back(
            event.ChildID);
    else
        manager.GetComponent<ChildrenComponent>(parent).ChildrenID.push_back(
            event.ChildID);
}

void TransformUpdateSystem::OnRemoveChild(const RemoveChildEvent &event)
{
    auto &manager = m_ParentWorld.GetEntityManager();
    Entity parent = manager.GetEntity(event.ParentID);
    Entity child = manager.GetEntity(event.ChildID);

    if (manager.HasComponent<ParentComponent>(child))
        manager.RemoveComponent<ParentComponent>(child);

    if (manager.HasComponent<ChildrenComponent>(parent))
    {
        auto &children = manager.GetComponent<ChildrenComponent>(parent).ChildrenID;
        UUID childID = manager.GetComponent<IDComponent>(child).ID;
        std::erase(children, childID);

        if (children.empty())
            manager.RemoveComponent<ChildrenComponent>(parent);
    }
}

void TransformUpdateSystem::OnReparent(const ReparentEvent &event)
{
    auto &manager = m_ParentWorld.GetEntityManager();
    Entity child = manager.GetEntity(event.ChildID);

    if (!manager.HasComponent<ParentComponent>(child))
    {
        OnAddChild({event.NewParentID, event.ChildID});
        return;
    }

    UUID oldParentID = manager.GetComponent<ParentComponent>(child).ParentID;

    OnRemoveChild({oldParentID, event.ChildID});
    OnAddChild({event.NewParentID, event.ChildID});
}

} // namespace Lumen