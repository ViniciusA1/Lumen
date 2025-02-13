#pragma once

#include "Lumen/Asset/AssetType.hpp"
#include "Lumen/Core/UUID.hpp"

namespace Lumen
{

class Asset
{
public:
    Asset() = default;
    Asset(UUID uuid);

    [[nodiscard]] virtual bool IsValid() const = 0;

    [[nodiscard]] UUID GetID() const;
    [[nodiscard]] virtual AssetType GetType() const = 0;

private:
    UUID m_ID;
};

} // namespace Lumen