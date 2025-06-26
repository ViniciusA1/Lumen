#include "Lumen/UI/LUIPayload.hpp"

#include "imgui.h"

namespace Lumen
{

LUIPayload::LUIPayload(const ::ImGuiPayload *payload) : m_Payload(payload)
{
}

bool LUIPayload::IsType(const std::string &type) const
{
    return m_Payload && strcmp(m_Payload->DataType, type.c_str()) == 0;
}

bool LUIPayload::IsValid() const
{
    return m_Payload && m_Payload->Data != nullptr && m_Payload->DataSize > 0;
}

const void *LUIPayload::GetData() const
{
    return m_Payload ? m_Payload->Data : nullptr;
}

int LUIPayload::GetDataSize() const
{
    return m_Payload ? m_Payload->DataSize : 0;
}

const char *LUIPayload::GetType() const
{
    return m_Payload ? m_Payload->DataType : "";
}

LUIPayload::operator const ImGuiPayload *() const
{
    return m_Payload;
}

} // namespace Lumen