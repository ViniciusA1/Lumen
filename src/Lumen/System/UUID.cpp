#include "Lumen/System/UUID.hpp"
#include <random>

namespace Lumen
{

static std::random_device s_RandomDevice;
static std::mt19937_64 s_Generator(s_RandomDevice());
static std::uniform_int_distribution<uint64_t> s_Distribution;

UUID::UUID()
{
    m_UUID = s_Distribution(s_Generator);
    m_UUID = (m_UUID & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;
    m_UUID = (m_UUID & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;
}

UUID::UUID(uint64_t uuid) : m_UUID(uuid)
{
}

} // namespace Lumen