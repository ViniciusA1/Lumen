#pragma once

#include "Lumen/Meta/MetaType.hpp"

#include "entt/meta/factory.hpp"
#include <string>

namespace Lumen
{

template <typename T> class MetaFactory
{
public:
    MetaFactory(MetaContext *ctx = nullptr);

    [[nodiscard]] MetaType GetType() const;

    MetaFactory<T> &Type(MetaID id);
    MetaFactory<T> &Type(const std::string &name);

    template <typename... Args> MetaFactory<T> &Constructor();
    template <auto DestructorFunc> MetaFactory &Destructor();

    template <auto Member, typename Policy = entt::as_is_t>
    MetaFactory<T> &Data(MetaID id);
    template <auto Member, typename Policy = entt::as_is_t>
    MetaFactory<T> &Data(const std::string &name);
    template <auto Func, typename Policy = entt::as_is_t>
    MetaFactory<T> &Function(MetaID id);
    template <auto Func, typename Policy = entt::as_is_t>
    MetaFactory<T> &Function(const std::string &name);

    template <typename Base> MetaFactory<T> &Base();
    template <typename To> MetaFactory<T> &Conversion();
    // template <typename Traits> MetaFactory<T> &Traits(Traits traits);
    template <typename DataType, typename... Args> MetaFactory<T> &Custom(Args &&...args);

private:
    entt::meta_factory<T> m_Factory;
    MetaContext *m_Ctx;
};

} // namespace Lumen

#include "Lumen/Meta/MetaFactory.inl"