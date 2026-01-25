#pragma once

#include "Lumen/Asset/AssetManager.hpp"

namespace Lumen
{

template <typename T> inline T &AssetManager::GetDefault()
{
    return *static_cast<T *>(s_DefaultAssetMap.find(T().GetType())->second.get());
}

template <typename T> inline std::vector<T &> AssetManager::Get()
{
    std::vector<T &> assets;
    assets.reserve(s_AssetMap.size());

    AssetType type = T().GetType();
    for (auto &[handle, scope] : s_AssetMap)
    {
        if (scope.Asset->GetType() == type)
            assets.push_back(*static_cast<T *>(scope.Asset.get()));
    }

    return assets;
}

template <typename T> inline T &AssetManager::Get(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    if (it == s_AssetMap.end())
        return GetDefault<T>();

    AssetEntry &entry = it->second;

    switch (entry.Metadata.Status)
    {
    case AssetStatus::Loaded:
        return *static_cast<T *>(entry.Asset.get());
    case AssetStatus::Imported:
        entry.Metadata.Status = AssetStatus::Loading;
        Load(entry);
        return *static_cast<T *>(entry.Asset.get());
    case AssetStatus::NotImported:
    case AssetStatus::Loading:
    case AssetStatus::Failed:
    default:
        return GetDefault<T>();
    }
}

template <typename T> inline T &AssetManager::Get(const Path &path)
{
    auto it = s_AssetPathMap.find(path);
    if (it == s_AssetPathMap.end())
        return GetDefault<T>();

    return Get<T>(it->second);
}

} // namespace Lumen