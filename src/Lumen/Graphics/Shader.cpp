#include "Lumen/Graphics/Shader.hpp"
#include "raylib.h"

namespace Lumen
{

Shader::Shader(UUID uuid, const ::Shader &shader)
    : Asset(uuid), m_RendererID(shader.id), m_Locs(shader.locs)
{
}

Shader::Shader(const ::Shader &shader) : Shader(UUID(), shader)
{
}

bool Shader::IsValid() const
{
    return ::IsShaderReady(*this);
}

int *Shader::GetLocations() const
{
    return m_Locs;
}

unsigned int Shader::GetRendererID() const
{
    return m_RendererID;
}

AssetType Shader::GetType() const
{
    return AssetType::Shader;
}

Shader::operator ::Shader() const
{
    return {m_RendererID, m_Locs};
}

} // namespace Lumen