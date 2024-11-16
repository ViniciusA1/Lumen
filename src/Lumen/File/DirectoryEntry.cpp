#include "Lumen/File/DirectoryEntry.hpp"

namespace Lumen
{

DirectoryEntry::DirectoryEntry(std::filesystem::directory_entry entry)
    : m_Entry(std::move(entry))
{
}

void DirectoryEntry::ReplaceFilename(const std::string &filename)
{
    m_Entry.replace_filename(filename);
}

void DirectoryEntry::Refresh()
{
    m_Entry.refresh();
}

Path DirectoryEntry::GetPath() const
{
    return {m_Entry.path()};
}

bool DirectoryEntry::Exists() const
{
    return m_Entry.exists();
}

bool DirectoryEntry::IsDirectory() const
{
    return m_Entry.is_directory();
}

bool DirectoryEntry::IsFile() const
{
    return m_Entry.is_regular_file();
}

std::uintmax_t DirectoryEntry::FileSize() const
{
    return m_Entry.file_size();
}

bool DirectoryEntry::operator==(const DirectoryEntry &other) const
{
    return m_Entry == other.m_Entry;
}

bool DirectoryEntry::operator!=(const DirectoryEntry &other) const
{
    return m_Entry != other.m_Entry;
}

} // namespace Lumen