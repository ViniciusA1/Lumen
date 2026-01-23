#pragma once

#include "Lumen/Meta/MetaFactory.hpp"
#include "Lumen/Meta/MetaRegistry.hpp"
#include "Lumen/World/Component/ComponentRegistry.hpp"

namespace Lumen
{

template <typename T>
MetaFactory<T> ComponentRegistry::Register(const std::string &name,
                                           const std::string &group)
{
    auto factory =
        MetaFactory<T>().Type(entt::hashed_string{name.c_str()}).template Constructor<>();

    if (!s_Registry.contains(group))
        s_Registry[group] = {};

    auto type = MetaRegistry::Resolve<T>();
    s_Registry[group].push_back(type.GetId());
    return factory;
}

} // namespace Lumen