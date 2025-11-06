#pragma once

#include <cstdint>

namespace Lumen
{

class UUID
{
public:
    UUID();
    UUID(uint64_t uuid);

    operator uint64_t() const { return (uint64_t)m_UUID; }

private:
    uint64_t m_UUID;
};

} // namespace Lumen

namespace std
{

template <typename T> struct hash;

template <> struct hash<Lumen::UUID>
{
    size_t operator()(const Lumen::UUID &uuid) const { return (uint64_t)uuid; }
};

} // namespace std