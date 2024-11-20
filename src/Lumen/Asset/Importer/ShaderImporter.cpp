#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Graphics/Shader.hpp"
#include "raylib.h"

namespace Lumen
{

Ref<Asset> ShaderImporter::ImportShader(const AssetMetadata &metadata)
{
    Ref<Shader> shader = CreateRef<Shader>(
        metadata, LoadShader((metadata.Path / "vert.glsl").String().c_str(),
                             (metadata.Path / "frag.glsl").String().c_str()));
    return std::static_pointer_cast<Asset>(shader);
}

} // namespace Lumen