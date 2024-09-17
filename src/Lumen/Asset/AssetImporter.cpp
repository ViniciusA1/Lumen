#include "Lumen/Asset/AssetImporter.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include <functional>
#include <raylib.h>
#include <unordered_map>

namespace Lumen
{

static Ref<Asset> ImportTexture(const AssetMetadata &metadata);

static std::unordered_map<std::type_index,
                          std::function<Ref<Asset>(const AssetMetadata &)>>
    s_ImportFunc = {{typeid(Texture2D), ImportTexture}};

Ref<Asset> AssetImporter::ImportAsset(std::type_index type, const AssetMetadata &metadata)
{
    Ref<Asset> assetLoaded = s_ImportFunc[type](metadata);
    if (assetLoaded->IsReady() == false)
    {
        return nullptr;
    }
    return assetLoaded;
}

static Ref<Asset> ImportTexture(const AssetMetadata &metadata)
{
    Ref<Texture2D> texture =
        CreateRef<Texture2D>(metadata, LoadTexture(metadata.Path.c_str()));
    return std::static_pointer_cast<Asset>(texture);
}

} // namespace Lumen