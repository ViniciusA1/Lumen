#pragma once

#include "Lumen/File/Path.hpp"

#include "nlohmann/json.hpp"

namespace Lumen
{

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

        template <typename T> Proxy &operator<<(const T &value);

        Proxy operator[](const std::string &key);

        Iterator begin();
        Iterator end();

        operator Json() const;

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

    Iterator begin();
    Iterator end();
    [[nodiscard]] ConstIterator begin() const;
    [[nodiscard]] ConstIterator end() const;

    template <typename T> T Get() const;
    template <typename T> T GetOrDefault(const T &defaultValue) const;

    template <typename T> void PushBack(const T &value);
    template <typename T> void Set(const std::string &key, const T &value);
    template <typename T> void Set(size_t index, const T &value);

    static Json FromFile(const Path &path);
    bool ToFile(const Path &path, int indent = 4);

    template <typename T> Json &operator<<(const T &obj);
    template <typename T> const Json &operator>>(T &obj) const;

    Proxy operator[](const std::string &key);
    const Json operator[](const std::string &key) const;
    Json operator[](std::size_t index);
    const Json operator[](std::size_t index) const;
    operator nlohmann::json() const;

private:
    nlohmann::json m_Data;
};

} // namespace Lumen