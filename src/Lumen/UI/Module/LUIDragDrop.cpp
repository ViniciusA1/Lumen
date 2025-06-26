#include "Lumen/UI/Module/LUIDragDrop.hpp"

#include "imgui.h"

namespace Lumen::LUI
{

bool BeginDragDropSource(DragDropFlags flags)
{
    return ImGui::BeginDragDropSource(static_cast<int>(flags));
}

void EndDragDropSource()
{
    ImGui::EndDragDropSource();
}

bool BeginDragDropTarget()
{
    return ImGui::BeginDragDropTarget();
}

void EndDragDropTarget()
{
    ImGui::EndDragDropTarget();
}

DragDropPayload AcceptDragDropPayload(const std::string &type, DragDropFlags flags)
{
    return ImGui::AcceptDragDropPayload(type.c_str(), static_cast<int>(flags));
}

bool SetDragDropPayload(const std::string &type, const void *data, size_t size,
                        CondFlags flags)
{
    return ImGui::SetDragDropPayload(type.c_str(), data, size, static_cast<int>(flags));
}

} // namespace Lumen::LUI

namespace Lumen::LUI
{

DragDropPayload::DragDropPayload(const ::ImGuiPayload *payload) : m_Payload(payload)
{
}

bool DragDropPayload::IsType(const std::string &type) const
{
    return m_Payload && strcmp(m_Payload->DataType, type.c_str()) == 0;
}

bool DragDropPayload::IsValid() const
{
    return m_Payload && m_Payload->Data != nullptr && m_Payload->DataSize > 0;
}

const void *DragDropPayload::GetData() const
{
    return m_Payload ? m_Payload->Data : nullptr;
}

int DragDropPayload::GetDataSize() const
{
    return m_Payload ? m_Payload->DataSize : 0;
}

const char *DragDropPayload::GetType() const
{
    return m_Payload ? m_Payload->DataType : "";
}

DragDropPayload::operator const ImGuiPayload *() const
{
    return m_Payload;
}

} // namespace Lumen::LUI