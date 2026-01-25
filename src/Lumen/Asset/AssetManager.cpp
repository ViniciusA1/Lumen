#include "Lumen/Asset/AssetManager.hpp"
#include "Lumen/Asset/AssetExtensionMap.hpp"
#include "Lumen/Asset/AssetImporterRegistry.hpp"
#include "Lumen/File/FileSystem.hpp"
#include "Lumen/Serialization/Json.hpp"

#define DEFAULT_ASSET(TYPE)                                                              \
    s_DefaultAssetMap[AssetType::TYPE] =                                                 \
        AssetImporterRegistry::GetDefault(AssetType::TYPE)->Import()

namespace Lumen
{

Path AssetManager::s_WorkingDirectory;
AssetMap AssetManager::s_AssetMap;
DefaultAssetMap AssetManager::s_DefaultAssetMap;
AssetPathMap AssetManager::s_AssetPathMap;
FileWatcher AssetManager::s_FileWatcher;

static AssetEntry s_DummyEntry;

void AssetManager::Init(const Path &workingDirectory)
{
    s_WorkingDirectory = workingDirectory;
    LoadDefaultAssets();

    EventBus::Subscribe<FileEvent>(OnFileEvent);

    s_FileWatcher.WatchDirectory({
        .Path = workingDirectory,
        .Callback = [](const FileEvent &event) { EventBus::Publish(FileEvent{event}); },
        .Recursive = true,
        .RunCallbackOnStartup = true,
    });
}

void AssetManager::LoadDefaultAssets()
{
    DEFAULT_ASSET(Audio);
    DEFAULT_ASSET(Font);
    DEFAULT_ASSET(Material);
    DEFAULT_ASSET(Mesh);
    DEFAULT_ASSET(Model);
    DEFAULT_ASSET(Prefab);
    DEFAULT_ASSET(Scene);
    DEFAULT_ASSET(Script);
    DEFAULT_ASSET(Shader);
    DEFAULT_ASSET(Texture2D);
}

void AssetManager::OnFileEvent(const FileEvent &event)
{
    const Path &path = event.Path;
    const std::string &extension = path.Extension().String();

    switch (event.Type)
    {
    case FileEventType::Modified:
        OnFileEventModified(path, extension);
        break;
    case FileEventType::Created:
        OnFileEventCreated(path, extension);
        break;
    case FileEventType::Deleted:
        OnFileEventDeleted(path);
        break;
    }
}

void AssetManager::OnFileEventModified(const Path &path, const std::string &extension)
{
    if (extension == ".meta")
    {
        AssetMetadata metadata;
        Json::FromFile(path, metadata);
        auto it = s_AssetMap.find(metadata.Handle);
        it->second.Metadata = metadata;
        Reload(it->second);
    }
    else
    {
        auto it = s_AssetMap.find(GetHandle(path));
        Reload(it->second);
    }
}

void AssetManager::OnFileEventCreated(const Path &path, const std::string &extension)
{
    if (extension == ".meta")
        return;

    AssetMetadata metadata;
    Path metadataPath = path + ".meta";
    if (FileSystem::Exists(metadataPath))
    {
        Json::FromFile(metadataPath, metadata);
    }
    else
    {
        metadata = {
            .Handle = AssetHandle(),
            .Path = path,
            .Type = AssetExtensionMap::GetAssetType(extension),
            .Status = AssetStatus::Imported,
        };

        Json::ToFile(metadataPath, metadata);
    }

    s_AssetMap[metadata.Handle] = AssetEntry{metadata};
}

void AssetManager::OnFileEventDeleted(const Path &path)
{
    s_AssetPathMap.erase(path);
}

bool AssetManager::IsImported(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    return it != s_AssetMap.end() &&
           it->second.Metadata.Status != AssetStatus::NotImported;
}

bool AssetManager::IsLoading(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    return it != s_AssetMap.end() && it->second.Metadata.Status == AssetStatus::Loading;
}

bool AssetManager::IsLoaded(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    return it != s_AssetMap.end() && it->second.Metadata.Status == AssetStatus::Loaded;
}

bool AssetManager::IsFailed(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    return it != s_AssetMap.end() && it->second.Metadata.Status == AssetStatus::Failed;
}

AssetEntry &AssetManager::GetEntry(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    if (it == s_AssetMap.end())
        return s_DummyEntry;

    return it->second;
}

AssetHandle AssetManager::GetHandle(const Path &path)
{
    auto it = s_AssetPathMap.find(path);
    if (it == s_AssetPathMap.end())
        return AssetHandle::Null;

    return it->second;
}

AssetMetadata &AssetManager::GetMetadata(const AssetHandle &handle)
{
    auto it = s_AssetMap.find(handle);
    if (it == s_AssetMap.end())
        return s_DummyEntry.Metadata;

    return it->second.Metadata;
}

AssetMap &AssetManager::GetMap()
{
    return s_AssetMap;
}

Path AssetManager::GetWorkingDirectory()
{
    return s_WorkingDirectory;
}

void AssetManager::SetWorkingDirectory(const Path &path)
{
    s_WorkingDirectory = path;
}

void AssetManager::Clear()
{
    s_AssetMap.clear();
}

void AssetManager::Unload(const AssetHandle &handle)
{
    auto assetIt = s_AssetMap.find(handle);
    if (assetIt == s_AssetMap.end())
        return;

    AssetEntry &entry = assetIt->second;
    AssetImporterRegistry::Get(entry.Metadata.Type)->Export(entry);
    entry.Asset = nullptr;
    entry.Metadata.Status = AssetStatus::Imported;
}

void AssetManager::Unload(AssetEntry &entry)
{
    AssetImporterRegistry::Get(entry.Metadata.Type)->Export(entry);
    entry.Asset = nullptr;
    entry.Metadata.Status = AssetStatus::Imported;
}

void AssetManager::Load(AssetEntry &entry)
{
    Scope<Asset> loadedAsset =
        AssetImporterRegistry::Get(entry.Metadata.Type)->Import(entry.Metadata);

    if (loadedAsset->IsValid())
    {
        entry.Asset = std::move(loadedAsset);
        entry.Metadata.Status = AssetStatus::Loaded;
    }
    else
    {
        entry.Metadata.Status = AssetStatus::Failed;
    }
}

void AssetManager::Reload(AssetEntry &entry)
{
    Unload(entry);
    Load(entry);
}

} // namespace Lumen