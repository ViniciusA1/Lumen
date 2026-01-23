#pragma once

#include <string>

namespace Lumen
{

struct TagComponent
{
    std::string Name;

    TagComponent() = default;
    TagComponent(std::string name) : Name(std::move(name)) {}
};

struct UntaggedComponent : public TagComponent
{
    UntaggedComponent() : TagComponent("Untagged") {}
};

struct EnemyTagComponent : public TagComponent
{
    EnemyTagComponent() : TagComponent("Enemy") {}
};

struct MainCameraTagComponent : public TagComponent
{
    MainCameraTagComponent() : TagComponent("MainCamera") {}
};

struct PlayerTagComponent : public TagComponent
{
    PlayerTagComponent() : TagComponent("Player") {}
};

} // namespace Lumen