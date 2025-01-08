#pragma once

#include "Lumen/File/Path.hpp"

namespace Lumen
{

class FileSystem
{
public:
    FileSystem() = delete;

    static Path Absolute(const Path &path);
    static Path Canonical(const Path &path);
    static Path Relative(const Path &path, const Path &base = Path("."));

    static void Copy(const Path &source, const Path &destination);
    static bool CopyFile(const Path &source, const Path &destination);
    static bool CopyFolder(const Path &source, const Path &destination);
    static bool CreateDirectory(const Path &path);
    static bool CreateDirectories(const Path &path);
    static bool Remove(const Path &path);
    static std::uintmax_t RemoveAll(const Path &path);
    static void Rename(const Path &old_path, const Path &new_path);
    static void ResizeFile(const Path &path, std::uintmax_t size);

    static bool Exists(const Path &path);
    static std::uintmax_t FileSize(const Path &path);
    static std::filesystem::perms GetPermissions(const Path &path);
    static Path GetCurrentPath();
    static std::filesystem::space_info GetSpace(const Path &path);
    static bool IsDirectory(const Path &path);
    static bool IsFile(const Path &path);
    static std::string LastDateModified(const Path &path);
    static std::filesystem::file_time_type LastWriteTime(const Path &path);
    static void SetCurrentPath(const Path &path);
    static void SetPermissions(const Path &path, std::filesystem::perms permissions);
};

} // namespace Lumen