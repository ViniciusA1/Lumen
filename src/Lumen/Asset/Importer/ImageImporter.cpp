#include "Lumen/Asset/Importer/ImageImporter.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "raylib.h"

namespace Lumen
{

Ref<Asset> ImageImporter::ImportImage(const AssetMetadata &metadata)
{
    Ref<Image> image =
        CreateRef<Image>(metadata, LoadImage(metadata.Path.String().c_str()));
    return std::static_pointer_cast<Asset>(image);
}

} // namespace Lumen