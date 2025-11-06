#pragma once

#include "Lumen/Meta/MetaAny.hpp"

namespace Lumen
{

template <typename T>
MetaAny::MetaAny(T &&value) : m_Any(entt::meta_any{std::forward<T>(value)})
{
}

template <typename T> bool MetaAny::AllowCast()
{
    return m_Any.allow_cast<T>();
}

template <typename T> T MetaAny::Cast() const
{
    return m_Any.cast<T>();
}

template <typename T> T *MetaAny::TryCast()
{
    return m_Any.try_cast<T>();
}

} // namespace Lumen