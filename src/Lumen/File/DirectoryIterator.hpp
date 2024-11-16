#pragma once

#include "Lumen/File/DirectoryEntry.hpp"
#include <optional>

namespace Lumen
{

class DirectoryIterator
{
public:
    DirectoryIterator();
    explicit DirectoryIterator(const std::string &path);

    const DirectoryEntry operator*() const;
    const DirectoryEntry operator->() const;

    DirectoryIterator &operator++();

    bool operator==(const DirectoryIterator &other) const;
    bool operator!=(const DirectoryIterator &other) const;

    DirectoryIterator begin();
    DirectoryIterator end();

private:
    std::optional<std::filesystem::directory_iterator> m_Iterator;
};

class RecursiveDirectoryIterator
{
public:
    RecursiveDirectoryIterator();
    explicit RecursiveDirectoryIterator(const std::string &path);

    const DirectoryEntry operator*() const;
    const DirectoryEntry operator->() const;

    RecursiveDirectoryIterator &operator++();

    bool operator==(const RecursiveDirectoryIterator &other) const;
    bool operator!=(const RecursiveDirectoryIterator &other) const;

    RecursiveDirectoryIterator begin();
    RecursiveDirectoryIterator end();

private:
    std::optional<std::filesystem::recursive_directory_iterator> m_Iterator;
};

} // namespace Lumen