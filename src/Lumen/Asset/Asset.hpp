#pragma once

#include "Lumen/Core/UUID.hpp"
#include "Lumen/File/Path.hpp"
#include <string>

namespace Lumen
{

struct AssetMetadata
{
    UUID ID;
    std::string Name;
    Path Path;

    AssetMetadata(UUID id, std::string name, class Path path)
        : ID(id), Name(std::move(name)), Path(std::move(path))
    {
    }

    AssetMetadata(std::string name, class Path path)
        : AssetMetadata(UUID(), std::move(name), std::move(path))
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