#include "Lumen/Input/InputValue.hpp"

namespace Lumen
{

InputValue::InputValue() : m_Type(InputValueType::None), m_Data(false)
{
}

InputValue::InputValue(bool value) : m_Type(InputValueType::Bool), m_Data(value)
{
}

InputValue::InputValue(float value) : m_Type(InputValueType::Float), m_Data(value)
{
}

InputValue::InputValue(Vector2 value) : m_Type(InputValueType::Vector2), m_Data(value)
{
}

InputValue::InputValue(Vector3 value) : m_Type(InputValueType::Vector3), m_Data(value)
{
}

bool InputValue::IsEmpty() const
{
    return m_Type == InputValueType::None;
}

InputValueType InputValue::GetType()
{
    return m_Type;
}

bool InputValue::AsBool() const
{
    if (m_Type != InputValueType::Bool)
        throw std::bad_variant_access();

    return std::get<bool>(m_Data);
}

float InputValue::AsFloat() const
{
    if (m_Type != InputValueType::Float)
        throw std::bad_variant_access();

    return std::get<float>(m_Data);
}

Vector2 InputValue::AsVector2() const
{
    if (m_Type != InputValueType::Vector2)
        throw std::bad_variant_access();

    return std::get<Vector2>(m_Data);
}

Vector3 InputValue::AsVector3() const
{
    if (m_Type != InputValueType::Vector3)
        throw std::bad_variant_access();

    return std::get<Vector3>(m_Data);
}

} // namespace Lumen