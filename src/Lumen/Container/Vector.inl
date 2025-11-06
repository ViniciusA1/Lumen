#pragma once

#include "Lumen/Container/Vector.hpp"

#include <cassert>
#include <utility>

namespace Lumen
{

template <typename T> Vector<T>::Vector(size_t capacity)
{
    Reallocate(capacity);
}

template <typename T> Vector<T>::Vector(std::initializer_list<T> init)
{
    Reserve(init.size());
    for (const auto &item : init)
        EmplaceBack(item);
}

template <typename T> Vector<T>::Vector(const Vector &other)
{
    Reserve(other.m_Size);
    for (size_t i = 0; i < other.m_Size; i++)
        new (&m_Data[i]) T(other.m_Data[i]);
    m_Size = other.m_Size;
}

template <typename T>
Vector<T>::Vector(Vector &&other) noexcept
    : m_Data(other.m_Data), m_Size(other.m_Size), m_Capacity(other.m_Capacity)
{
    other.m_Data = nullptr;
    other.m_Size = other.m_Capacity = 0;
}

template <typename T> Vector<T>::~Vector()
{
    Clear();
    ::operator delete(m_Data, m_Capacity * sizeof(T));
}

template <typename T> Vector<T> &Vector<T>::operator=(const Vector &other)
{
    if (this == &other)
        return *this;

    Clear();
    Reserve(other.m_Size);
    for (size_t i = 0; i < other.m_Size; i++)
        new (&m_Data[i]) T(other.m_Data[i]);

    m_Size = other.m_Size;
    return *this;
}

template <typename T> Vector<T> &Vector<T>::operator=(Vector &&other) noexcept
{
    if (this == &other)
        return *this;

    Clear();
    ::operator delete(m_Data, m_Capacity * sizeof(T));
    m_Data = other.m_Data;
    m_Size = other.m_Size;
    m_Capacity = other.m_Capacity;
    other.m_Data = nullptr;
    other.m_Size = other.m_Capacity = 0;
    return *this;
}

template <typename T>
constexpr const T &Vector<T>::operator[](size_t index) const noexcept
{
    assert(index < m_Size && "Vector index out of bounds");
    return m_Data[index];
}

template <typename T> constexpr T &Vector<T>::operator[](size_t index) noexcept
{
    assert(index < m_Size && "Vector index out of bounds");
    return m_Data[index];
}

template <typename T>
constexpr bool Vector<T>::operator==(const Vector &other) const noexcept
{
    if (m_Size != other.m_Size)
        return false;

    for (std::size_t i = 0; i < m_Size; i++)
    {
        if (m_Data[i] != other.m_Data[i])
            return false;
    }

    return true;
}

template <typename T>
constexpr bool Vector<T>::operator!=(const Vector &other) const noexcept
{
    return !(*this == other);
}

template <typename T> constexpr bool Vector<T>::IsEmpty() const noexcept
{
    return m_Size == 0;
}

template <typename T> constexpr size_t Vector<T>::GetCapacity() const noexcept
{
    return m_Capacity;
}

template <typename T> constexpr T *Vector<T>::GetData() noexcept
{
    return m_Data;
}

template <typename T> constexpr const T *Vector<T>::GetData() const noexcept
{
    return m_Data;
}

template <typename T> constexpr size_t Vector<T>::GetSize() const noexcept
{
    return m_Size;
}

template <typename T> constexpr T &Vector<T>::Front() noexcept
{
    return m_Data[0];
}

template <typename T> constexpr const T &Vector<T>::Front() const noexcept
{
    return m_Data[0];
}

template <typename T> constexpr T &Vector<T>::Back() noexcept
{
    return m_Data[m_Size - 1];
}

template <typename T> constexpr const T &Vector<T>::Back() const noexcept
{
    return m_Data[m_Size - 1];
}

template <typename T> constexpr Lumen::Vector<T>::Iterator Vector<T>::begin() noexcept
{
    return m_Data;
}

template <typename T>
constexpr Lumen::Vector<T>::ConstIterator Vector<T>::begin() const noexcept
{
    return m_Data;
}

template <typename T>
constexpr Lumen::Vector<T>::ConstIterator Vector<T>::cbegin() const noexcept
{
    return m_Data;
}

template <typename T> constexpr Lumen::Vector<T>::Iterator Vector<T>::end() noexcept
{
    return m_Data + m_Size;
}

template <typename T>
constexpr Lumen::Vector<T>::ConstIterator Vector<T>::end() const noexcept
{
    return m_Data + m_Size;
}

template <typename T>
constexpr Lumen::Vector<T>::ConstIterator Vector<T>::cend() const noexcept
{
    return m_Data + m_Size;
}

template <typename T> void Vector<T>::Reserve(size_t newCapacity)
{
    if (newCapacity > m_Capacity)
        Reallocate(newCapacity);
}

template <typename T> void Vector<T>::Resize(size_t newSize)
{
    if (newSize > m_Capacity)
        Reallocate(newSize);

    if (newSize > m_Size)
    {
        for (size_t i = m_Size; i < newSize; i++)
            new (&m_Data[i]) T();
    }
    else
    {
        for (size_t i = newSize; i < m_Size; i++)
            m_Data[i].~T();
    }
    m_Size = newSize;
}

template <typename T> void Vector<T>::ShrinkToFit()
{
    if (m_Size < m_Capacity)
        Reallocate(m_Size);
}

template <typename T>
template <typename... Args>
T &Vector<T>::EmplaceBack(Args &&...args)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());

    new (&m_Data[m_Size]) T(std::forward<Args>(args)...);
    return m_Data[m_Size++];
}

template <typename T> void Vector<T>::PushBack(const T &value)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());

    new (&m_Data[m_Size]) T(value);
    m_Size++;
}

template <typename T> void Vector<T>::PushBack(T &&value)
{
    if (m_Size >= m_Capacity)
        Reallocate(GrowCapacity());

    new (&m_Data[m_Size]) T(std::move(value));
    m_Size++;
}

template <typename T> void Vector<T>::Clear() noexcept
{
    for (size_t i = 0; i < m_Size; i++)
        m_Data[i].~T();

    m_Size = 0;
}

template <typename T> void Vector<T>::Erase(size_t index)
{
    assert(index < m_Size && "Erase index out of bounds");
    m_Data[index].~T();
    for (size_t i = index; i < m_Size - 1; i++)
        new (&m_Data[i]) T(std::move(m_Data[i + 1]));

    m_Size--;
    m_Data[m_Size].~T();
}

template <typename T> void Vector<T>::PopBack()
{
    assert(m_Size > 0 && "Cannot PopBack an empty vector");
    m_Size--;
    m_Data[m_Size].~T();
}

template <typename T> void Vector<T>::Swap(Vector &other) noexcept
{
    std::swap(m_Data, other.m_Data);
    std::swap(m_Size, other.m_Size);
    std::swap(m_Capacity, other.m_Capacity);
}

template <typename T> constexpr size_t Vector<T>::GrowCapacity() const noexcept
{
    return m_Capacity ? m_Capacity * 2 : 2;
}

template <typename T> void Vector<T>::Reallocate(size_t newCapacity)
{
    T *newData = static_cast<T *>(::operator new(newCapacity * sizeof(T)));

    for (size_t i = 0; i < m_Size; i++)
        new (&newData[i]) T(std::move(m_Data[i]));

    for (size_t i = 0; i < m_Size; i++)
        m_Data[i].~T();

    ::operator delete(m_Data, m_Capacity * sizeof(T));
    m_Data = newData;
    m_Capacity = newCapacity;
}

} // namespace Lumen