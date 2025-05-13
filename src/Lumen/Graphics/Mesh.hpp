#pragma once

#include "Lumen/Asset/Asset.hpp"

struct Mesh;

namespace Lumen
{

class Mesh : public Asset
{
public:
    Mesh() = default;
    Mesh(const AssetHandle &handle, const ::Mesh &mesh);
    Mesh(const AssetHandle &handle, ::Mesh *mesh);
    Mesh(const ::Mesh &mesh);
    Mesh(::Mesh *mesh);

    [[nodiscard]] bool IsValid() const override;

    [[nodiscard]] AssetType GetType() const final;

    operator ::Mesh() const;
    operator ::Mesh *() const;

private:
    ::Mesh *m_Mesh = nullptr;
};

} // namespace Lumen