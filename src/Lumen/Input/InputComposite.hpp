#pragma once

#include "Lumen/Input/InputBinding.hpp"

#include <string>
#include <vector>

namespace Lumen
{

class InputComposite
{
public:
    [[nodiscard]] const std::vector<InputBinding> &GetBindings() const;
    [[nodiscard]] std::vector<InputBinding> &GetBindings();
    [[nodiscard]] std::string GetName() const;

    bool operator==(const InputComposite &other) const;

private:
    std::string m_Name;
    std::vector<InputBinding> m_Bindings;
};

} // namespace Lumen