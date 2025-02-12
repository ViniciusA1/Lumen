#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Core/Memory.hpp"

#include <map>
#include <memory>
#include <typeindex>

namespace Lumen
{

class AssetManager
{
public:
    template <typename T> static inline Ref<T> Get(UUID uuid);
    template <typename T> static inline Ref<T> Get(const std::string &name);
    template <typename T> static inline Ref<T> Load(const AssetMetadata &metadata);
    template <typename T> static inline void Unload(UUID uuid);

    static Path GetWorkingDirectory();
    static void SetWorkingDirectory(const Path &path);

private:
    static std::map<UUID, Ref<Asset>> s_AssetMap;
    static std::map<std::type_index, Ref<Asset>> s_DefaultAssetMap;
    static Path s_WorkingDirectory;
};

template <typename T> Ref<T> AssetManager::Get(UUID uuid)
{
    auto it = s_AssetMap.find(uuid);
    if (it == s_AssetMap.end())
    {
        auto defaultIt = s_DefaultAssetMap.find(typeid(T));
        if (defaultIt != s_DefaultAssetMap.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }

        return nullptr;
    }

    return std::dynamic_pointer_cast<T>(it->second);
}

template <typename T> Ref<T> AssetManager::Get(const std::string &name)
{
    for (const auto &[uuid, asset] : s_AssetMap)
    {
        if (asset->GetMetadata().Name == name)
        {
            return std::dynamic_pointer_cast<T>(asset);
        }
    }

    auto defaultIt = s_DefaultAssetMap.find(typeid(T));
    if (defaultIt != s_DefaultAssetMap.end())
    {
        return std::dynamic_pointer_cast<T>(defaultIt->second);
    }

    return nullptr;
}

template <typename T> Ref<T> AssetManager::Load(const AssetMetadata &metadata)
{
    auto it = s_AssetMap.find(metadata.ID);
    if (it != s_AssetMap.end())
    {
        return std::dynamic_pointer_cast<T>(it->second);
    }

    AssetMetadata data = {metadata.ID, metadata.Name, s_WorkingDirectory / metadata.Path};
    Ref<T> asset = AssetImporter::Import<T>(data);
    if (asset == nullptr)
    {
        auto defaultIt = s_DefaultAssetMap.find(typeid(T));
        if (defaultIt != s_DefaultAssetMap.end())
        {
            return std::dynamic_pointer_cast<T>(defaultIt->second);
        }

        return nullptr;
    }

    s_AssetMap[metadata.ID] = std::static_pointer_cast<Asset>(asset);
    return asset;
}

template <typename T> void AssetManager::Unload(UUID uuid)
{
    auto it = s_AssetMap.find(uuid);
    if (it != s_AssetMap.end())
    {
        AssetImporter::Export<T>(std::static_pointer_cast<T>(it->second));
        s_AssetMap.erase(it);
    }
}

} // namespace Lumen