#pragma once

#include "Lumen/Asset/AssetEntry.hpp"
#include "Lumen/Event/FileEvent.hpp"
#include "Lumen/File/FileWatcher.hpp"

#include <unordered_map>
#include <vector>

namespace Lumen
{

using AssetMap = std::unordered_map<AssetHandle, AssetEntry>;
using DefaultAssetMap = std::unordered_map<AssetType, Scope<Asset>>;
using AssetPathMap = std::unordered_map<Path, AssetHandle>;

class AssetManager
{
public:
    AssetManager() = delete;

    static void Init(const Path &workingDirectory);

public:
    static bool IsImported(const AssetHandle &handle);
    static bool IsLoading(const AssetHandle &handle);
    static bool IsLoaded(const AssetHandle &handle);
    static bool IsFailed(const AssetHandle &handle);

    static AssetEntry &GetEntry(const AssetHandle &handle);
    static AssetHandle GetHandle(const Path &path);
    static AssetMetadata &GetMetadata(const AssetHandle &handle);
    static AssetMap &GetMap();
    static Path GetWorkingDirectory();

    static void SetWorkingDirectory(const Path &path);

    static void Clear();

    template <typename T> static inline T &GetDefault();
    template <typename T> static inline std::vector<T &> Get();
    template <typename T> static inline T &Get(const AssetHandle &handle);
    template <typename T> static inline T &Get(const Path &path);

    static void Unload(const AssetHandle &handle);
    static void Unload(AssetEntry &entry);

private:
    static void LoadDefaultAssets();
    static void Load(AssetEntry &entry);
    static void Reload(AssetEntry &entry);
    static void OnFileEvent(const FileEvent &event);
    static void OnFileEventModified(const Path &path, const std::string &extension);
    static void OnFileEventCreated(const Path &path, const std::string &extension);
    static void OnFileEventDeleted(const Path &path);

private:
    static Path s_WorkingDirectory;
    static AssetMap s_AssetMap;
    static DefaultAssetMap s_DefaultAssetMap;
    static AssetPathMap s_AssetPathMap;
    static FileWatcher s_FileWatcher;
};

} // namespace Lumen

#include "Lumen/Asset/AssetManager.inl"