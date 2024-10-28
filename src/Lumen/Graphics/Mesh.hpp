#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Mesh;

namespace Lumen
{

class Mesh : public Asset
{
public:
    Mesh(const AssetMetadata &metadata, const ::Mesh &mesh);
    ~Mesh() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Mesh() const;

private:
    Scope<::Mesh> m_Instance;
};

} // namespace Lumen