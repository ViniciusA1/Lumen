#include "Lumen/Asset/Importer/ImageImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Image> Import(const AssetMetadata &metadata)
{
    Ref<Image> image =
        CreateRef<Image>(metadata, LoadImage(metadata.Path.String().c_str()));
    return image;
}

template <> bool Export(const Ref<Image> &image)
{
    if (!image->IsValid())
    {
        return false;
    }

    ::UnloadImage(*image);
    return true;
}

} // namespace Lumen::AssetImporter