#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Core/Memory.hpp"

#include <memory>
#include <typeindex>
#include <unordered_map>

namespace Lumen
{

enum class AssetManagerMode
{
    Editor,
    Runtime
};

class AssetManager
{
public:
    AssetManager() = delete;

public:
    static bool IsLoaded(UUID uuid);
    static bool IsValid(UUID uuid);

    static std::unordered_map<UUID, AssetMetadata> &GetMetadataMap();
    static AssetMetadata GetMetadata(UUID uuid);
    static AssetManagerMode GetMode();
    static Path GetWorkingDirectory();

    static void SetMetadata(UUID uuid, const AssetMetadata &metadata);
    static void SetMode(AssetManagerMode mode);
    static void SetWorkingDirectory(const Path &path);

    static void Clear();

    template <typename T> static inline Ref<T> Get(UUID uuid);
    template <typename T> static inline void Unload(UUID uuid);

private:
    static std::unordered_map<UUID, Ref<Asset>> s_AssetMap;
    static std::unordered_map<UUID, AssetMetadata> s_AssetMetadataMap;
    static std::unordered_map<std::type_index, Ref<Asset>> s_DefaultAssetMap;
    static Path s_WorkingDirectory;
    static AssetManagerMode s_Mode;
};

template <typename T> Ref<T> AssetManager::Get(UUID uuid)
{
    if (IsLoaded(uuid))
    {
        return std::dynamic_pointer_cast<T>(s_AssetMap.at(uuid));
    }

    Ref<T> asset = nullptr;

    if (s_Mode == AssetManagerMode::Editor)
    {
        AssetMetadata metadata = s_AssetMetadataMap.at(uuid);
        AssetMetadata data = {s_WorkingDirectory / metadata.Path, metadata.Name};
        asset = AssetImporter::Import<T>(uuid, data);
        if (asset == nullptr || !asset->IsValid())
        {
            auto defaultIt = s_DefaultAssetMap.find(typeid(T));
            if (defaultIt != s_DefaultAssetMap.end())
            {
                return std::dynamic_pointer_cast<T>(defaultIt->second);
            }

            return nullptr;
        }

        s_AssetMap[uuid] = std::static_pointer_cast<Asset>(asset);
    }

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