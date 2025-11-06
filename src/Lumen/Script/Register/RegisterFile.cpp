#include "Lumen/File/DirectoryIterator.hpp"
#include "Lumen/File/FileSystem.hpp"
#include "Lumen/File/FileWatcher.hpp"
#include "Lumen/Script/Register/RegisterAPI.hpp"
#include "Lumen/Script/ScriptEngine.hpp"

namespace Lumen
{

static void RegisterDirectoryEntry();
static void RegisterDirectoryIterator();
static void RegisterFileDialog();
static void RegisterFileSize();
static void RegisterFileSystem();
static void RegisterFileWatcher();
static void RegisterPath();

void RegisterFileAPI()
{
    RegisterDirectoryEntry();
    RegisterDirectoryIterator();
    RegisterFileSize();
    RegisterFileSystem();
    RegisterFileWatcher();
    RegisterPath();
}

static void RegisterDirectoryEntry()
{
    ScriptEngine::GetInstance()
        ->RegisterType<DirectoryEntry>("DirectoryEntry")
        .Constructors<DirectoryEntry()>()
        .Property("path", &DirectoryEntry::GetPath)
        .Property("file_size", &DirectoryEntry::FileSize)
        .Method("exists", &DirectoryEntry::Exists)
        .Method("is_directory", &DirectoryEntry::IsDirectory)
        .Method("is_file", &DirectoryEntry::IsFile)
        .Method("replace_filename", &DirectoryEntry::ReplaceFilename)
        .Method("refresh", &DirectoryEntry::Refresh)
        .OperatorEq(
            [](const DirectoryEntry &a, const DirectoryEntry &b) { return a == b; });
}

static void RegisterDirectoryIterator()
{
    ScriptEngine::GetInstance()
        ->RegisterType<DirectoryIterator>("DirectoryIterator")
        .Constructors<DirectoryIterator(), DirectoryIterator(const Path &)>()
        .OperatorNext([](DirectoryIterator &it) -> std::optional<DirectoryEntry> {
            static DirectoryIterator endIt;
            if (it == endIt)
                return std::nullopt;
            DirectoryEntry entry = *it;
            ++it;
            return entry;
        });

    ScriptEngine::GetInstance()
        ->RegisterType<RecursiveDirectoryIterator>("RecursiveDirectoryIterator")
        .Constructors<RecursiveDirectoryIterator(),
                      RecursiveDirectoryIterator(const Path &)>()
        .OperatorNext(
            [](RecursiveDirectoryIterator &it) -> std::optional<DirectoryEntry> {
                static RecursiveDirectoryIterator endIt;
                if (it == endIt)
                    return std::nullopt;
                DirectoryEntry entry = *it;
                ++it;
                return entry;
            });
}

static void RegisterFileSize()
{
    ScriptEngine::GetInstance()
        ->RegisterType<FileSize>("FileSize")
        .Constructors<FileSize(), FileSize(uint64_t)>()
        .Property("bytes", &FileSize::Bytes)
        .OperatorToString(&FileSize::String);
}

static void RegisterFileSystem()
{
    ScriptEngine::GetInstance()
        ->RegisterType<FileSystem>("FileSystem")
        .StaticMethod("absolute", &FileSystem::Absolute)
        .StaticMethod("canonical", &FileSystem::Canonical)
        .StaticMethod("relative", static_cast<Path (*)(const Path &, const Path &)>(
                                      &FileSystem::Relative))
        .StaticMethod("copy", &FileSystem::Copy)
        .StaticMethod("copy_file", &FileSystem::CopyFile)
        .StaticMethod("copy_folder", &FileSystem::CopyFolder)
        .StaticMethod("create_directory", &FileSystem::CreateDirectory)
        .StaticMethod("create_directories", &FileSystem::CreateDirectories)
        .StaticMethod("remove", &FileSystem::Remove)
        .StaticMethod("remove_all", &FileSystem::RemoveAll)
        .StaticMethod("rename", &FileSystem::Rename)
        .StaticMethod("resize_file", &FileSystem::ResizeFile)
        .StaticMethod("exists", &FileSystem::Exists)
        .StaticMethod("file_size", &FileSystem::FileSize)
        .StaticMethod("permissions", &FileSystem::GetPermissions)
        .StaticMethod("current_path", &FileSystem::GetCurrentPath)
        .StaticMethod("space", &FileSystem::GetSpace)
        .StaticMethod("is_directory", &FileSystem::IsDirectory)
        .StaticMethod("is_file", &FileSystem::IsFile)
        .StaticMethod("last_date_modified", &FileSystem::LastDateModified)
        .StaticMethod("last_write_time", &FileSystem::LastWriteTime)
        .StaticMethod("set_current_path", &FileSystem::SetCurrentPath)
        .StaticMethod("set_permissions", &FileSystem::SetPermissions);
}

static void RegisterFileWatcher()
{
    ScriptEngine::GetInstance()
        ->RegisterType<FileWatcher>("FileWatcher")
        .Constructors<FileWatcher(), FileWatcher(FileWatcherMode, int)>()
        .Property("mode", &FileWatcher::GetMode)
        .Property("interval", &FileWatcher::GetInterval)
        .Method("watch_directory",
                [](FileWatcher &self, const Path &dir, const sol::function &callback,
                   bool recursive) {
                    self.WatchDirectory(
                        dir, [callback](const FileEvent &event) { callback(event); },
                        recursive);
                })
        .Method("watch_file",
                [](FileWatcher &self, const Path &path, const sol::function &callback) {
                    self.WatchFile(
                        path, [callback](const FileEvent &event) { callback(event); });
                })
        .Method("unwatch_directory", &FileWatcher::UnwatchDirectory)
        .Method("unwatch_file", &FileWatcher::UnwatchFile)
        .Method("update", &FileWatcher::Update)
        .Method("stop", &FileWatcher::Stop);
}

static void RegisterPath()
{
    ScriptEngine::GetInstance()
        ->RegisterType<Path>("Path")
        .Constructors<Path(), Path(const char *)>()
        .StaticProperty("preferred_separator", Path::PreferredSeparator)
        .Property("root_name", &Path::RootName)
        .Property("root_directory", &Path::RootDirectory)
        .Property("root_path", &Path::RootPath)
        .Property("relative_path", &Path::RelativePath)
        .Property("parent_path", &Path::ParentPath)
        .Property("filename", &Path::Filename)
        .Property("stem", &Path::Stem)
        .Property("extension", &Path::Extension)
        .Method("is_empty", &Path::IsEmpty)
        .Method("is_absolute", &Path::IsAbsolute)
        .Method("is_relative", &Path::IsRelative)
        .Method("has_root_path", &Path::HasRootPath)
        .Method("has_root_name", &Path::HasRootName)
        .Method("has_root_directory", &Path::HasRootDirectory)
        .Method("has_relative_path", &Path::HasRelativePath)
        .Method("has_parent_path", &Path::HasParentPath)
        .Method("has_filename", &Path::HasFilename)
        .Method("has_stem", &Path::HasStem)
        .Method("has_extension", &Path::HasExtension)
        .Method("clear", &Path::Clear)
        .Method("remove_filename", &Path::RemoveFilename)
        .Method("replace_filename", &Path::ReplaceFilename)
        .Method("replace_extension", &Path::ReplaceExtension)
        .OperatorEq([](const Path &a, const Path &b) { return a == b; })
        .OperatorDiv([](const Path &a, const Path &b) { return a / b; })
        .OperatorAdd([](const Path &a, const std::string &s) {
            Path p = a;
            p += s;
            return p;
        })
        .OperatorToString(&Path::String);
}

} // namespace Lumen