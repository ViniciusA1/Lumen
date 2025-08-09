#pragma once

#include "Lumen/Memory/Buffer.hpp"

#include <cstring>
#include <stdexcept>
#include <type_traits>

namespace Lumen
{

template <typename T> void Buffer::Write(const T &value, std::size_t offset)
{
    static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
    offset = (offset == SIZE_MAX) ? m_Size : offset;

    std::size_t end = offset + sizeof(T);
    if (end > m_Capacity)
        Reserve(end);

    std::memcpy(m_Data + offset, &value, sizeof(T));

    if (end > m_Size)
        m_Size = end;
}

template <typename T> T Buffer::Read(std::size_t offset) const
{
    static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");

    if (offset + sizeof(T) > m_Size)
        throw std::out_of_range("Read exceeds buffer size");

    T value;
    std::memcpy(&value, m_Data + offset, sizeof(T));
    return value;
}

} // namespace Lumen