#include "Lumen/File/FileSystem.hpp"
#include <filesystem>

namespace Lumen
{

Path FileSystem::Absolute(const Path &path)
{
    return {std::filesystem::absolute(path)};
}

Path FileSystem::Canonical(const Path &path)
{
    return {std::filesystem::canonical(path)};
}

Path FileSystem::Relative(const Path &path, const Path &base)
{
    return {std::filesystem::relative(path, base)};
}

void FileSystem::Copy(const Path &source, const Path &destination)
{
    std::filesystem::copy(source, destination, std::filesystem::copy_options::recursive);
}

bool FileSystem::CopyFile(const Path &source, const Path &destination)
{
    return std::filesystem::copy_file(source, destination);
}

bool FileSystem::CreateDirectory(const Path &path)
{
    return std::filesystem::create_directory(path);
}

bool FileSystem::CreateDirectories(const Path &path)
{
    return std::filesystem::create_directories(path);
}

bool FileSystem::Remove(const Path &path)
{
    return std::filesystem::remove(path);
}

std::uintmax_t FileSystem::RemoveAll(const Path &path)
{
    return std::filesystem::remove_all(path);
}

void FileSystem::Rename(const Path &oldPath, const Path &newPath)
{
    std::filesystem::rename(oldPath, newPath);
}

void FileSystem::ResizeFile(const Path &path, std::uintmax_t size)
{
    std::filesystem::resize_file(path, size);
}

bool FileSystem::Exists(const Path &path)
{
    return std::filesystem::exists(path);
}

std::uintmax_t FileSystem::FileSize(const Path &path)
{
    return std::filesystem::file_size(path);
}

std::filesystem::perms FileSystem::GetPermissions(const Path &path)
{
    return std::filesystem::status(path).permissions();
}

Path FileSystem::GetCurrentPath()
{
    return {std::filesystem::current_path()};
}

std::filesystem::space_info FileSystem::GetSpace(const Path &path)
{
    return std::filesystem::space(path);
}

bool FileSystem::IsDirectory(const Path &path)
{
    return std::filesystem::is_directory(path);
}

bool FileSystem::IsFile(const Path &path)
{
    return std::filesystem::is_regular_file(path);
}

void FileSystem::SetCurrentPath(const Path &path)
{
    std::filesystem::current_path(path);
}

void FileSystem::SetPermissions(const Path &path, std::filesystem::perms permissions)
{
    std::filesystem::permissions(path, permissions);
}

} // namespace Lumen