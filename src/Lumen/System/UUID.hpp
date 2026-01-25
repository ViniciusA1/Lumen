#pragma once

#include <cstdint>

namespace Lumen
{

class UUID
{
public:
    static const UUID Null;

public:
    UUID();
    constexpr UUID(uint64_t uuid) : m_UUID(uuid) {}

    bool operator==(const UUID &other) const;
    bool operator!=(const UUID &other) const;
    bool operator<(const UUID &other) const;
    operator uint64_t() const;

private:
    uint64_t m_UUID;
};

} // namespace Lumen

namespace Lumen
{

inline constexpr UUID UUID::Null{0};

} // namespace Lumen

namespace std
{

template <typename T> struct hash;

template <> struct hash<Lumen::UUID>
{
    size_t operator()(const Lumen::UUID &uuid) const { return (uint64_t)uuid; }
};

} // namespace std