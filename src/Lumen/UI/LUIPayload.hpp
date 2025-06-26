#pragma once

#include <string>

struct ImGuiPayload;

namespace Lumen
{

class LUIPayload
{
public:
    LUIPayload() = default;
    LUIPayload(const ::ImGuiPayload *payload);

    [[nodiscard]] bool IsType(const std::string &type) const;
    [[nodiscard]] bool IsValid() const;

    [[nodiscard]] const void *GetData() const;
    [[nodiscard]] int GetDataSize() const;
    [[nodiscard]] const char *GetType() const;

    template <typename T> const T *As() const;

    operator const ImGuiPayload *() const;

private:
    const ::ImGuiPayload *m_Payload = nullptr;
};

template <typename T> const T *LUIPayload::As() const
{
    return reinterpret_cast<const T *>(GetData());
}

} // namespace Lumen