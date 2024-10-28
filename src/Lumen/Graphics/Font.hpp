#pragma once

#include "Lumen/Asset/Asset.hpp"
#include "Lumen/Core/Memory.hpp"

struct Font;

namespace Lumen
{

class Font : public Asset
{
public:
    Font(const AssetMetadata &metadata, const ::Font &font);
    ~Font() override;

    [[nodiscard]] bool IsValid() const override;
    operator ::Font() const;

private:
    Scope<::Font> m_Instance;
};

} // namespace Lumen