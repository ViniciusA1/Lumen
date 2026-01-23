#include "Lumen/Serialization/SerializationResult.hpp"

namespace Lumen
{

bool SerializationResult::IsOk() const
{
    return !HasErrors();
}

bool SerializationResult::IsEmpty() const
{
    return m_Messages.empty();
}

bool SerializationResult::HasErrors() const
{
    for (const auto &m : m_Messages)
        if (m.Status == SerializationStatus::Error)
            return true;

    return false;
}

bool SerializationResult::HasWarnings() const
{
    for (const auto &m : m_Messages)
        if (m.Status == SerializationStatus::Warning)
            return true;

    return false;
}

const std::vector<SerializationMessage> &SerializationResult::GetMessages() const
{
    return m_Messages;
}

void SerializationResult::AddInfo(std::string text, Path path)
{
    m_Messages.push_back(SerializationMessage{
        SerializationStatus::Info,
        std::move(text),
        std::move(path),
    });
}

void SerializationResult::AddWarning(std::string text, Path path)
{
    m_Messages.push_back(SerializationMessage{
        SerializationStatus::Warning,
        std::move(text),
        std::move(path),
    });
}

void SerializationResult::AddError(std::string text, Path path)
{
    m_Messages.push_back(SerializationMessage{
        SerializationStatus::Error,
        std::move(text),
        std::move(path),
    });
}

void SerializationResult::Clear()
{
    m_Messages.clear();
}

} // namespace Lumen