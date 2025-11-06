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

} // namespace Lumen

#include "Lumen/Asset/AssetManager.inl"