#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Graphics/Model.hpp"
#include "raylib.h"

namespace Lumen
{

Ref<Asset> ModelImporter::ImportModel(const AssetMetadata &metadata)
{
    Ref<Model> model =
        CreateRef<Model>(metadata, LoadModel(metadata.Path.String().c_str()));
    return std::static_pointer_cast<Asset>(model);
}

} // namespace Lumen