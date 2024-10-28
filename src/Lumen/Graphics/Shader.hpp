#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Shader;

namespace Lumen
{

class Shader : public Asset
{
public:
    Shader(const AssetMetadata &metadata, const ::Shader &shader);
    ~Shader() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Shader() const;

private:
    Scope<::Shader> m_Instance;
};

} // namespace Lumen