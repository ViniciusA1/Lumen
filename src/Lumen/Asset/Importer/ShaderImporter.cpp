#include "Lumen/Asset/Importer/ShaderImporter.hpp"

#include "raylib.h"

namespace Lumen::AssetImporter
{

template <> Ref<Shader> Import(UUID uuid, const AssetMetadata &metadata)
{
    Ref<Shader> shader = CreateRef<Shader>(
        uuid, LoadShader((metadata.Path / "vert.glsl").String().c_str(),
                         (metadata.Path / "frag.glsl").String().c_str()));
    return shader;
}

template <> bool Export(const Ref<Shader> &shader)
{
    if (!shader->IsValid())
    {
        return false;
    }

    ::UnloadShader(*shader);
    return true;
}

} // namespace Lumen::AssetImporter