#pragma once

#include <cstddef>
#include <initializer_list>

namespace Lumen
{

template <typename T, size_t N> class FixedVector
{
public:
    using ValueType = T;
    using Iterator = T *;
    using ConstIterator = const T *;

public:
    constexpr FixedVector() noexcept;
    FixedVector(std::initializer_list<T> init);
    FixedVector(const FixedVector &other);
    FixedVector(FixedVector &&other) noexcept;
    ~FixedVector();

    FixedVector &operator=(const FixedVector &other);
    FixedVector &operator=(FixedVector &&other) noexcept;

    constexpr T &operator[](size_t index) noexcept;
    constexpr const T &operator[](size_t index) const noexcept;
    constexpr bool operator==(const FixedVector &other) const noexcept;
    constexpr bool operator!=(const FixedVector &other) const noexcept;

    [[nodiscard]] constexpr bool IsEmpty() const noexcept;

    [[nodiscard]] constexpr size_t GetCapacity() const noexcept;
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

    void Reserve(size_t newCapacity);
    void Resize(size_t newSize);
    void ShrinkToFit();

    template <typename... Args> T &EmplaceBack(Args &&...args);
    void PushBack(const T &value);
    void PushBack(T &&value);

    void Clear() noexcept;
    void Erase(size_t index);
    void PopBack();

    void Swap(FixedVector &other) noexcept;

private:
    [[nodiscard]] constexpr size_t GrowCapacity() const noexcept;
    void Reallocate(size_t newCapacity);
    void MoveFrom(FixedVector &&other) noexcept;

private:
    alignas(T) unsigned char m_InlineStorage[sizeof(T) * N];
    T *m_Data = nullptr;
    std::size_t m_Size = 0;
    std::size_t m_Capacity = N;
    bool m_UsingInline = true;
};

} // namespace Lumen

#include "Lumen/Container/FixedVector.inl"
