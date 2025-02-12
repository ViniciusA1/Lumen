#include "Lumen/Asset/Importer/ModelImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Model> Import(const AssetMetadata &metadata)
{
    Ref<Model> model =
        CreateRef<Model>(metadata, LoadModel(metadata.Path.String().c_str()));
    return model;
}

template <> bool Export(const Ref<Model> &model)
{
    if (!model->IsValid())
    {
        return false;
    }

    ::UnloadModel(*model);
    return true;
}

} // namespace Lumen::AssetImporter