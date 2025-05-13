#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Graphics/Texture.hpp"
#include "Lumen/Math/Matrix4.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"
#include "Lumen/Math/Vector4.hpp"

struct Shader;

namespace Lumen
{

enum class ShaderUniformType
{
    Float,
    Vec2,
    Vec3,
    Vec4,
    Int,
    IVec2,
    IVec3,
    IVec4,
    Sampler2D
};

enum class ShaderAttributeType
{
    Float,
    Vec2,
    Vec3,
    Vec4
};

class Shader : public Asset
{
public:
    Shader() = default;
    Shader(const AssetHandle &handle, const ::Shader &shader);
    Shader(const AssetHandle &handle, ::Shader *shader);
    Shader(const ::Shader &shader);
    Shader(::Shader *shader);

    [[nodiscard]] bool IsValid() const final;

    [[nodiscard]] int *GetLocations() const;
    [[nodiscard]] unsigned int GetRendererID() const;
    [[nodiscard]] AssetType GetType() const final;

    void SetValue(int locIndex, const void *value, ShaderUniformType type);
    void SetValue(int locIndex, const Matrix4 &matrix);
    void SetValue(int locIndex, const Texture2D &texture);
    void SetValue(int locIndex, const Vector2 &vec);
    void SetValue(int locIndex, const Vector3 &vec);
    void SetValue(int locIndex, const Vector4 &vec);

    operator ::Shader() const;
    operator ::Shader *() const;

private:
    ::Shader *m_Shader = nullptr;
};

} // namespace Lumen