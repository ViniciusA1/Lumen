#pragma once

#include <type_traits>

namespace Lumen::Enum
{

template <typename E> constexpr auto ToUnderlying(E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

template <typename E>
constexpr int ToInt(E e)
    requires std::is_enum_v<E>
{
    return static_cast<int>(ToUnderlying(e));
}

template <typename E>
constexpr E FromInt(int value)
    requires(std::is_enum_v<E>)
{
    return static_cast<E>(value);
}

#define ENUM_ENABLE_BITMASK(EnumType)                                                    \
    constexpr EnumType operator|(EnumType lhs, EnumType rhs)                             \
    {                                                                                    \
        return static_cast<EnumType>(Lumen::Enum::ToUnderlying(lhs) |                    \
                                     Lumen::Enum::ToUnderlying(rhs));                    \
    }                                                                                    \
    constexpr EnumType operator&(EnumType lhs, EnumType rhs)                             \
    {                                                                                    \
        return static_cast<EnumType>(Lumen::Enum::ToUnderlying(lhs) &                    \
                                     Lumen::Enum::ToUnderlying(rhs));                    \
    }                                                                                    \
    constexpr EnumType operator^(EnumType lhs, EnumType rhs)                             \
    {                                                                                    \
        return static_cast<EnumType>(Lumen::Enum::ToUnderlying(lhs) ^                    \
                                     Lumen::Enum::ToUnderlying(rhs));                    \
    }                                                                                    \
    constexpr EnumType operator~(EnumType e)                                             \
    {                                                                                    \
        return static_cast<EnumType>(~Lumen::Enum::ToUnderlying(e));                     \
    }                                                                                    \
    constexpr EnumType &operator|=(EnumType &lhs, EnumType rhs)                          \
    {                                                                                    \
        lhs = lhs | rhs;                                                                 \
        return lhs;                                                                      \
    }                                                                                    \
    constexpr EnumType &operator&=(EnumType &lhs, EnumType rhs)                          \
    {                                                                                    \
        lhs = lhs & rhs;                                                                 \
        return lhs;                                                                      \
    }                                                                                    \
    constexpr EnumType &operator^=(EnumType &lhs, EnumType rhs)                          \
    {                                                                                    \
        lhs = lhs ^ rhs;                                                                 \
        return lhs;                                                                      \
    }

} // namespace Lumen::Enum