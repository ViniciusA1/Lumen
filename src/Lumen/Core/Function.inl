#pragma once

#include "Lumen/Core/Function.hpp"

namespace Lumen
{

template <typename... Args>
template <typename Callable>
Function<void(Args...)>::Function(Callable &&function)
{
    m_Functions.emplace_back(std::forward<Callable>(function));
}

template <typename... Args> bool Function<void(Args...)>::IsBound() const
{
    return !m_Functions.empty();
}

template <typename... Args> void Function<void(Args...)>::Clear()
{
    m_Functions.clear();
}

template <typename... Args> void Function<void(Args...)>::Invoke(Args... args) const
{
    for (const auto &func : m_Functions)
    {
        func(std::forward<Args>(args)...);
    }
}

template <typename... Args> void Function<void(Args...)>::operator()(Args... args) const
{
    Invoke(std::forward<Args>(args)...);
}

template <typename... Args>
template <typename Callable>
Function<void(Args...)> &Function<void(Args...)>::operator=(Callable &&function)
{
    Clear();
    m_Functions.emplace_back(std::forward<Callable>(function));
    return *this;
}

template <typename... Args>
template <typename Callable>
Function<void(Args...)> &Function<void(Args...)>::operator+=(Callable &&function)
{
    m_Functions.emplace_back(std::forward<Callable>(function));
    return *this;
}

template <typename Ret, typename... Args>
template <typename Callable>
Function<Ret(Args...)>::Function(Callable &&function)
{
    m_Functions.emplace_back(std::forward<Callable>(function));
}

template <typename Ret, typename... Args> bool Function<Ret(Args...)>::IsBound() const
{
    return !m_Functions.empty();
}

template <typename Ret, typename... Args> void Function<Ret(Args...)>::Clear()
{
    m_Functions.clear();
}

template <typename Ret, typename... Args>
std::vector<Ret> Function<Ret(Args...)>::Invoke(Args... args) const
{
    std::vector<Ret> results;
    for (const auto &func : m_Functions)
    {
        results.emplace_back(func(args...));
    }
    return results;
}

template <typename Ret, typename... Args>
std::vector<Ret> Function<Ret(Args...)>::operator()(Args... args) const
{
    return Invoke(args...);
}

template <typename Ret, typename... Args>
template <typename Callable>
Function<Ret(Args...)> &Function<Ret(Args...)>::operator=(Callable &&function)
{
    Clear();
    m_Functions.emplace_back(std::forward<Callable>(function));
    return *this;
}

template <typename Ret, typename... Args>
template <typename Callable>
Function<Ret(Args...)> &Function<Ret(Args...)>::operator+=(Callable &&function)
{
    m_Functions.emplace_back(std::forward<Callable>(function));
    return *this;
}

} // namespace Lumen