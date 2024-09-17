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
    template <typename T> static Ref<T> Load(const AssetMetadata &metadata)
    {
        auto &typeCache = m_AssetCache[typeid(T)];
        auto it = typeCache.find(metadata.ID);
        if (it != typeCache.end())
        {
            return std::dynamic_pointer_cast<T>(it->second);
        }

        Ref<Asset> asset = AssetImporter::ImportAsset(typeid(T), metadata);
        if (asset == nullptr)
        {
            auto defaultIt = m_DefaultAsset.find(typeid(T));
            if (defaultIt != m_DefaultAsset.end())
            {
                return std::dynamic_pointer_cast<T>(defaultIt->second);
            }
        }

        typeCache[metadata.ID] = asset;
        return std::dynamic_pointer_cast<T>(asset);
    }

    template <typename T> static Ref<T> Get(UUID uuid)
    {
        auto typeCacheIt = m_AssetCache.find(typeid(T));
        if (typeCacheIt == m_AssetCache.end())
        {
            auto defaultIt = m_DefaultAsset.find(typeid(T));
            if (defaultIt != m_DefaultAsset.end())
            {
                return std::dynamic_pointer_cast<T>(defaultIt->second);
            }
        }

        const auto &typeCache = typeCacheIt->second;
        auto it = typeCache.find(uuid);
        if (it == typeCache.end())
        {
            auto defaultIt = m_DefaultAsset.find(typeid(T));
            if (defaultIt != m_DefaultAsset.end())
            {
                return std::dynamic_pointer_cast<T>(defaultIt->second);
            }
        }

        return std::dynamic_pointer_cast<T>(it->second);
    }

private:
    static std::map<std::type_index, std::map<UUID, Ref<Asset>>> m_AssetCache;
    static std::map<std::type_index, Ref<Asset>> m_DefaultAsset;
};

} // namespace Lumen