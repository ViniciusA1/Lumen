#include "Lumen/World/Component/ComponentRegistry.hpp"
#include "Lumen/Meta/MetaRegistry.hpp"

namespace Lumen
{

ComponentRegistry::RegistryMap ComponentRegistry::s_Registry;

std::vector<MetaID> ComponentRegistry::GetComponents(const std::string &group)
{
    auto it = s_Registry.find(group);
    if (it == s_Registry.end())
        return {};

    return it->second;
}

void ComponentRegistry::ForEachComponent(const std::string &group,
                                         const Function<void(MetaType)> &callback)
{
    auto components = GetComponents(group);

    for (const auto &component : components)
    {
        auto componentType = MetaRegistry::Resolve(component);
        callback(componentType);
    }
}

void ComponentRegistry::ForEachGroup(const Function<void(const std::string &)> &callback)
{
    for (const auto &[group, _] : s_Registry)
        callback(group);
}

} // namespace Lumen