#include "Lumen/Graphics/Shader.hpp"
#include "raylib.h"

namespace Lumen
{

Shader::Shader(const AssetMetadata &metadata, const ::Shader &shader)
    : Asset(metadata), m_RendererID(shader.id), m_Locs(shader.locs)
{
}

Shader::Shader(const ::Shader &shader) : Shader({UUID(), "", {""}}, shader)
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

Shader::operator ::Shader() const
{
    return {m_RendererID, m_Locs};
}

} // namespace Lumen