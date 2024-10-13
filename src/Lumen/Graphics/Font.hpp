#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Font;

namespace Lumen
{

class Font : public Asset
{
public:
    Font(const AssetMetadata &metadata, ::Font font);
    ~Font() override;

private:
    Scope<::Font> m_Font;
};

} // namespace Lumen