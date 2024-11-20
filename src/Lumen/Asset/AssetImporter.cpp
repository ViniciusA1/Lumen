#include "Lumen/Asset/AssetImporter.hpp"

#include "Lumen/Asset/Importer/FontImporter.hpp"
#include "Lumen/Asset/Importer/ImageImporter.hpp"
#include "Lumen/Asset/Importer/MeshImporter.hpp"
#include "Lumen/Asset/Importer/ModelImporter.hpp"
#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Asset/Importer/TextureImporter.hpp"

#include "Lumen/Graphics/Font.hpp"
#include "Lumen/Graphics/Image.hpp"
#include "Lumen/Graphics/Mesh.hpp"
#include "Lumen/Graphics/Model.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "Lumen/Graphics/Texture.hpp"

#include <functional>
#include <unordered_map>

namespace Lumen
{

static std::unordered_map<std::type_index,
                          std::function<Ref<Asset>(const AssetMetadata &)>>
    s_ImportFunc = {{typeid(Font), FontImporter::ImportFont},
                    {typeid(Image), ImageImporter::ImportImage},
                    {typeid(Mesh), MeshImporter::ImportMesh},
                    {typeid(Model), ModelImporter::ImportModel},
                    {typeid(Shader), ShaderImporter::ImportShader},
                    {typeid(Texture2D), TextureImporter::ImportTexture}};

Ref<Asset> AssetImporter::ImportAsset(std::type_index type, const AssetMetadata &metadata)
{
    Ref<Asset> assetLoaded = s_ImportFunc[type](metadata);
    if (assetLoaded->IsValid() == false)
    {
        return nullptr;
    }
    return assetLoaded;
}

} // namespace Lumen