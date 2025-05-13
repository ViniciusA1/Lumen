#include "Lumen/File/FileDialog.hpp"

#include <nfd.h>

namespace Lumen
{

void FileDialog::Init()
{
    nfdresult_t result = NFD_Init();
}

void FileDialog::Shutdown()
{
    NFD_Quit();
}

void FileDialog::CopyResult(const std::span<char> &buffer, const DialogResult &result)
{
    if (result.Status != DialogResult::Status::Ok)
        return;

    const std::string &strResult = result.Paths[0].String();
    std::copy(strResult.begin(), strResult.end(), buffer.begin());
}

static nfdfilteritem_t makeFilter(const std::pair<std::string, std::string> &f)
{
    return {f.first.c_str(), f.second.c_str()};
}

DialogResult FileDialog::OpenFile(
    const std::vector<std::pair<std::string, std::string>> &filters,
    const Path &defaultPath)
{
    nfdchar_t *outPath = nullptr;
    std::vector<nfdfilteritem_t> items;
    items.reserve(filters.size());
    for (auto &f : filters)
        items.push_back(makeFilter(f));

    const std::string &defaultPathStr = defaultPath.String();
    nfdresult_t res =
        NFD_OpenDialog(&outPath, items.data(), items.size(),
                       defaultPathStr.empty() ? nullptr : defaultPathStr.c_str());

    if (res == NFD_OKAY)
    {
        Path path(outPath);
        free(outPath);
        return {DialogResult::Status::Ok, {path}, {}};
    }

    if (res == NFD_CANCEL)
        return {DialogResult::Status::Cancel, {}, {}};

    return {DialogResult::Status::Error, {}, NFD_GetError()};
}

DialogResult FileDialog::OpenMultipleFiles(
    const std::vector<std::pair<std::string, std::string>> &filters,
    const Path &defaultPath)
{
    nfdchar_t *outPath = nullptr;
    const std::string &defaultPathStr = defaultPath.String();
    nfdresult_t res = NFD_PickFolder(
        &outPath, defaultPathStr.empty() ? nullptr : defaultPathStr.c_str());

    if (res == NFD_OKAY)
    {
        Path path(outPath);
        free(outPath);
        return {DialogResult::Status::Ok, {path}, {}};
    }

    if (res == NFD_CANCEL)
        return {DialogResult::Status::Cancel, {}, {}};

    return {DialogResult::Status::Error, {}, NFD_GetError()};
}

DialogResult FileDialog::PickFolder(const Path &defaultPath)
{
    nfdchar_t *outPath = nullptr;
    const std::string &defaultPathStr = defaultPath.String();
    nfdresult_t res = NFD_PickFolder(
        &outPath, defaultPathStr.empty() ? nullptr : defaultPathStr.c_str());

    if (res == NFD_OKAY)
    {
        Path path(outPath);
        free(outPath);
        return {DialogResult::Status::Ok, {path}, {}};
    }

    if (res == NFD_CANCEL)
        return {DialogResult::Status::Cancel, {}, {}};

    return {DialogResult::Status::Error, {}, NFD_GetError()};
}

DialogResult FileDialog::SaveFile(
    const std::vector<std::pair<std::string, std::string>> &filters,
    const Path &defaultPath, const std::string &defaultName)
{
    nfdchar_t *outPath = nullptr;
    std::vector<nfdfilteritem_t> items;
    items.reserve(filters.size());
    for (auto &f : filters)
        items.push_back(makeFilter(f));

    const std::string &defaultPathStr = defaultPath.String();
    nfdresult_t res =
        NFD_SaveDialog(&outPath, items.data(), items.size(),
                       defaultPathStr.empty() ? nullptr : defaultPathStr.c_str(),
                       defaultName.empty() ? nullptr : defaultName.c_str());

    if (res == NFD_OKAY)
    {
        Path path(outPath);
        free(outPath);
        return {DialogResult::Status::Ok, {path}, {}};
    }

    if (res == NFD_CANCEL)
        return {DialogResult::Status::Cancel, {}, {}};

    return {DialogResult::Status::Error, {}, NFD_GetError()};
}

} // namespace Lumen