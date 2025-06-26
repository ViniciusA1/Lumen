#include "Lumen/File/DirectoryIterator.hpp"

namespace Lumen
{

DirectoryIterator::DirectoryIterator(const Path &path)
{
    try
    {
        m_Iterator = std::filesystem::directory_iterator(path);
    }
    catch (...)
    {
        m_Iterator = std::nullopt;
    }
}

DirectoryEntry DirectoryIterator::operator*() const
{
    if (!m_Iterator || *m_Iterator == std::filesystem::directory_iterator{})
        return {};

    return **m_Iterator;
}

DirectoryEntry DirectoryIterator::operator->() const
{
    if (!m_Iterator || *m_Iterator == std::filesystem::directory_iterator{})
        return {};

    return **this;
}

DirectoryIterator &DirectoryIterator::operator++()
{
    if (m_Iterator)
    {
        try
        {
            ++(*m_Iterator);
        }
        catch (...)
        {
            m_Iterator = std::nullopt;
        }

        if (*m_Iterator == std::filesystem::directory_iterator{})
            m_Iterator = std::nullopt;
    }
    return *this;
}

bool DirectoryIterator::operator==(const DirectoryIterator &other) const
{
    return (!m_Iterator && !other.m_Iterator) ||
           (m_Iterator && other.m_Iterator && *m_Iterator == *other.m_Iterator);
}

bool DirectoryIterator::operator!=(const DirectoryIterator &other) const
{
    return !(*this == other);
}

DirectoryIterator DirectoryIterator::begin() const
{
    return *this;
}

DirectoryIterator DirectoryIterator::end() const
{
    return {};
}

RecursiveDirectoryIterator::RecursiveDirectoryIterator(const Path &path)
{
    try
    {
        m_Iterator = std::filesystem::recursive_directory_iterator(path);
    }
    catch (...)
    {
        m_Iterator = std::nullopt;
    }
}

DirectoryEntry RecursiveDirectoryIterator::operator*() const
{
    if (!m_Iterator || *m_Iterator == std::filesystem::recursive_directory_iterator{})
        return {};

    return **m_Iterator;
}

DirectoryEntry RecursiveDirectoryIterator::operator->() const
{
    if (!m_Iterator || *m_Iterator == std::filesystem::recursive_directory_iterator{})
        return {};

    return **this;
}

RecursiveDirectoryIterator &RecursiveDirectoryIterator::operator++()
{
    if (m_Iterator)
    {
        try
        {
            ++(*m_Iterator);
        }
        catch (...)
        {
            m_Iterator = std::nullopt;
        }

        if (*m_Iterator == std::filesystem::recursive_directory_iterator{})
            m_Iterator = std::nullopt;
    }
    return *this;
}

bool RecursiveDirectoryIterator::operator==(const RecursiveDirectoryIterator &other) const
{
    return (!m_Iterator && !other.m_Iterator) ||
           (m_Iterator && other.m_Iterator && *m_Iterator == *other.m_Iterator);
}

bool RecursiveDirectoryIterator::operator!=(const RecursiveDirectoryIterator &other) const
{
    return !(*this == other);
}

RecursiveDirectoryIterator RecursiveDirectoryIterator::begin() const
{
    return *this;
}

RecursiveDirectoryIterator RecursiveDirectoryIterator::end() const
{
    return {};
}

} // namespace Lumen