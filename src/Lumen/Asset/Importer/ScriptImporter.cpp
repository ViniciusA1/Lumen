#include "Lumen/Asset/Importer/ScriptImporter.hpp"

namespace Lumen
{

Scope<Asset> ScriptImporter::Import(const AssetMetadata &metadata)
{
    return nullptr;
}

void ScriptImporter::Export(AssetEntry &entry)
{
    // auto *script = entry.GetAsset<Script>();
}

} // namespace Lumen