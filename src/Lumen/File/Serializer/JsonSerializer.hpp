#pragma once

#include "Lumen/File/Path.hpp"

#include "nlohmann/json.hpp"

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
    class Iterator
    {
    public:
        Iterator(nlohmann::json::iterator it);

        Iterator &operator++();
        Iterator operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        Json operator*() const;

    private:
        nlohmann::json::iterator m_Iterator;
    };

    class ConstIterator
    {
    public:
        ConstIterator(nlohmann::json::const_iterator it);
        ConstIterator &operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator &other) const;
        bool operator!=(const ConstIterator &other) const;
        Json operator*() const;

    private:
        nlohmann::json::const_iterator m_Iterator;
    };

    class Proxy
    {
    public:
        Proxy(nlohmann::json &ref) : m_Ref(ref) {}

        template <typename T> Proxy &operator<<(const T &value)
        {
            m_Ref = JsonSerializer::Serialize(value).m_Data;
            return *this;
        }

        Proxy operator[](const std::string &key) { return m_Ref[key]; }

        Iterator begin() { return m_Ref.begin(); }
        Iterator end() { return m_Ref.end(); }

        operator Json() const { return m_Ref; }

    private:
        nlohmann::json &m_Ref;
    };

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

    Iterator begin() { return m_Data.begin(); }
    Iterator end() { return m_Data.end(); }
    [[nodiscard]] ConstIterator begin() const { return m_Data.begin(); }
    [[nodiscard]] ConstIterator end() const { return m_Data.end(); }

    template <typename T> T Get() const { return m_Data.get<T>(); }

    template <typename T> T GetOrDefault(const T &defaultValue) const
    {
        if (!IsNull())
        {
            return m_Data.get<T>();
        }

        return defaultValue;
    }

    template <typename T> void PushBack(const T &value) { m_Data.push_back(value); }

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
    bool ToFile(const Path &path, int indent = 4);

    template <typename T> Json &operator<<(const T &obj)
    {
        Json serializedData = JsonSerializer::Serialize(obj);

        if (m_Data.is_object())
        {
            for (const auto &[key, value] : serializedData.m_Data.items())
            {
                m_Data[key] = value;
            }
        }
        else if (m_Data.is_array())
        {
            for (const auto &item : serializedData.m_Data)
            {
                m_Data.push_back(item);
            }
        }
        else
        {
            m_Data = serializedData.m_Data;
        }

        return *this;
    }

    template <typename T> const Json &operator>>(T &obj) const
    {
        if (!IsNull())
            JsonSerializer::Deserialize(*this, obj);
        return *this;
    }

    Proxy operator[](const std::string &key) { return m_Data[key]; }
    const Json operator[](const std::string &key) const
    {
        if (m_Data.contains(key))
            return m_Data[key];

        return {};
    }
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
    return json;
}

template <typename T> void Deserialize(const Json &json, T &obj)
{
    obj = json.GetOrDefault<T>(obj);
}

} // namespace Lumen::JsonSerializer

#include "Lumen/File/Serializer/Conversions/Conversions.hpp"