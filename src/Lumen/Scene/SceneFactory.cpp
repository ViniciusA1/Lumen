#include "Lumen/Scene/SceneFactory.hpp"
#include "Lumen/Scene/Scene2D.hpp"
#include "Lumen/Scene/Scene3D.hpp"

namespace Lumen
{

Ref<Scene> SceneFactory::CreateScene(SceneType type)
{
    switch (type)
    {
    case SceneType::Type2D:
        return CreateRef<Scene2D>();
    case SceneType::Type3D:
        return CreateRef<Scene3D>();
    }

    return nullptr;
}

Ref<Scene> SceneFactory::CreateScene(SceneType type, UUID uuid, const Path &path,
                                     const std::string &name)
{
    switch (type)
    {
    case SceneType::Type2D:
        return CreateRef<Scene2D>(uuid, name, path);
    case SceneType::Type3D:
        return CreateRef<Scene3D>(uuid, name, path);
    }

    return nullptr;
}

} // namespace Lumen