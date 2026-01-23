#include "Lumen/Serialization/Json.hpp"

#include <fstream>

namespace Lumen
{

Json::Json(nlohmann::json json) : m_Data(std::move(json))
{
}

Json::Json(std::initializer_list<nlohmann::json::value_type> initList) : m_Data(initList)
{
}

bool Json::IsArray() const
{
    return m_Data.is_array();
}

bool Json::IsBoolean() const
{
    return m_Data.is_boolean();
}

bool Json::IsNull() const
{
    return m_Data.is_null();
}

bool Json::IsNumber() const
{
    return m_Data.is_number();
}

bool Json::IsObject() const
{
    return m_Data.is_object();
}

bool Json::IsString() const
{
    return m_Data.is_string();
}

bool Json::Contains(const std::string &key) const
{
    return m_Data.contains(key);
}

std::vector<std::pair<std::string, Json>> Json::GetKeyValues() const
{
    if (!IsObject())
        return {};

    std::vector<std::pair<std::string, Json>> result;
    for (const auto &item : m_Data.items())
        result.emplace_back(item.key(), item.value());

    return result;
}

std::vector<std::string> Json::GetKeys() const
{
    if (!IsObject())
        return {};

    std::vector<std::string> result;
    for (const auto &item : m_Data.items())
        result.push_back(item.key());

    return result;
}

std::size_t Json::GetSize() const
{
    return m_Data.size();
}

std::vector<Json> Json::GetValues() const
{
    if (!IsObject())
        return {};

    std::vector<Json> result;
    for (const auto &item : m_Data.items())
        result.emplace_back(item.value());

    return result;
}

JsonIterator Json::begin()
{
    return m_Data.begin();
}

JsonIterator Json::end()
{
    return m_Data.end();
}

JsonConstIterator Json::begin() const
{
    return m_Data.begin();
}

JsonConstIterator Json::end() const
{
    return m_Data.end();
}

void Json::Clear()
{
    m_Data.clear();
}

void Json::Erase(const std::string &key)
{
    m_Data.erase(key);
}

const Json Json::operator[](std::size_t index) const
{
    return m_Data[index];
}

Json Json::operator[](std::size_t index)
{
    return m_Data[index];
}

const Json Json::operator[](const std::string &key) const
{
    return m_Data[key];
}

JsonProxy Json::operator[](const std::string &key)
{
    return m_Data[key];
}

SerializationResult Json::FromFileInternal(const Path &path, Json &out)
{
    SerializationResult result;

    std::ifstream file(path.String());
    if (!file.is_open())
    {
        result.AddError("Failed to open file", path);
        return result;
    }

    try
    {
        nlohmann::json jsonData;
        file >> jsonData;
        out = Json(std::move(jsonData));
    }
    catch (const std::exception &e)
    {
        result.AddError(e.what(), path);
    }

    return result;
}

SerializationResult Json::ToFile(const Path &path) const
{
    SerializationResult result;

    std::ofstream file(path.String());
    if (!file.is_open())
    {
        result.AddError("Failed to open file for writing", path);
        return result;
    }

    try
    {
        file << m_Data.dump(4);
    }
    catch (const std::exception &e)
    {
        result.AddError(e.what(), path);
    }

    return result;
}

JsonIterator::JsonIterator(nlohmann::json::iterator it) : m_Iterator(std::move(it))
{
}

JsonIterator &JsonIterator::operator++()
{
    ++m_Iterator;
    return *this;
}

JsonIterator JsonIterator::operator++(int)
{
    JsonIterator temp = *this;
    ++(*this);
    return temp;
}

bool JsonIterator::operator==(const JsonIterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool JsonIterator::operator!=(const JsonIterator &other) const
{
    return !(*this == other);
}

Json JsonIterator::operator*() const
{
    return *m_Iterator;
}

JsonConstIterator::JsonConstIterator(nlohmann::json::const_iterator it)
    : m_Iterator(std::move(it))
{
}

JsonConstIterator &JsonConstIterator::operator++()
{
    ++m_Iterator;
    return *this;
}

JsonConstIterator JsonConstIterator::operator++(int)
{
    JsonConstIterator temp = *this;
    ++(*this);
    return temp;
}

bool JsonConstIterator::operator==(const JsonConstIterator &other) const
{
    return m_Iterator == other.m_Iterator;
}

bool JsonConstIterator::operator!=(const JsonConstIterator &other) const
{
    return !(*this == other);
}

Json JsonConstIterator::operator*() const
{
    return *m_Iterator;
}

JsonProxy::JsonProxy(nlohmann::json &ref) : m_Ref(ref)
{
}

JsonProxy JsonProxy::operator[](const std::string &key)
{
    return m_Ref[key];
}

JsonIterator JsonProxy::begin()
{
    return m_Ref.begin();
}
JsonIterator JsonProxy::end()
{
    return m_Ref.end();
}

JsonProxy::operator Json() const
{
    return m_Ref;
}

} // namespace Lumen