#include "Lumen/Asset/Importer/TextureImporter.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "raylib.h"

namespace Lumen
{

Ref<Asset> TextureImporter::ImportTexture(const AssetMetadata &metadata)
{
    Ref<Texture2D> texture =
        CreateRef<Texture2D>(metadata, LoadTexture(metadata.Path.String().c_str()));
    return std::static_pointer_cast<Asset>(texture);
}

} // namespace Lumen