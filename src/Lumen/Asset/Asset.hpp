#pragma once

#include "Lumen/Asset/AssetMetadata.hpp"

namespace Lumen
{

class Asset
{
public:
    Asset(AssetMetadata metadata);
    virtual ~Asset() = default;

    AssetMetadata &GetMetadata() { return m_Metadata; }
    [[nodiscard]] virtual bool IsValid() const = 0;

private:
    AssetMetadata m_Metadata;
};

} // namespace Lumen