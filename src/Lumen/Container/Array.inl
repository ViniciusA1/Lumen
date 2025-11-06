#pragma once

#include "Lumen/Container/Array.hpp"

#include <algorithm>

namespace Lumen
{

template <typename T, size_t N>
constexpr Array<T, N>::Array(std::initializer_list<T> init)
{
    assert(init.size() <= N && "Too many elements for Array");
    size_t i = 0;
    for (const auto &v : init)
        m_Data[i++] = v;
}

template <typename T, size_t N>
constexpr const T &Array<T, N>::operator[](size_t index) const noexcept
{
    assert(index < N && "Array index out of bounds");
    return m_Data[index];
}

template <typename T, size_t N>
constexpr T &Array<T, N>::operator[](size_t index) noexcept
{
    assert(index < N && "Array index out of bounds");
    return m_Data[index];
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator==(const Array &other) const noexcept
{
    for (size_t i = 0; i < N; i++)
    {
        if (m_Data[i] != other.m_Data[i])
            return false;
    }

    return true;
}

template <typename T, size_t N>
constexpr bool Array<T, N>::operator!=(const Array &other) const noexcept
{
    return !(*this == other);
}

template <typename T, size_t N> constexpr bool Array<T, N>::IsEmpty() const noexcept
{
    return N == 0;
}

template <typename T, size_t N> constexpr T *Array<T, N>::GetData() noexcept
{
    return m_Data;
}

template <typename T, size_t N> constexpr const T *Array<T, N>::GetData() const noexcept
{
    return m_Data;
}

template <typename T, size_t N> constexpr size_t Array<T, N>::GetSize() const noexcept
{
    return N;
}

template <typename T, size_t N> constexpr T &Array<T, N>::Front() noexcept
{
    return m_Data[0];
}

template <typename T, size_t N> constexpr const T &Array<T, N>::Front() const noexcept
{
    return m_Data[0];
}

template <typename T, size_t N> constexpr T &Array<T, N>::Back() noexcept
{
    return m_Data[N - 1];
}

template <typename T, size_t N> constexpr const T &Array<T, N>::Back() const noexcept
{
    return m_Data[N - 1];
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::Iterator Array<T, N>::begin() noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::ConstIterator Array<T, N>::begin() const noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::ConstIterator Array<T, N>::cbegin() const noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::Iterator Array<T, N>::end() noexcept
{
    return m_Data + N;
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::ConstIterator Array<T, N>::end() const noexcept
{
    return m_Data + N;
}

template <typename T, size_t N>
constexpr Lumen::Array<T, N>::ConstIterator Array<T, N>::cend() const noexcept
{
    return m_Data + N;
}

template <typename T, size_t N> constexpr void Array<T, N>::Fill(const T &value)
{
    for (size_t i = 0; i < N; i++)
        m_Data[i] = value;
}

template <typename T, size_t N> constexpr void Array<T, N>::Swap(Array &other) noexcept
{
    for (size_t i = 0; i < N; i++)
        std::swap(m_Data[i], other.m_Data[i]);
}

} // namespace Lumen