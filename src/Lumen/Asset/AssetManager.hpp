#pragma once

#include "Lumen/Asset/AssetImporter.hpp"

#include <unordered_map>

namespace Lumen
{

enum class AssetManagerMode
{
    Editor,
    Runtime
};

template <typename T> struct AssetStorage
{
    static std::unordered_map<AssetHandle, T> s_Map;
};

template <typename T> struct DefaultAssetStorage
{
    static T s_Asset;
};

class AssetManager
{
public:
    AssetManager() = delete;

public:
    static void LoadDefaultAssets();

public:
    template <typename T> static inline bool IsLoaded(const AssetHandle &handle);
    template <typename T> static inline bool IsValid(const AssetHandle &handle);

    static std::unordered_map<AssetHandle, AssetMetadata> &GetMetadataMap();
    static AssetMetadata GetMetadata(const AssetHandle &handle);
    static AssetManagerMode GetMode();
    static Path GetWorkingDirectory();

    template <typename T> static std::unordered_map<AssetHandle, T> GetMap();

    static void SetMetadata(const AssetHandle &handle, const AssetMetadata &metadata);
    static void SetMode(AssetManagerMode mode);
    static void SetWorkingDirectory(const Path &path);

    static void Clear();

    template <typename T> static inline T Get(const AssetHandle &handle);
    template <typename T> static inline T Get(const AssetMetadata &metadata);
    template <typename T> static inline T GetDefault();

    template <typename T>
    static inline void Load(const AssetHandle &handle, const AssetMetadata &metadata);

    template <typename T> static inline bool Unload(const AssetHandle &handle);
    template <typename T> static inline bool Unload(const T &asset);

private:
    static std::unordered_map<AssetHandle, AssetMetadata> s_AssetMetadataMap;
    static Path s_WorkingDirectory;
    static AssetManagerMode s_Mode;
};

template <typename T> bool AssetManager::IsLoaded(const AssetHandle &handle)
{
    auto &map = AssetStorage<T>::s_Map;
    return map.contains(handle);
}

template <typename T> bool AssetManager::IsValid(const AssetHandle &handle)
{
    auto &map = AssetStorage<T>::s_Map;
    auto it = map.find(handle);
    if (it == map.end())
        return false;

    return it->second.IsValid();
}

template <typename T> std::unordered_map<AssetHandle, T> AssetManager::GetMap()
{
    return AssetStorage<T>::s_Map;
}

template <typename T> T AssetManager::Get(const AssetHandle &handle)
{
    auto it = AssetStorage<T>::s_Map.find(handle);
    if (it != AssetStorage<T>::s_Map.end())
        return it->second;

    auto itMeta = s_AssetMetadataMap.find(handle);
    if (itMeta == s_AssetMetadataMap.end())
        return GetDefault<T>();

    Load<T>(handle, itMeta->second);
    return GetDefault<T>();
}

template <typename T> T AssetManager::Get(const AssetMetadata &metadata)
{
    for (const auto &[handle, meta] : s_AssetMetadataMap)
    {
        if (metadata == meta)
            return Get<T>(handle);
    }

    AssetHandle newHandle;
    s_AssetMetadataMap[newHandle] = metadata;

    Load<T>(newHandle, metadata);
    return GetDefault<T>();
}

template <typename T> T AssetManager::GetDefault()
{
    return DefaultAssetStorage<T>::s_Asset;
}

template <typename T>
void AssetManager::Load(const AssetHandle &handle, const AssetMetadata &metadata)
{
    T asset = AssetImporter::Import<T>(handle, metadata);
    if (asset.IsValid())
        AssetStorage<T>::s_Map[handle] = asset;
}

template <typename T> bool AssetManager::Unload(const AssetHandle &handle)
{
    auto it = AssetStorage<T>::s_Map.find(handle);
    if (it == AssetStorage<T>::s_Map.end())
        return false;

    bool isExported = AssetImporter::Export(it->second);
    if (isExported)
        AssetStorage<T>::s_Map.erase(it);

    return isExported;
}

template <typename T> bool AssetManager::Unload(const T &asset)
{
    if (Unload<T>(asset.GetHandle()))
        return true;

    return AssetImporter::Export(asset);
}

} // namespace Lumen