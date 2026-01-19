#pragma once

#include <cstddef>
#include <cstdint>

namespace Lumen
{

class Buffer
{
public:
    Buffer();
    explicit Buffer(std::size_t capacity);
    Buffer(const Buffer &other);
    Buffer(Buffer &&other) noexcept;
    ~Buffer();

    Buffer &operator=(const Buffer &other);
    Buffer &operator=(Buffer &&other) noexcept;

    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] size_t GetCapacity() const;
    [[nodiscard]] const uint8_t *GetData() const;
    [[nodiscard]] uint8_t *GetData();
    [[nodiscard]] size_t GetSize() const;

    void Clear();
    void Reserve(std::size_t newCapacity);
    void Resize(std::size_t newSize);

    template <typename T> void Write(const T &value, std::size_t offset = SIZE_MAX);
    template <typename T> T Read(std::size_t offset = 0) const;

private:
    void Allocate(std::size_t capacity);
    void Deallocate();

private:
    uint8_t *m_Data;
    std::size_t m_Size;
    std::size_t m_Capacity;
};

} // namespace Lumen

#include "Lumen/Memory/Buffer.inl"