#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Graphics/Font.hpp"
#include "raylib.h"

namespace Lumen
{

Ref<Asset> FontImporter::ImportFont(const AssetMetadata &metadata)
{
    Ref<Font> font = CreateRef<Font>(metadata, LoadFont(metadata.Path.String().c_str()));
    return nullptr;
}

} // namespace Lumen