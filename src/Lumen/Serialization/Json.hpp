#pragma once

#include "Lumen/File/Path.hpp"
#include "Lumen/Serialization/SerializationResult.hpp"

#include "nlohmann/json.hpp"

namespace Lumen
{

class JsonIterator;
class JsonConstIterator;
class JsonProxy;

class Json
{
public:
    Json() = default;
    Json(nlohmann::json json);
    Json(std::initializer_list<nlohmann::json::value_type> initList);

    [[nodiscard]] bool IsArray() const;
    [[nodiscard]] bool IsBoolean() const;
    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsNumber() const;
    [[nodiscard]] bool IsObject() const;
    [[nodiscard]] bool IsString() const;

    [[nodiscard]] bool Contains(const std::string &key) const;

    template <typename T> T Get() const;
    template <typename T> T GetOrDefault(const T &defaultValue) const;
    [[nodiscard]] std::vector<std::pair<std::string, Json>> GetKeyValues() const;
    [[nodiscard]] std::vector<std::string> GetKeys() const;
    [[nodiscard]] std::size_t GetSize() const;
    [[nodiscard]] std::vector<Json> GetValues() const;

    JsonIterator begin();
    JsonIterator end();
    [[nodiscard]] JsonConstIterator begin() const;
    [[nodiscard]] JsonConstIterator end() const;

    template <typename T> void PushBack(const T &value);
    template <typename T> void Set(const std::string &key, const T &value);
    template <typename T> void Set(size_t index, const T &value);

    void Clear();
    void Erase(const std::string &key);

    template <typename T> Json &operator<<(const T &obj);
    template <typename T> const Json &operator>>(T &obj) const;

    JsonProxy operator[](const std::string &key);
    const Json operator[](const std::string &key) const;
    Json operator[](std::size_t index);
    const Json operator[](std::size_t index) const;
    operator nlohmann::json() const;

    template <typename T> static SerializationResult FromFile(const Path &path, T &obj);
    [[nodiscard]] SerializationResult ToFile(const Path &path) const;
    template <typename T>
    static SerializationResult ToFile(const Path &path, const T &obj);

private:
    static SerializationResult FromFileInternal(const Path &path, Json &out);

private:
    nlohmann::json m_Data;

    friend class JsonProxy;
};

class JsonIterator
{
public:
    JsonIterator(nlohmann::json::iterator it);

    JsonIterator &operator++();
    JsonIterator operator++(int);
    bool operator==(const JsonIterator &other) const;
    bool operator!=(const JsonIterator &other) const;
    Json operator*() const;

private:
    nlohmann::json::iterator m_Iterator;
};

class JsonConstIterator
{
public:
    JsonConstIterator(nlohmann::json::const_iterator it);
    JsonConstIterator &operator++();
    JsonConstIterator operator++(int);
    bool operator==(const JsonConstIterator &other) const;
    bool operator!=(const JsonConstIterator &other) const;
    Json operator*() const;

private:
    nlohmann::json::const_iterator m_Iterator;
};

class JsonProxy
{
public:
    JsonProxy(nlohmann::json &ref);

    template <typename T> JsonProxy &operator<<(const T &value);

    JsonProxy operator[](const std::string &key);

    JsonIterator begin();
    JsonIterator end();

    operator Json() const;

private:
    nlohmann::json &m_Ref;
};

} // namespace Lumen

namespace Lumen::JsonSerializer
{

template <typename T> Json Serialize(const T &obj)
{
    if constexpr (std::is_same_v<T, Json>)
        return obj;

    nlohmann::json json;
    json = obj;
    return json;
}

template <typename T> void Deserialize(const Json &json, T &obj)
{
    if constexpr (std::is_same_v<T, Json>)
    {
        obj = json;
        return;
    }

    obj = json.GetOrDefault<T>(obj);
}

} // namespace Lumen::JsonSerializer

#include "Lumen/Serialization/Json.inl"