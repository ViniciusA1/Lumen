#include "Lumen/Asset/Importer/ImageImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Image Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    Image image = {handle, LoadImage(metadata.Path.String().c_str())};
    return image;
}

template <> bool Export(const Image &image)
{
    if (!image.IsValid())
        return false;

    ::Image *rayImage = image;
    ::UnloadImage(*rayImage);
    delete rayImage;
    return true;
}

Image LoadImageFromTexture(const Texture2D &texture)
{
    Image image = {texture.GetHandle(), ::LoadImageFromTexture(texture)};
    return image;
}

} // namespace Lumen::AssetImporter