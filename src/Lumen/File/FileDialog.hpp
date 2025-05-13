#pragma once

#include "Lumen/File/Path.hpp"

#include <span>
#include <vector>

namespace Lumen
{

struct DialogResult
{
    enum class Status
    {
        Ok,
        Cancel,
        Error
    } Status;

    std::vector<Path> Paths;
    std::string Error;
};

class FileDialog
{
public:
    FileDialog() = delete;

public:
    static void Init();
    static void Shutdown();

    static void CopyResult(const std::span<char> &buffer, const DialogResult &result);

    static DialogResult OpenFile(
        const std::vector<std::pair<std::string, std::string>> &filters = {},
        const Path &defaultPath = {});

    static DialogResult OpenMultipleFiles(
        const std::vector<std::pair<std::string, std::string>> &filters = {},
        const Path &defaultPath = {});

    static DialogResult PickFolder(const Path &defaultPath = {});

    static DialogResult SaveFile(
        const std::vector<std::pair<std::string, std::string>> &filters = {},
        const Path &defaultPath = {}, const std::string &defaultName = {});
};

} // namespace Lumen