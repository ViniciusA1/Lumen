#include "Lumen/Graphics/Shader.hpp"
#include "raylib.h"

namespace Lumen
{

Shader::Shader(const AssetMetadata &metadata, const ::Shader &shader)
    : Asset(metadata), m_Instance(CreateScope<::Shader>(shader))
{
}

Shader::~Shader()
{
    UnloadShader(*m_Instance);
}

bool Shader::IsValid() const
{
    return ::IsShaderReady(*m_Instance);
}

Shader::operator ::Shader() const
{
    return *m_Instance;
}

} // namespace Lumen