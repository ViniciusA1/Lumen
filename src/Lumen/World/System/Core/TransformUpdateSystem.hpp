#pragma once

#include "Lumen/Event/SceneEvent.hpp"
#include "Lumen/World/System/UpdateSystem.hpp"

namespace Lumen
{

class TransformUpdateSystem : public UpdateSystem
{
public:
    TransformUpdateSystem(World &world);

    void OnCreate() final;
    void OnUpdate() final;

private:
    void SyncCamera();

private:
    void OnAddChild(const AddChildEvent &event);
    void OnRemoveChild(const RemoveChildEvent &event);
    void OnReparent(const ReparentEvent &event);
};

} // namespace Lumen