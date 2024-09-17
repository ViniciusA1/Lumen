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