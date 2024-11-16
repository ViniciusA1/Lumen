#include "Lumen/File/Path.hpp"

namespace Lumen
{

Path::Path() : m_Path(".")
{
}

Path::Path(std::filesystem::path path) : m_Path(std::move(path))
{
}

void Path::Clear()
{
    m_Path.clear();
}

void Path::RemoveFilename()
{
    m_Path.remove_filename();
}

void Path::ReplaceFilename(const Path &filename)
{
    m_Path.replace_filename(filename);
}

void Path::ReplaceExtension(const std::string &extension)
{
    m_Path.replace_extension(extension);
}

void Path::Swap(Path &other)
{
    m_Path.swap(other.m_Path);
}

Path Path::GetRootName() const
{
    return {m_Path.root_name()};
}

Path Path::GetRootDirectory() const
{
    return {m_Path.root_directory()};
}

Path Path::GetRootPath() const
{
    return {m_Path.root_path()};
}

Path Path::GetRelativePath() const
{
    return {m_Path.relative_path()};
}

Path Path::GetParentPath() const
{
    return {m_Path.parent_path()};
}

Path Path::GetFilename() const
{
    return {m_Path.filename()};
}

Path Path::GetStem() const
{
    return {m_Path.stem()};
}

Path Path::GetExtension() const
{
    return {m_Path.extension()};
}

std::string Path::ToString() const
{
    return m_Path.string();
}

bool Path::IsEmpty() const
{
    return m_Path.empty();
}

bool Path::HasRootPath() const
{
    return m_Path.has_root_path();
}

bool Path::HasRootName() const
{
    return m_Path.has_root_name();
}

bool Path::HasRootDirectory() const
{
    return m_Path.has_root_directory();
}

bool Path::HasRelativePath() const
{
    return m_Path.has_relative_path();
}

bool Path::HasParentPath() const
{
    return m_Path.has_parent_path();
}

bool Path::HasFilename() const
{
    return m_Path.has_filename();
}

bool Path::HasStem() const
{
    return m_Path.has_stem();
}

bool Path::HasExtension() const
{
    return m_Path.has_extension();
}

bool Path::IsAbsolute() const
{
    return m_Path.is_absolute();
}

bool Path::IsRelative() const
{
    return m_Path.is_relative();
}

Path::operator std::filesystem::path() const
{
    return m_Path;
}

Path &Path::operator=(const std::string &path)
{
    m_Path = path;
    return *this;
}

Path &Path::operator=(const std::filesystem::path &path)
{
    m_Path = path;
    return *this;
}

bool Path::operator==(const Path &other) const
{
    return m_Path == other.m_Path;
}

bool Path::operator!=(const Path &other) const
{
    return m_Path != other.m_Path;
}

Path Path::operator/(const std::string &other) const
{
    return {m_Path / other};
}

Path Path::operator/(const Path &other) const
{
    return {m_Path / other.m_Path};
}

Path &Path::operator/=(const std::string &other)
{
    m_Path /= other;
    return *this;
}

Path &Path::operator/=(const Path &other)
{
    m_Path /= other.m_Path;
    return *this;
}

Path &Path::operator+=(const std::string &str)
{
    m_Path += str;
    return *this;
}

} // namespace Lumen