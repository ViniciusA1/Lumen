#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Model;

namespace Lumen
{

class Model : public Asset
{
public:
    Model(const AssetMetadata &metadata, const ::Model &model);
    ~Model() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Model() const;

private:
    Scope<::Model> m_Instance;
};

} // namespace Lumen