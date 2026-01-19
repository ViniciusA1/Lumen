#pragma once

#include "Lumen/Meta/MetaFactory.hpp"
#include "Lumen/Meta/MetaType.hpp"
#include "Lumen/System/Function.hpp"


#include <string>
#include <unordered_map>

namespace Lumen
{

class ComponentRegistry
{
public:
    ComponentRegistry() = delete;

    using RegistryMap = std::unordered_map<std::string, std::vector<MetaID>>;

public:
    static std::vector<MetaID> GetComponents(const std::string &group);

    template <typename T>
    static MetaFactory<T> Register(const std::string &name, const std::string &group);

    static void ForEachComponent(const std::string &group,
                                 const Function<void(MetaType)> &callback);
    static void ForEachGroup(const Function<void(const std::string &)> &callback);

private:
    static RegistryMap s_Registry;
};

} // namespace Lumen

#include "Lumen/Scene/Component/ComponentRegistry.inl"