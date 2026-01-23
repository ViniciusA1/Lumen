#pragma once

#include "Lumen/Serialization/SerializationMessage.hpp"

#include <vector>

namespace Lumen
{

class SerializationResult
{
public:
    SerializationResult() = default;

    [[nodiscard]] bool IsOk() const;
    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] bool HasErrors() const;
    [[nodiscard]] bool HasWarnings() const;

    [[nodiscard]] const std::vector<SerializationMessage> &GetMessages() const;

    void AddInfo(std::string text, Path path);
    void AddWarning(std::string text, Path path);
    void AddError(std::string text, Path path);

    void Clear();

private:
    std::vector<SerializationMessage> m_Messages;
};

} // namespace Lumen