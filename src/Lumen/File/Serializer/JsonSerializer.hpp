#pragma once

#include "Lumen/File/Path.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"

namespace Lumen
{

class Json;

namespace JsonSerializer
{

template <typename T> Json Serialize(const T &obj);
template <typename T> void Deserialize(const Json &j, T &obj);

} // namespace JsonSerializer

class Json
{
public:
    Json() = default;
    Json(nlohmann::json j);
    Json(std::initializer_list<nlohmann::json::value_type> initList);

    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsObject() const;
    [[nodiscard]] bool IsArray() const;
    [[nodiscard]] bool IsString() const;
    [[nodiscard]] bool IsNumber() const;
    [[nodiscard]] bool IsBoolean() const;

    [[nodiscard]] bool Contains(const std::string &key) const;
    void Clear();
    void Erase(const std::string &key);
    [[nodiscard]] std::vector<std::string> Keys() const;
    [[nodiscard]] std::size_t Size() const;
    [[nodiscard]] std::vector<Json> Values() const;

    template <typename T> T Get() const { return m_Data.get<T>(); }

    template <typename T> T GetOrDefault(const T &defaultValue) const
    {
        if (!IsNull())
        {
            return m_Data.get<T>();
        }

        return defaultValue;
    }

    template <typename T> void PushBack(const T &value)
    {
        if (!IsArray())
        {
            return;
        }

        m_Data.push_back(value);
    }

    template <typename T> void Set(const std::string &key, const T &value)
    {
        if (!IsObject())
        {
            return;
        }

        m_Data[key] = value;
    }

    template <typename T> void Set(size_t index, const T &value)
    {
        if (!IsArray() || index >= Size())
        {
            return;
        }

        m_Data[index] = value;
    }

    static Json FromFile(const Path &path);
    bool ToFile(const Path &path, int indent = -1);

    template <typename T> Json &operator<<(const T &obj)
    {
        *this = JsonSerializer::Serialize(obj);
        return *this;
    }

    template <typename T> const Json &operator>>(T &obj) const
    {
        JsonSerializer::Deserialize(*this, obj);
        return *this;
    }

    Json operator[](const std::string &key) { return m_Data[key]; }
    const Json operator[](const std::string &key) const { return m_Data[key]; }
    Json operator[](std::size_t index) { return m_Data[index]; }
    const Json operator[](std::size_t index) const { return m_Data[index]; }
    operator nlohmann::json() const;

private:
    nlohmann::json m_Data;
};

} // namespace Lumen

namespace Lumen::JsonSerializer
{

template <typename T> Json Serialize(const T &obj)
{
    nlohmann::json json;
    json = obj;
    return {json};
}

template <typename T> void Deserialize(const Json &json, T &obj)
{
    obj = json.GetOrDefault<T>(obj);
}

} // namespace Lumen::JsonSerializer

#include "Lumen/File/Serializer/Conversions/AssetConversion.hpp"
#include "Lumen/File/Serializer/Conversions/CoreConversion.hpp"
#include "Lumen/File/Serializer/Conversions/FileConversion.hpp"
#include "Lumen/File/Serializer/Conversions/GraphicsConversion.hpp"
#include "Lumen/File/Serializer/Conversions/MathConversion.hpp"
#include "Lumen/File/Serializer/Conversions/ProjectConversion.hpp"
#include "Lumen/File/Serializer/Conversions/SceneConversion.hpp"
#include "Lumen/File/Serializer/Conversions/UIConversion.hpp"