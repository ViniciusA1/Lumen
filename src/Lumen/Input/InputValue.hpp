#pragma once

#include "Lumen/Input/InputValueType.hpp"
#include "Lumen/Math/Vector2.hpp"
#include "Lumen/Math/Vector3.hpp"

#include <variant>

namespace Lumen
{

class InputValue
{
public:
    InputValue();
    InputValue(bool value);
    InputValue(float value);
    InputValue(Vector2 value);
    InputValue(Vector3 value);

    [[nodiscard]] bool IsEmpty() const;

    InputValueType GetType();

    [[nodiscard]] bool AsBool() const;
    [[nodiscard]] float AsFloat() const;
    [[nodiscard]] Vector2 AsVector2() const;
    [[nodiscard]] Vector3 AsVector3() const;

private:
    InputValueType m_Type;
    std::variant<bool, float, Vector2, Vector3> m_Data;
};

} // namespace Lumen