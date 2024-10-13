#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Shader;

namespace Lumen
{

class Shader : public Asset
{
public:
    Shader(const AssetMetadata &metadata, ::Shader shader);
    ~Shader() override;

private:
    Scope<::Shader> m_Shader;
};

} // namespace Lumen