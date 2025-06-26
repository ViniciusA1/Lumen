#include "Lumen/File/FileSize.hpp"

#include <array>
#include <cstdio>

namespace Lumen
{

static std::string HumanReadableSize(uint64_t sizeInBytes)
{
    const std::array<std::string, 5> suffixes = {"B", "KB", "MB", "GB", "TB"};
    size_t suffixIndex = 0;
    auto size = static_cast<double>(sizeInBytes);

    while (size >= 1024 && suffixIndex < suffixes.size() - 1)
    {
        size /= 1024.0;
        ++suffixIndex;
    }

    std::array<char, 32> buffer;
    snprintf(buffer.data(), buffer.size(), "%.2f %s", size,
             suffixes[suffixIndex].c_str());
    return buffer.data();
}

FileSize::FileSize(uint64_t bytes)
    : m_Bytes(bytes), m_StringRepresentation(HumanReadableSize(bytes))
{
}

uint64_t FileSize::Bytes() const
{
    return m_Bytes;
}

std::string FileSize::String() const
{
    return m_StringRepresentation;
}

} // namespace Lumen