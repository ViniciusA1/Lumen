#include "Lumen/Asset/Importer/TextureImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Texture2D> Import(const AssetMetadata &metadata)
{
    Ref<Texture2D> texture =
        CreateRef<Texture2D>(metadata, LoadTexture(metadata.Path.String().c_str()));
    return texture;
}

template <> bool Export(const Ref<Texture2D> &texture)
{
    if (!texture->IsValid())
    {
        return false;
    }

    ::UnloadTexture(*texture);
    return true;
}

} // namespace Lumen::AssetImporter