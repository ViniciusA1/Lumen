#pragma once

#include <cstddef>
#include <initializer_list>

namespace Lumen
{

template <typename T> class Vector
{
public:
    using ValueType = T;
    using Iterator = T *;
    using ConstIterator = const T *;

public:
    constexpr Vector() = default;
    explicit Vector(size_t capacity);
    Vector(std::initializer_list<T> init);
    Vector(const Vector &other);
    Vector(Vector &&other) noexcept;
    ~Vector();

    Vector &operator=(const Vector &other);
    Vector &operator=(Vector &&other) noexcept;
    constexpr T &operator[](size_t index) noexcept;
    constexpr const T &operator[](size_t index) const noexcept;
    constexpr bool operator==(const Vector &other) const noexcept;
    constexpr bool operator!=(const Vector &other) const noexcept;

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

    void Swap(Vector &other) noexcept;

private:
    [[nodiscard]] constexpr size_t GrowCapacity() const noexcept;

    void Reallocate(size_t newCapacity);

private:
    T *m_Data = nullptr;
    std::size_t m_Size = 0;
    std::size_t m_Capacity = 0;
};

} // namespace Lumen

#include "Lumen/Container/Vector.inl"