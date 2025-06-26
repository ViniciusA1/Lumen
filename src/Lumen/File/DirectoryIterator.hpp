#pragma once

#include "Lumen/File/DirectoryEntry.hpp"

#include <optional>

namespace Lumen
{

class DirectoryIterator
{
public:
    DirectoryIterator() = default;
    explicit DirectoryIterator(const Path &path);

    DirectoryEntry operator*() const;
    DirectoryEntry operator->() const;

    DirectoryIterator &operator++();

    bool operator==(const DirectoryIterator &other) const;
    bool operator!=(const DirectoryIterator &other) const;

    [[nodiscard]] DirectoryIterator begin() const;
    [[nodiscard]] DirectoryIterator end() const;

private:
    std::optional<std::filesystem::directory_iterator> m_Iterator;
};

class RecursiveDirectoryIterator
{
public:
    RecursiveDirectoryIterator() = default;
    explicit RecursiveDirectoryIterator(const Path &path);

    DirectoryEntry operator*() const;
    DirectoryEntry operator->() const;

    RecursiveDirectoryIterator &operator++();

    bool operator==(const RecursiveDirectoryIterator &other) const;
    bool operator!=(const RecursiveDirectoryIterator &other) const;

    [[nodiscard]] RecursiveDirectoryIterator begin() const;
    [[nodiscard]] RecursiveDirectoryIterator end() const;

private:
    std::optional<std::filesystem::recursive_directory_iterator> m_Iterator;
};

} // namespace Lumen