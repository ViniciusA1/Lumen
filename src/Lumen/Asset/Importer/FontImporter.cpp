#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Graphics/Font.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> FontImporter::Import(const AssetMetadata &metadata)
{
    Font font = {
        metadata.Handle,
        LoadFont(metadata.Path.String().c_str()),
    };

    return CreateScope<Font>(font);
}

void FontImporter::Export(AssetEntry &entry)
{
    Font *font = entry.GetAsset<Font>();
    if (!font->IsValid())
        return;

    ::Font *rayFont = *font;
    ::UnloadFont(*rayFont);
    delete rayFont;
}

} // namespace Lumen