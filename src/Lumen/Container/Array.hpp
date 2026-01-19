#pragma once

#include <cstddef>
#include <initializer_list>

namespace Lumen
{

template <typename T, size_t N> class Array
{
public:
    using ValueType = T;
    using Iterator = T *;
    using ConstIterator = const T *;

public:
    constexpr Array() noexcept = default;
    constexpr Array(std::initializer_list<T> init);
    constexpr Array(const Array &) = default;
    constexpr Array(Array &&) noexcept = default;
    ~Array() = default;

    constexpr Array &operator=(const Array &) = default;
    constexpr Array &operator=(Array &&) noexcept = default;
    constexpr T &operator[](size_t index) noexcept;
    constexpr const T &operator[](size_t index) const noexcept;
    constexpr bool operator==(const Array &other) const noexcept;
    constexpr bool operator!=(const Array &other) const noexcept;

    [[nodiscard]] constexpr bool IsEmpty() const noexcept;

    constexpr T *GetData() noexcept;
    constexpr const T *GetData() const noexcept;
    [[nodiscard]] constexpr size_t GetSize() const noexcept;

    constexpr T &Front() noexcept;
    constexpr const T &Front() const noexcept;

    constexpr T &Back() noexcept;
    constexpr const T &Back() const noexcept;

    constexpr Iterator begin() noexcept;
    constexpr ConstIterator begin() const noexcept;
    constexpr ConstIterator cbegin() const noexcept;

    constexpr Iterator end() noexcept;
    constexpr ConstIterator end() const noexcept;
    constexpr ConstIterator cend() const noexcept;

    constexpr void Fill(const T &value);
    constexpr void Swap(Array &other) noexcept;

private:
    T m_Data[N > 0 ? N : 1];
};

} // namespace Lumen

#include "Lumen/Container/Array.inl"