#pragma once

#include "Lumen/Core/Memory.hpp"
#include "Lumen/File/Path.hpp"
#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class SceneSerializer
{
public:
    SceneSerializer() = default;

    bool Deserialize(Ref<Scene> &scene, const Path &path);
    bool Serialize(const Ref<Scene> &scene, const Path &path);
};

} // namespace Lumen