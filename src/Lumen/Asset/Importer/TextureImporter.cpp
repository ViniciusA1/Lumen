#include "Lumen/Asset/Importer/TextureImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Texture2D Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    ::Texture2D texture = LoadTexture(metadata.Path.String().c_str());
    ::SetTextureFilter(texture, TEXTURE_FILTER_POINT);
    ::SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
    ::GenTextureMipmaps(&texture);
    return {handle, texture};
}

template <> bool Export(const Texture2D &texture)
{
    if (!texture.IsValid())
        return false;

    ::Texture2D *rayTexture = texture;
    ::UnloadTexture(*rayTexture);
    delete rayTexture;
    return true;
}

Texture2D LoadTextureFromImage(const Image &image)
{
    Texture2D texture = {image.GetHandle(), ::LoadTextureFromImage(image)};
    return texture;
}

} // namespace Lumen::AssetImporter