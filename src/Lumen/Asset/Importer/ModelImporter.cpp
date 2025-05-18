#include "Lumen/Asset/Importer/ModelImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Model Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    int animationCount = 0;

    ::Model rayModel = ::LoadModel(metadata.Path.String().c_str());
    ::ModelAnimation *animations =
        ::LoadModelAnimations(metadata.Path.String().c_str(), &animationCount);

    Model model = {handle, rayModel, animations, animationCount};
    return model;
}

template <> bool Export(const Model &model)
{
    if (!model.IsValid())
        return false;

    ::Model *rayModel = model;
    ::UnloadModel(*rayModel);
    delete rayModel;
    return true;
}

} // namespace Lumen::AssetImporter