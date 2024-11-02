#include "Lumen/Editor/Panel/ProjectPanel.hpp"
#include "imgui.h"
#include <filesystem>
#include <stack>
#include <unordered_map>

namespace Lumen
{

ProjectPanel::ProjectPanel(const std::filesystem::path &rootPath)
{
    m_RootDirectory = {rootPath};
    m_SelectedDirectory = rootPath;
    LoadDirectoryEntries(&m_RootDirectory);
}

void ProjectPanel::Draw()
{
    ImGui::Begin("Project");

    ImGui::Columns(2, nullptr, true);

    ImGui::BeginChild("DirectoryTree");
    DrawDirectoryTree();
    ImGui::EndChild();

    ImGui::NextColumn();

    const DirectoryEntry *selectedDirEntry =
        FindDirectoryEntry(m_RootDirectory, m_SelectedDirectory);
    if (selectedDirEntry)
    {
        DrawFileList(*selectedDirEntry);
    }

    ImGui::Columns(1);
    ImGui::End();
}

void ProjectPanel::DrawDirectoryTree()
{
    std::stack<const DirectoryEntry *> dirStack;
    std::stack<int> openStack;

    dirStack.push(&m_RootDirectory);
    openStack.push(0);

    while (!dirStack.empty())
    {
        const DirectoryEntry *currentDir = dirStack.top();
        int openNodes = openStack.top();
        openStack.pop();
        dirStack.pop();

        ImGuiTreeNodeFlags nodeFlags =
            ImGuiTreeNodeFlags_OpenOnArrow |
            (currentDir->path == m_SelectedDirectory ? ImGuiTreeNodeFlags_Selected : 0);

        bool open =
            ImGui::TreeNodeEx(currentDir->path.filename().string().c_str(), nodeFlags);

        if (ImGui::IsItemClicked())
        {
            m_SelectedDirectory = currentDir->path;
        }

        if (open)
        {
            for (const auto &subdir : currentDir->subdirectories)
            {
                dirStack.push(&subdir);
                openStack.push(1);
            }
            ImGui::TreePop();
        }
    }
}

void ProjectPanel::DrawFileList(const DirectoryEntry &dirEntry)
{
    ImGui::BeginChild("FileView");

    for (const auto &file : dirEntry.files)
    {
        ImGui::Selectable(file.name.c_str());

        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Open"))
            {
                // Handle file opening
            }
            if (ImGui::MenuItem("Delete"))
            {
                // Handle file deletion
            }
            ImGui::EndPopup();
        }
    }

    ImGui::EndChild();
}

void ProjectPanel::LoadDirectoryEntries(DirectoryEntry *rootDirEntry)
{
    if (!rootDirEntry || !std::filesystem::exists(rootDirEntry->path) ||
        !std::filesystem::is_directory(rootDirEntry->path))
        return;

    std::unordered_map<std::filesystem::path, DirectoryEntry *> dirMap;
    dirMap[rootDirEntry->path] = rootDirEntry;

    for (const auto &entry :
         std::filesystem::recursive_directory_iterator(rootDirEntry->path))
    {
        const auto &path = entry.path();
        auto *parentDir = dirMap[path.parent_path()];

        if (entry.is_directory())
        {
            DirectoryEntry subdir{path, {}, {}};
            parentDir->subdirectories.push_back(std::move(subdir));
            dirMap[path] = &parentDir->subdirectories.back();
        }
        else if (entry.is_regular_file())
        {
            parentDir->files.push_back({path.filename().string(), false});
        }
    }
}

const DirectoryEntry *ProjectPanel::FindDirectoryEntry(const DirectoryEntry &root,
                                                       const std::filesystem::path &path)
{
    std::stack<const DirectoryEntry *> stack;
    stack.push(&root);

    while (!stack.empty())
    {
        const DirectoryEntry *current = stack.top();
        stack.pop();

        if (current->path == path)
            return current;

        for (const auto &subdir : current->subdirectories)
            stack.push(&subdir);
    }

    return nullptr;
}

} // namespace Lumen