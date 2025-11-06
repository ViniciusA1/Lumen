#pragma once

#include <cmath>
#include <cstdint>
#include <limits>

namespace Lumen
{

class Limits
{
public:
    static constexpr int IntMin = std::numeric_limits<int>::lowest();
    static constexpr int IntMax = std::numeric_limits<int>::max();

    static constexpr int64_t Int64Min = std::numeric_limits<int64_t>::lowest();
    static constexpr int64_t Int64Max = std::numeric_limits<int64_t>::max();

    static constexpr uint32_t UIntMin = std::numeric_limits<uint32_t>::lowest();
    static constexpr uint32_t UIntMax = std::numeric_limits<uint32_t>::max();

    static constexpr uint64_t UInt64Min = std::numeric_limits<uint64_t>::lowest();
    static constexpr uint64_t UInt64Max = std::numeric_limits<uint64_t>::max();

    static constexpr float FloatMin = std::numeric_limits<float>::lowest();
    static constexpr float FloatMax = std::numeric_limits<float>::max();
    static constexpr float FloatEpsilon = std::numeric_limits<float>::epsilon();

    static constexpr double DoubleMin = std::numeric_limits<double>::lowest();
    static constexpr double DoubleMax = std::numeric_limits<double>::max();
    static constexpr double DoubleEpsilon = std::numeric_limits<double>::epsilon();

    static constexpr float SmallNumber = 1e-8f;
    static constexpr float BigNumber = 3.4e+38f;
    static constexpr float Infinity = std::numeric_limits<float>::infinity();

    static constexpr double SmallNumberD = 1e-12;
    static constexpr double BigNumberD = 1.7e+308;
    static constexpr double InfinityD = std::numeric_limits<double>::infinity();

    template <typename T> static constexpr T Min()
    {
        return std::numeric_limits<T>::lowest();
    }

    template <typename T> static constexpr T Max()
    {
        return std::numeric_limits<T>::max();
    }

    template <typename T> static constexpr T Epsilon()
    {
        return std::numeric_limits<T>::epsilon();
    }

    template <typename T> static constexpr bool IsFinite(T value)
    {
        return std::isfinite(value);
    }

    template <typename T> static constexpr bool IsNan(T value)
    {
        return std::isnan(value);
    }
};

} // namespace Lumen