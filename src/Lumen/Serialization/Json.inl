#pragma once

#include "Lumen/Serialization/Conversion/Conversion.hpp"
#include "Lumen/Serialization/Json.hpp"

namespace Lumen
{

template <typename T> T Json::Get() const
{
    return m_Data.get<T>();
}

template <typename T> T Json::GetOrDefault(const T &defaultValue) const
{
    if (!IsNull())
        return m_Data.get<T>();

    return defaultValue;
}

template <typename T> void Json::PushBack(const T &value)
{
    if constexpr (std::is_same_v<T, Json>)
        m_Data.push_back(value.m_Data);
    else
        m_Data.push_back(value);
}

template <typename T> void Json::Set(const std::string &key, const T &value)
{
    if (!IsObject())
        return;

    m_Data[key] = value;
}

template <typename T> void Json::Set(size_t index, const T &value)
{
    if (!IsArray() || index >= GetSize())
        return;

    m_Data[index] = value;
}

template <typename T> Json &Json::operator<<(const T &obj)
{
    Json serializedData = JsonSerializer::Serialize(obj);

    if (m_Data.is_object())
    {
        for (const auto &[key, value] : serializedData.m_Data.items())
            m_Data[key] = value;
    }
    else if (m_Data.is_array())
    {
        for (const auto &item : serializedData.m_Data)
            m_Data.push_back(item);
    }
    else
    {
        m_Data = serializedData.m_Data;
    }

    return *this;
}

template <typename T> const Json &Json::operator>>(T &obj) const
{
    if (!IsNull())
        JsonSerializer::Deserialize(*this, obj);

    return *this;
}

template <typename T> SerializationResult Json::FromFile(const Path &path, T &obj)
{
    SerializationResult result;
    Json json;

    SerializationResult loadResult = FromFileInternal(path, json);
    if (loadResult.HasErrors())
        return loadResult;

    json >> obj;

    if (json.IsNull())
        result.AddError("JSON data is null", path);

    return result;
}

template <typename T> SerializationResult Json::ToFile(const Path &path, const T &obj)
{
    Json json;
    json << obj;
    return json.ToFile(path);
}

template <typename T> JsonProxy &JsonProxy::operator<<(const T &value)
{
    m_Ref = JsonSerializer::Serialize(value).m_Data;
    return *this;
}

} // namespace Lumen