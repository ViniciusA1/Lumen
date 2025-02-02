#pragma once

#include "Lumen/Scene/Scene.hpp"

namespace Lumen
{

class SceneFactory
{
public:
    static Ref<Scene> CreateScene(SceneType type);
    static Ref<Scene> CreateScene(SceneType type, UUID uuid, const Path &path,
                                  const std::string &name);
};

} // namespace Lumen