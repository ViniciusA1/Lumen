#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Core/Memory.hpp"
#include <map>
#include <typeindex>

namespace Lumen
{

class AssetManager
{
public:
    template <typename T> static inline Ref<T> Get(UUID uuid);
    template <typename T> static inline Ref<T> Get(const std::string &name);
    template <typename T> static inline Ref<T> Load(const AssetMetadata &metadata);

    static Path GetWorkingDirectory();
    static void SetWorkingDirectory(const Path &path);

private:
    static std::map<std::type_index, std::map<UUID, Ref<Asset>>> s_AssetCache;
    static std::map<std::type_index, Ref<Asset>> s_DefaultAsset;
    static Path s_WorkingDirectory;
};

template <typename T> Ref<T> AssetManager::Get(UUID uuid)
{
    auto typeCacheIt = s_AssetCache.find(typeid(T));
    if (typeCacheIt == s_AssetCache.end())
    {
        auto defaultIt = s_DefaultAsset.find(typeid(T));
        if (defaultIt != s_DefaultAsset.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }
    }

    const auto &typeCache = typeCacheIt->second;
    auto it = typeCache.find(uuid);
    if (it == typeCache.end())
    {
        auto defaultIt = s_DefaultAsset.find(typeid(T));
        if (defaultIt != s_DefaultAsset.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }
    }

    return std::dynamic_pointer_cast<T>(it->second);
}

template <typename T> Ref<T> AssetManager::Get(const std::string &name)
{
    auto typeCacheIt = s_AssetCache.find(typeid(T));
    if (typeCacheIt == s_AssetCache.end())
    {
        auto defaultIt = s_DefaultAsset.find(typeid(T));
        if (defaultIt != s_DefaultAsset.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }
    }

    const auto &typeCache = typeCacheIt->second;

    for (const auto &[uuid, asset] : typeCache)
    {
        if (asset->GetMetadata().Name == name)
        {
            return std::dynamic_pointer_cast<T>(asset);
        }
    }

    auto defaultIt = s_DefaultAsset.find(typeid(T));
    if (defaultIt != s_DefaultAsset.end())
    {
        return std::dynamic_pointer_cast<T>(defaultIt->second);
    }
}

template <typename T> Ref<T> AssetManager::Load(const AssetMetadata &metadata)
{
    auto &typeCache = s_AssetCache[typeid(T)];
    auto it = typeCache.find(metadata.ID);
    if (it != typeCache.end())
    {
        return std::dynamic_pointer_cast<T>(it->second);
    }

    AssetMetadata data = {metadata.ID, metadata.Name, s_WorkingDirectory / metadata.Path};
    Ref<Asset> asset = AssetImporter::ImportAsset(typeid(T), data);
    if (asset == nullptr)
    {
        auto defaultIt = s_DefaultAsset.find(typeid(T));
        if (defaultIt != s_DefaultAsset.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }
    }

    typeCache[metadata.ID] = asset;
    return std::dynamic_pointer_cast<T>(asset);
}

} // namespace Lumen