#include "Lumen/Asset/Importer/FontImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Font Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    Font font = {handle, LoadFont(metadata.Path.String().c_str())};
    return font;
}

template <> bool Export(const Font &font)
{
    if (!font.IsValid())
        return false;

    ::Font *rayFont = font;
    ::UnloadFont(*rayFont);
    delete rayFont;
    return true;
}

} // namespace Lumen::AssetImporter