#pragma once

#include "Lumen/Asset/AssetImporter.hpp"

#include <unordered_map>

namespace Lumen
{

using AssetImporterMap = std::unordered_map<AssetType, Ref<AssetImporter>>;
using DefaultImporterMap = std::unordered_map<AssetType, Ref<DefaultAssetImporter>>;

class AssetImporterRegistry
{
public:
    AssetImporterRegistry() = delete;

public:
    static bool Has(AssetType type);
    static bool HasDefault(AssetType type);

    static Ref<AssetImporter> Get(AssetType type);
    static Ref<DefaultAssetImporter> GetDefault(AssetType type);

    static void Register(AssetType type, Ref<AssetImporter> importer);

private:
    static AssetImporterMap s_ImporterMap;
    static DefaultImporterMap s_DefaultImporterMap;
};

} // namespace Lumen