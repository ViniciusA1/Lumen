#include "Lumen/Asset/Importer/TextureImporter.hpp"
#include "Lumen/Graphics/Texture.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> Texture2DImporter::Import(const AssetMetadata &metadata)
{
    Texture2D texture = {
        metadata.Handle,
        LoadTexture(metadata.Path.String().c_str()),
    };

    return CreateScope<Texture2D>(texture);
}

void Texture2DImporter::Export(AssetEntry &entry)
{
    auto *texture = entry.GetAsset<Texture2D>();
    if (!texture->IsValid())
        return;

    ::Texture2D *rayTexture = *texture;
    ::UnloadTexture(*rayTexture);
    delete rayTexture;
}

} // namespace Lumen