#pragma once

#include "Lumen/Asset/AssetHandle.hpp"
#include "Lumen/Asset/AssetType.hpp"

namespace Lumen
{

class Asset
{
public:
    Asset() = default;
    Asset(const AssetHandle &handle);

    [[nodiscard]] virtual bool IsValid() const = 0;

    [[nodiscard]] AssetHandle GetHandle() const;
    [[nodiscard]] virtual AssetType GetType() const = 0;

private:
    AssetHandle m_Handle;
};

} // namespace Lumen