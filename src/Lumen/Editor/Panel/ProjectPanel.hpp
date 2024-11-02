#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace Lumen
{

struct FileEntry
{
    std::string name;
    bool isDirectory;
};

struct DirectoryEntry
{
    std::filesystem::path path;
    std::vector<DirectoryEntry> subdirectories;
    std::vector<FileEntry> files;
};

class ProjectPanel
{
public:
    ProjectPanel(const std::filesystem::path &rootPath);

    void Draw();

private:
    void DrawDirectoryTree();
    void DrawFileList(const DirectoryEntry &dirEntry);

    void LoadDirectoryEntries(DirectoryEntry *rootDirEntry);
    const DirectoryEntry *FindDirectoryEntry(const DirectoryEntry &root,
                                             const std::filesystem::path &path);

private:
    std::filesystem::path m_SelectedDirectory;
    DirectoryEntry m_RootDirectory;
};

} // namespace Lumen