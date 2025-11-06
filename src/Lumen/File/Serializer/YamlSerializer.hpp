#pragma once

#include <utility>

#include "Lumen/File/Path.hpp"

#if WIN32
#define YAML_CPP_STATIC_DEFINE
#endif
#include "yaml-cpp/yaml.h"

namespace Lumen
{

class Yaml;

namespace YamlSerializer
{

template <typename T> Yaml Serialize(const T &obj);
template <typename T> void Deserialize(const Yaml &node, T &obj);

} // namespace YamlSerializer

class Yaml
{
public:
    enum class EmitterStyle
    {
        Default,
        Block,
        Flow
    };

public:
    Yaml() = default;
    Yaml(const YAML::Node &node);

    bool IsNull() const;
    bool IsSequence() const;

    void Clear();
    bool Contains(const std::string &key) const;
    std::size_t Size() const;

    void SetStyle(Yaml::EmitterStyle style);

    template <typename T> T As() const { return m_Data.as<T>(); }

    template <typename T> bool Is() const
    {
        return m_Data.IsDefined() && m_Data.IsScalar() && m_Data.as<T>();
    }

    template <typename T> T GetOrDefault(const T &defaultValue) const
    {
        if (!IsNull())
        {
            return m_Data.as<T>();
        }

        return defaultValue;
    }

    void PushBack(const Yaml &yaml);

    template <typename T> void PushBack(const T &value) { m_Data.push_back(value); }

    static Yaml FromFile(const Path &path);
    bool ToFile(const Path &path);

    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = Yaml;
        using difference_type = std::ptrdiff_t;
        using pointer = Yaml *;
        using reference = Yaml &;

        explicit Iterator(YAML::iterator it) : m_Iterator(std::move(it)) {}

        Yaml operator*() const { return *m_Iterator; }
        Iterator &operator++()
        {
            ++m_Iterator;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return m_Iterator != other.m_Iterator;
        }

    private:
        YAML::iterator m_Iterator;
    };

    class ConstIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Yaml;
        using difference_type = std::ptrdiff_t;
        using pointer = const Yaml *;
        using reference = const Yaml &;

        explicit ConstIterator(YAML::const_iterator it) : m_Iterator(std::move(it)) {}

        Yaml operator*() const { return *m_Iterator; }
        ConstIterator &operator++()
        {
            ++m_Iterator;
            return *this;
        }

        bool operator!=(const ConstIterator &other) const
        {
            return m_Iterator != other.m_Iterator;
        }

    private:
        YAML::const_iterator m_Iterator;
    };

    ConstIterator begin() const;
    ConstIterator end() const;

    Iterator begin();
    Iterator end();

    template <typename T> Yaml &operator<<(const T &obj)
    {
        Yaml serializedData = YamlSerializer::Serialize(obj);

        if (m_Data.IsMap())
        {
            for (const auto &item : serializedData.m_Data)
            {
                m_Data[item.first] = item.second;
            }
        }
        else if (m_Data.IsSequence())
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

    template <typename T> const Yaml &operator>>(T &obj) const
    {
        YamlSerializer::Deserialize(*this, obj);
        return *this;
    }

    template <typename T> const Yaml operator[](const T &key) const
    {
        return m_Data[key];
    }

    template <typename T> Yaml operator[](const T &key) { return m_Data[key]; }

    operator YAML::Node() const;

private:
    YAML::Node m_Data;
};

} // namespace Lumen

namespace Lumen::YamlSerializer
{

template <typename T> Yaml Serialize(const T &obj)
{
    YAML::Node yaml;
    yaml = obj;
    return {yaml};
}

template <typename T> void Deserialize(const Yaml &yaml, T &obj)
{
    obj = yaml.GetOrDefault<T>(obj);
}

} // namespace Lumen::YamlSerializer

#include "Lumen/File/Serializer/Conversions/Conversions.hpp"