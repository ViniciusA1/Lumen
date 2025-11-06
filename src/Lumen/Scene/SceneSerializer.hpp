#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Memory/Memory.hpp"
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