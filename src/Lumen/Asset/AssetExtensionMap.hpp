#pragma once

#include "Lumen/Asset/AssetType.hpp"

#include <string>
#include <unordered_map>

namespace Lumen
{

class AssetExtensionMap
{
public:
    AssetExtensionMap() = delete;

public:
    static bool HasExtension(const std::string &extension);

    static AssetType GetAssetType(const std::string &extension);

    static void RegisterExtension(const std::string &extension, AssetType type);
    static void UnregisterExtension(const std::string &extension);

private:
    static std::unordered_map<std::string, AssetType> s_Extensions;
};

} // namespace Lumen