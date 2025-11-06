#pragma once

#include "Lumen/Container/FixedVector.hpp"

#include <algorithm>
#include <cassert>

namespace Lumen
{

template <typename T, size_t N> constexpr FixedVector<T, N>::FixedVector() noexcept
{
    m_Data = reinterpret_cast<T *>(m_InlineStorage);
}

template <typename T, size_t N>
FixedVector<T, N>::FixedVector(std::initializer_list<T> init)
{
    m_Data = reinterpret_cast<T *>(m_InlineStorage);
    for (const auto &item : init)
        PushBack(item);
}

template <typename T, size_t N> FixedVector<T, N>::FixedVector(const FixedVector &other)
{
    m_Data = reinterpret_cast<T *>(m_InlineStorage);
    Reserve(other.m_Size);
    for (size_t i = 0; i < other.m_Size; ++i)
        new (&m_Data[i]) T(other.m_Data[i]);
    m_Size = other.m_Size;
}

template <typename T, size_t N>
FixedVector<T, N>::FixedVector(FixedVector &&other) noexcept
{
    m_Data = reinterpret_cast<T *>(m_InlineStorage);
    MoveFrom(std::move(other));
}

template <typename T, size_t N> FixedVector<T, N>::~FixedVector()
{
    Clear();
    if (!m_UsingInline)
        operator delete[](m_Data);
}

template <typename T, size_t N>
FixedVector<T, N> &FixedVector<T, N>::operator=(const FixedVector &other)
{
    if (this != &other)
    {
        Clear();
        Reserve(other.m_Size);
        for (size_t i = 0; i < other.m_Size; ++i)
            new (&m_Data[i]) T(other.m_Data[i]);
        m_Size = other.m_Size;
    }
    return *this;
}

template <typename T, size_t N>
FixedVector<T, N> &FixedVector<T, N>::operator=(FixedVector &&other) noexcept
{
    if (this != &other)
    {
        Clear();
        if (!m_UsingInline)
            operator delete[](m_Data);
        MoveFrom(std::move(other));
    }
    return *this;
}

template <typename T, size_t N>
constexpr T &FixedVector<T, N>::operator[](size_t index) noexcept
{
    assert(index < m_Size && "FixedVector index out of range");
    return m_Data[index];
}

template <typename T, size_t N>
constexpr const T &FixedVector<T, N>::operator[](size_t index) const noexcept
{
    assert(index < m_Size && "FixedVector index out of range");
    return m_Data[index];
}

template <typename T, size_t N>
constexpr bool FixedVector<T, N>::operator==(const FixedVector &other) const noexcept
{
    if (m_Size != other.m_Size)
        return false;
    for (size_t i = 0; i < m_Size; ++i)
        if (!(m_Data[i] == other.m_Data[i]))
            return false;
    return true;
}

template <typename T, size_t N>
constexpr bool FixedVector<T, N>::operator!=(const FixedVector &other) const noexcept
{
    return !(*this == other);
}

template <typename T, size_t N> constexpr bool FixedVector<T, N>::IsEmpty() const noexcept
{
    return m_Size == 0;
}

template <typename T, size_t N>
constexpr size_t FixedVector<T, N>::GetCapacity() const noexcept
{
    return m_Capacity;
}

template <typename T, size_t N> constexpr T *FixedVector<T, N>::GetData() noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr const T *FixedVector<T, N>::GetData() const noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr size_t FixedVector<T, N>::GetSize() const noexcept
{
    return m_Size;
}

template <typename T, size_t N> constexpr T &FixedVector<T, N>::Front() noexcept
{
    assert(m_Size > 0);
    return m_Data[0];
}

template <typename T, size_t N>
constexpr const T &FixedVector<T, N>::Front() const noexcept
{
    assert(m_Size > 0);
    return m_Data[0];
}

template <typename T, size_t N> constexpr T &FixedVector<T, N>::Back() noexcept
{
    assert(m_Size > 0);
    return m_Data[m_Size - 1];
}

template <typename T, size_t N>
constexpr const T &FixedVector<T, N>::Back() const noexcept
{
    assert(m_Size > 0);
    return m_Data[m_Size - 1];
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::Iterator FixedVector<T, N>::begin() noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::ConstIterator FixedVector<T, N>::begin()
    const noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::ConstIterator FixedVector<T, N>::cbegin()
    const noexcept
{
    return m_Data;
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::Iterator FixedVector<T, N>::end() noexcept
{
    return m_Data + m_Size;
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::ConstIterator FixedVector<T, N>::end()
    const noexcept
{
    return m_Data + m_Size;
}

template <typename T, size_t N>
constexpr typename FixedVector<T, N>::ConstIterator FixedVector<T, N>::cend()
    const noexcept
{
    return m_Data + m_Size;
}

template <typename T, size_t N> void FixedVector<T, N>::Reserve(size_t newCapacity)
{
    if (newCapacity <= m_Capacity)
        return;
    Reallocate(newCapacity);
}

template <typename T, size_t N> void FixedVector<T, N>::Resize(size_t newSize)
{
    if (newSize > m_Capacity)
        Reallocate(newSize);

    if (newSize > m_Size)
    {
        for (size_t i = m_Size; i < newSize; ++i)
            new (&m_Data[i]) T();
    }
    else
    {
        for (size_t i = newSize; i < m_Size; ++i)
            m_Data[i].~T();
    }

    m_Size = newSize;
}

template <typename T, size_t N> void FixedVector<T, N>::ShrinkToFit()
{
    if (!m_UsingInline && m_Size <= N)
    {
        T *inlineData = reinterpret_cast<T *>(m_InlineStorage);
        for (size_t i = 0; i < m_Size; ++i)
            new (&inlineData[i]) T(std::move(m_Data[i]));
        for (size_t i = 0; i < m_Size; ++i)
            m_Data[i].~T();
        operator delete[](m_Data);
        m_Data = inlineData;
        m_Capacity = N;
        m_UsingInline = true;
    }
}

template <typename T, size_t N>
template <typename... Args>
T &FixedVector<T, N>::EmplaceBack(Args &&...args)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());
    new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
    return m_Data[m_Size++];
}

template <typename T, size_t N> void FixedVector<T, N>::PushBack(const T &value)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());
    new (&m_Data[m_Size++]) T(value);
}

template <typename T, size_t N> void FixedVector<T, N>::PushBack(T &&value)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());
    new (&m_Data[m_Size++]) T(std::move(value));
}

template <typename T, size_t N> void FixedVector<T, N>::Clear() noexcept
{
    for (size_t i = 0; i < m_Size; ++i)
        m_Data[i].~T();
    m_Size = 0;
}

template <typename T, size_t N> void FixedVector<T, N>::Erase(size_t index)
{
    assert(index < m_Size);
    m_Data[index].~T();
    for (size_t i = index; i < m_Size - 1; ++i)
        new (&m_Data[i]) T(std::move(m_Data[i + 1]));
    --m_Size;
}

template <typename T, size_t N> void FixedVector<T, N>::PopBack()
{
    assert(m_Size > 0);
    m_Data[--m_Size].~T();
}

template <typename T, size_t N> void FixedVector<T, N>::Swap(FixedVector &other) noexcept
{
    FixedVector temp = std::move(other);
    other = std::move(*this);
    *this = std::move(temp);
}

template <typename T, size_t N>
constexpr size_t FixedVector<T, N>::GrowCapacity() const noexcept
{
    return (m_Capacity > 0) ? (m_Capacity * 2) : N;
}

template <typename T, size_t N> void FixedVector<T, N>::Reallocate(size_t newCapacity)
{
    T *newData = static_cast<T *>(operator new[](sizeof(T) * newCapacity));

    for (size_t i = 0; i < m_Size; ++i)
        new (&newData[i]) T(std::move(m_Data[i]));

    for (size_t i = 0; i < m_Size; ++i)
        m_Data[i].~T();

    if (!m_UsingInline)
        operator delete[](m_Data);

    m_Data = newData;
    m_Capacity = newCapacity;
    m_UsingInline = false;
}

template <typename T, size_t N>
void FixedVector<T, N>::MoveFrom(FixedVector &&other) noexcept
{
    if (other.m_UsingInline)
    {
        for (size_t i = 0; i < other.m_Size; ++i)
            new (&m_Data[i]) T(std::move(other.m_Data[i]));
        m_Size = other.m_Size;
    }
    else
    {
        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_UsingInline = false;

        other.m_Data = reinterpret_cast<T *>(other.m_InlineStorage);
        other.m_Size = 0;
        other.m_Capacity = N;
        other.m_UsingInline = true;
    }
}

} // namespace Lumen
