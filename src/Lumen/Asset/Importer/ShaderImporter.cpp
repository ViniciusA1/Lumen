#include "Lumen/Asset/Importer/ShaderImporter.hpp"
#include "Lumen/Graphics/Shader.hpp"

#include "raylib.h"

namespace Lumen
{

Scope<Asset> ShaderImporter::Import(const AssetMetadata &metadata)
{
    const std::string shaderName = metadata.Path.Stem().String();
    const Path vertPath = metadata.Path / (shaderName + ".vert").c_str();
    const Path fragPath = metadata.Path / (shaderName + ".frag").c_str();

    Shader shader = {
        metadata.Handle,
        LoadShader(vertPath.String().c_str(), fragPath.String().c_str()),
    };

    return CreateScope<Shader>(shader);
}

void ShaderImporter::Export(AssetEntry &entry)
{
    auto *shader = entry.GetAsset<Shader>();
    if (!shader->IsValid())
        return;

    ::Shader *rayShader = *shader;
    ::UnloadShader(*rayShader);
    delete rayShader;
}

} // namespace Lumen