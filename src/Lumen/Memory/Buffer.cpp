#include "Lumen/Memory/Buffer.hpp"

namespace Lumen
{

Buffer::Buffer() : m_Data(nullptr), m_Size(0), m_Capacity(0)
{
}

Buffer::Buffer(std::size_t capacity) : m_Data(nullptr), m_Size(0), m_Capacity(0)
{
    if (capacity > 0)
        Allocate(capacity);
}

Buffer::Buffer(const Buffer &other)
    : m_Data(nullptr), m_Size(other.m_Size), m_Capacity(other.m_Capacity)
{
    Allocate(m_Capacity);
    std::memcpy(m_Data, other.m_Data, m_Size);
}

Buffer::Buffer(Buffer &&other) noexcept
    : m_Data(other.m_Data), m_Size(other.m_Size), m_Capacity(other.m_Capacity)
{
    other.m_Data = nullptr;
    other.m_Size = 0;
    other.m_Capacity = 0;
}

Buffer::~Buffer()
{
    Deallocate();
}

Buffer &Buffer::operator=(const Buffer &other)
{
    if (this != &other)
    {
        Deallocate();
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        Allocate(m_Capacity);
        std::memcpy(m_Data, other.m_Data, m_Size);
    }

    return *this;
}

Buffer &Buffer::operator=(Buffer &&other) noexcept
{
    if (this != &other)
    {
        Deallocate();
        m_Data = other.m_Data;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;

        other.m_Data = nullptr;
        other.m_Size = 0;
        other.m_Capacity = 0;
    }

    return *this;
}

bool Buffer::IsEmpty() const
{
    return m_Size == 0;
}

size_t Buffer::GetCapacity() const
{
    return m_Capacity;
}

const uint8_t *Buffer::GetData() const
{
    return m_Data;
}

uint8_t *Buffer::GetData()
{
    return m_Data;
}

size_t Buffer::GetSize() const
{
    return m_Size;
}

void Buffer::Clear()
{
    if (m_Data)
        std::memset(m_Data, 0, m_Size);

    m_Size = 0;
}

void Buffer::Reserve(std::size_t newCapacity)
{
    if (newCapacity <= m_Capacity)
        return;

    if (m_Capacity == 0)
        m_Capacity = newCapacity;
    else
    {
        std::size_t grow = m_Capacity + m_Capacity / 2;
        if (grow < newCapacity)
            grow = newCapacity;
        m_Capacity = grow;
    }

    auto newBlock = new uint8_t[m_Capacity];
    if (!newBlock)
        throw std::bad_alloc();

    if (m_Data)
        std::memcpy(newBlock, m_Data, m_Size);

    std::free(m_Data);
    m_Data = newBlock;
}

void Buffer::Resize(std::size_t newSize)
{
    if (newSize > m_Capacity)
        Reserve(newSize);

    m_Size = newSize;
}

void Buffer::Allocate(std::size_t capacity)
{
    m_Data = new uint8_t[capacity];
    if (!m_Data && capacity > 0)
        throw std::bad_alloc();

    m_Capacity = capacity;
}

void Buffer::Deallocate()
{
    if (m_Data)
    {
        delete[] m_Data;
        m_Data = nullptr;
    }

    m_Size = 0;
    m_Capacity = 0;
}

} // namespace Lumen