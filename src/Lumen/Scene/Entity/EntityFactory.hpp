#pragma once

#include "Lumen/Scene/Entity/EntityManager.hpp"
#include "Lumen/System/Function.hpp"


namespace Lumen
{

class EntityFactory
{
public:
    using Creator = Function<Entity(EntityManager &)>;

    static void Register(const std::string &name, const Creator &creator);

    static Entity Create(const std::string &name, EntityManager &manager);

    static void RegisterDefaultCreators();

private:
    static std::unordered_map<std::string, Creator> s_Registry;
};

} // namespace Lumen