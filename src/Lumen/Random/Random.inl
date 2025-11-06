#pragma once

#include "Lumen/Random/Random.hpp"

namespace Lumen
{

template <typename T> T Random::Choice(const std::span<std::pair<T, double>> &items)
{
    if (items.empty())
        return {};

    double totalWeight = 0.0;
    for (const auto &p : items)
        totalWeight += p.second;
    if (totalWeight <= 0.0)
        return items.front().first;

    std::uniform_real_distribution<double> dist(0.0, totalWeight);
    double pick = dist(m_Engine);

    double cumulative = 0.0;
    for (const auto &p : items)
    {
        cumulative += p.second;
        if (pick <= cumulative)
            return p.first;
    }

    return items.back().first;
}

template <typename T> T Random::Choice(const std::span<T> &items)
{
    if (items.empty())
        return {};

    std::uniform_int_distribution<size_t> dist(0, items.size() - 1);
    return items[dist(m_Engine)];
}

template <typename T> void Random::Shuffle(const std::span<T> &items)
{
    if (items.empty())
        return;

    for (size_t i = items.size() - 1; i > 0; --i)
    {
        std::uniform_int_distribution<size_t> dist(0, i);
        std::swap(items[i], items[dist(m_Engine)]);
    }
}

} // namespace Lumen