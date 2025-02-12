#include "Lumen/Asset/Importer/FontImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Font> Import(const AssetMetadata &metadata)
{
    Ref<Font> font = CreateRef<Font>(metadata, LoadFont(metadata.Path.String().c_str()));
    return font;
}

template <> bool Export(const Ref<Font> &font)
{
    if (!font->IsValid())
    {
        return false;
    }

    ::UnloadFont(*font);
    return true;
}

} // namespace Lumen::AssetImporter