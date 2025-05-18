#include "Lumen/Asset/Importer/ShaderImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Shader Import(const AssetHandle &handle, const AssetMetadata &metadata)
{
    const std::string shaderName = metadata.Path.Stem().String();
    const Path vertPath = metadata.Path / (shaderName + ".vert").c_str();
    const Path fragPath = metadata.Path / (shaderName + ".frag").c_str();

    Shader shader = {
        handle,
        LoadShader(vertPath.String().c_str(), fragPath.String().c_str()),
    };

    return shader;
}

template <> bool Export(const Shader &shader)
{
    if (!shader.IsValid())
        return false;

    ::Shader *rayShader = shader;
    ::UnloadShader(*rayShader);
    delete rayShader;
    return true;
}

} // namespace Lumen::AssetImporter