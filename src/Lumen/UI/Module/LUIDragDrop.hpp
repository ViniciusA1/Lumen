#pragma once

#include "Lumen/UI/Module/LUIStructures.hpp"

#include <string>

namespace Lumen::LUI
{

class DragDropPayload;

bool BeginDragDropSource(DragDropFlags flags = DragDropFlags::None);
void EndDragDropSource();

bool BeginDragDropTarget();
void EndDragDropTarget();

DragDropPayload AcceptDragDropPayload(const std::string &type,
                                      DragDropFlags flags = DragDropFlags::None);

bool SetDragDropPayload(const std::string &type, const void *data, size_t size,
                        CondFlags flags = CondFlags::None);

} // namespace Lumen::LUI

struct ImGuiPayload;

namespace Lumen::LUI
{

class DragDropPayload
{
public:
    DragDropPayload() = default;
    DragDropPayload(const ::ImGuiPayload *payload);

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

template <typename T> const T *DragDropPayload::As() const
{
    return reinterpret_cast<const T *>(GetData());
}

} // namespace Lumen::LUI