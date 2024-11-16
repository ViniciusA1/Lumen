#include "Lumen/File/DirectoryIterator.hpp"

namespace Lumen
{

DirectoryIterator::DirectoryIterator() : m_Iterator(std::nullopt)
{
}

DirectoryIterator::DirectoryIterator(const std::string &path)
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

const DirectoryEntry DirectoryIterator::operator*() const
{
    return DirectoryEntry(**m_Iterator);
}

const DirectoryEntry DirectoryIterator::operator->() const
{
    return DirectoryEntry(**m_Iterator);
}

DirectoryIterator &DirectoryIterator::operator++()
{
    if (m_Iterator && *m_Iterator != std::filesystem::end(*m_Iterator))
    {
        try
        {
            ++(*m_Iterator);
        }
        catch (...)
        {
            m_Iterator = std::nullopt;
        }
    }
    return *this;
}

bool DirectoryIterator::operator==(const DirectoryIterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool DirectoryIterator::operator!=(const DirectoryIterator &other) const
{
    return !(*this == other);
}

DirectoryIterator DirectoryIterator::begin()
{
    return *this;
}

DirectoryIterator DirectoryIterator::end()
{
    return {};
}

RecursiveDirectoryIterator::RecursiveDirectoryIterator() : m_Iterator(std::nullopt)
{
}

RecursiveDirectoryIterator::RecursiveDirectoryIterator(const std::string &path)
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

const DirectoryEntry RecursiveDirectoryIterator::operator*() const
{
    return DirectoryEntry(**m_Iterator);
}

const DirectoryEntry RecursiveDirectoryIterator::operator->() const
{
    return DirectoryEntry(**m_Iterator);
}

RecursiveDirectoryIterator &RecursiveDirectoryIterator::operator++()
{
    if (m_Iterator && *m_Iterator != std::filesystem::end(*m_Iterator))
    {
        try
        {
            ++(*m_Iterator);
        }
        catch (...)
        {
            m_Iterator = std::nullopt;
        }
    }
    return *this;
}

bool RecursiveDirectoryIterator::operator==(const RecursiveDirectoryIterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool RecursiveDirectoryIterator::operator!=(const RecursiveDirectoryIterator &other) const
{
    return m_Iterator != other.m_Iterator;
}

RecursiveDirectoryIterator RecursiveDirectoryIterator::begin()
{
    return *this;
}

RecursiveDirectoryIterator RecursiveDirectoryIterator::end()
{
    return {};
}

} // namespace Lumen