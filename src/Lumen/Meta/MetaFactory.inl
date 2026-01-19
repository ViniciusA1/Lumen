#pragma once

#include "Lumen/Meta/MetaFactory.hpp"

namespace Lumen
{

template <typename T>
MetaFactory<T>::MetaFactory(MetaContext *ctx)
    : m_Factory(ctx ? entt::meta_factory<T>{ctx->GetInternalCtx()}
                    : entt::meta_factory<T>{}),
      m_Ctx(ctx)
{
}

template <typename T> MetaType MetaFactory<T>::GetType() const
{
    return MetaType(entt::meta<T>());
}

template <typename T> MetaFactory<T> &MetaFactory<T>::Type(entt::id_type id)
{
    m_Factory.type(id);
    return *this;
}

template <typename T> MetaFactory<T> &MetaFactory<T>::Type(const std::string &name)
{
    m_Factory.type(entt::hashed_string(name.c_str()));
    return *this;
}

template <typename T>
template <typename... Args>
MetaFactory<T> &MetaFactory<T>::Constructor()
{
    m_Factory.template ctor<Args...>();
    return *this;
}

template <typename T>
template <auto DestructorFunc>
MetaFactory<T> &MetaFactory<T>::Destructor()
{
    m_Factory.template dtor<DestructorFunc>();
    return *this;
}

template <typename T>
template <auto Member, typename Policy>
MetaFactory<T> &MetaFactory<T>::Data(MetaID id)
{
    m_Factory.template data<Member, Policy>(id);
    return *this;
}

template <typename T>
template <auto Member, typename Policy>
MetaFactory<T> &MetaFactory<T>::Data(const std::string &name)
{
    m_Factory.template data<Member, Policy>(entt::hashed_string(name.c_str()));
    return *this;
}

template <typename T>
template <auto Func, typename Policy>
MetaFactory<T> &MetaFactory<T>::Function(MetaID id)
{
    m_Factory.template func<Func, Policy>(id);
    return *this;
}

template <typename T>
template <auto Func, typename Policy>
MetaFactory<T> &MetaFactory<T>::Function(const std::string &name)
{
    m_Factory.template func<Func, Policy>(entt::hashed_string(name.c_str()));
    return *this;
}

template <typename T> template <typename Base> MetaFactory<T> &MetaFactory<T>::Base()
{
    m_Factory.template base<Base>();
    return *this;
}

template <typename T> template <typename To> MetaFactory<T> &MetaFactory<T>::Conversion()
{
    m_Factory.template conv<To>();
    return *this;
}

// template <typename T>
// template <typename Traits>
// MetaFactory<T> &MetaFactory<T>::Traits(Traits traits)
// {
//     m_Factory.traits(static_cast<std::underlying_type_t<Traits>>(traits));
//     return *this;
// }

template <typename T>
template <typename DataType, typename... Args>
MetaFactory<T> &MetaFactory<T>::Custom(Args &&...args)
{
    m_Factory.template custom<DataType>(std::forward<Args>(args)...);
    return *this;
}

} // namespace Lumen