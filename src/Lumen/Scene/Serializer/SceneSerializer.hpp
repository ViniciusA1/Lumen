#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class SceneSerializer
{
public:
    SceneSerializer(const Ref<Scene> &scene);

    bool Deserialize(const Path &path);
    bool Serialize(const Path &path);

private:
    Ref<Scene> m_Scene;
};

} // namespace Lumen