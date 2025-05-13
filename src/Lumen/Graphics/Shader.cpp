#include "Lumen/Graphics/Shader.hpp"

#include "raylib.h"

namespace Lumen
{

Shader::Shader(const AssetHandle &handle, const ::Shader &shader)
    : Asset(handle), m_Shader(new ::Shader(shader))
{
}

Shader::Shader(const AssetHandle &handle, ::Shader *shader)
    : Asset(handle), m_Shader(shader)
{
}

Shader::Shader(const ::Shader &shader) : Shader({}, shader)
{
}

Shader::Shader(::Shader *shader) : Shader({}, shader)
{
}

bool Shader::IsValid() const
{
    return m_Shader && ::IsShaderValid(*m_Shader);
}

int *Shader::GetLocations() const
{
    return m_Shader->locs;
}

unsigned int Shader::GetRendererID() const
{
    return m_Shader->id;
}

AssetType Shader::GetType() const
{
    return AssetType::Shader;
}

void Shader::SetValue(int locIndex, const void *value, ShaderUniformType type)
{
    ::SetShaderValue(*m_Shader, locIndex, value, static_cast<int>(type));
}

void Shader::SetValue(int locIndex, const Matrix4 &matrix)
{
    ::SetShaderValueMatrix(*m_Shader, locIndex, matrix);
}

void Shader::SetValue(int locIndex, const Texture2D &texture)
{
    ::SetShaderValueTexture(*m_Shader, locIndex, texture);
}

void Shader::SetValue(int locIndex, const Vector2 &vec)
{
    ::SetShaderValueV(*m_Shader, locIndex, &vec, SHADER_UNIFORM_VEC2, 2);
}

void Shader::SetValue(int locIndex, const Vector3 &vec)
{
    ::SetShaderValueV(*m_Shader, locIndex, &vec, SHADER_UNIFORM_VEC3, 3);
}

void Shader::SetValue(int locIndex, const Vector4 &vec)
{
    ::SetShaderValueV(*m_Shader, locIndex, &vec, SHADER_UNIFORM_VEC4, 4);
}

Shader::operator ::Shader() const
{
    return *m_Shader;
}

Shader::operator ::Shader *() const
{
    return m_Shader;
}

} // namespace Lumen