#pragma once

#include <functional>

#define BIND_ACTION(fn) [this]() { this->fn(); }

namespace Lumen
{

class Action
{
public:
    Action() = default;
    template <typename Callable> Action(Callable &&function);

    [[nodiscard]] bool IsBound() const;

    void Clear();

    void Invoke() const;

    template <typename Callable> Action &operator=(Callable &&function);
    template <typename Callable> Action &operator+=(Callable &&function);
    template <typename Callable> Action &operator-=(const Callable &function);
    void operator()() const;

private:
    std::vector<std::function<void()>> m_Actions;
};

template <typename Callable> Action::Action(Callable &&function)
{
    m_Actions.push_back(std::forward<Callable>(function));
}

template <typename Callable> Action &Action::operator=(Callable &&function)
{
    Clear();
    m_Actions.push_back(std::forward<Callable>(function));
    return *this;
}

template <typename Callable> Action &Action::operator+=(Callable &&function)
{
    m_Actions.push_back(std::forward<Callable>(function));
    return *this;
}

template <typename Callable> Action &Action::operator-=(const Callable &function)
{
    auto it = std::find(m_Actions.begin(), m_Actions.end(), function);
    if (it != m_Actions.end())
        m_Actions.erase(it);

    return *this;
}

} // namespace Lumen