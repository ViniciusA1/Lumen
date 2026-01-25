#include "Lumen/System/UUID.hpp"

#include <chrono>
#include <random>

namespace Lumen
{

static uint64_t GetTimestampMs()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

UUID::UUID()
{
    static std::mt19937_64 rng([] {
        std::random_device rd;
        std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        return std::mt19937_64(seed);
    }());

    static std::uniform_int_distribution<uint32_t> randomDist(0, (1u << 22) - 1);

    const uint64_t timestamp = GetTimestampMs() & ((1ULL << 42) - 1);
    const uint64_t random = randomDist(rng);

    m_UUID = (timestamp << 22) | random;
}

bool UUID::operator==(const UUID &other) const
{
    return m_UUID == other.m_UUID;
}

bool UUID::operator!=(const UUID &other) const
{
    return m_UUID != other.m_UUID;
}

bool UUID::operator<(const UUID &other) const
{
    return m_UUID < other.m_UUID;
}

UUID::operator uint64_t() const
{
    return m_UUID;
}

} // namespace Lumen