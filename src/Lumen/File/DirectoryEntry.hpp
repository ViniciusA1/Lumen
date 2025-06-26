#pragma once

#include "Lumen/File/Path.hpp"

namespace Lumen
{

class DirectoryEntry
{
public:
    DirectoryEntry(std::filesystem::directory_entry entry = {});

    void ReplaceFilename(const std::string &filename);
    void Refresh();

    [[nodiscard]] Path GetPath() const;
    [[nodiscard]] bool Exists() const;
    [[nodiscard]] bool IsDirectory() const;
    [[nodiscard]] bool IsFile() const;
    [[nodiscard]] std::uintmax_t FileSize() const;

    bool operator==(const DirectoryEntry &other) const;
    bool operator!=(const DirectoryEntry &other) const;

private:
    std::filesystem::directory_entry m_Entry;
};

} // namespace Lumen