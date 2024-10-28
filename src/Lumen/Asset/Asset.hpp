#pragma once

#include "Lumen/Core/UUID.hpp"
#include <string>

namespace Lumen
{

struct AssetMetadata
{
    UUID ID;
    std::string Name;
    std::string Path;

    AssetMetadata(UUID id, std::string name, std::string path)
        : ID(id), Name(std::move(name)), Path(std::move(path))
    {
    }
};

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