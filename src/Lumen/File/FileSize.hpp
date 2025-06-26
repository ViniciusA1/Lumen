#pragma once

#include <cstdint>
#include <string>

namespace Lumen
{

class FileSize
{
public:
    FileSize() = default;
    FileSize(uint64_t bytes);

    [[nodiscard]] uint64_t Bytes() const;
    [[nodiscard]] std::string String() const;

private:
    uint64_t m_Bytes = 0;
    std::string m_StringRepresentation = "0 B";
};

} // namespace Lumen
