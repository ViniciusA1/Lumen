#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Graphics/Model.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> ModelImporter::Import(const AssetMetadata &metadata)
{
    int animationCount = 0;

    ::Model rayModel = ::LoadModel(metadata.Path.String().c_str());
    ::ModelAnimation *animations =
        ::LoadModelAnimations(metadata.Path.String().c_str(), &animationCount);

    Model model = {
        metadata.Handle,
        rayModel,
        animations,
        animationCount,
    };

    return CreateScope<Model>(model);
}

void ModelImporter::Export(AssetEntry &entry)
{
    auto *model = entry.GetAsset<Model>();
    if (!model->IsValid())
        return;

    ::Model *rayModel = *model;
    ::UnloadModel(*rayModel);
    delete rayModel;
}

} // namespace Lumen