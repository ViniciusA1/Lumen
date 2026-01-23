#include "Lumen/Serialization/Conversion/Script/ScriptConversion.hpp"
#include "sol/object.hpp"

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LuaObject &object)
{
    Json json;

    switch (object.GetType())
    {
    case LuaObjectType::Boolean:
        json["type"] << "boolean";
        json["value"] << object.As<bool>();
        break;
    case LuaObjectType::Number:
        json["type"] << "number";
        json["value"] << object.As<double>();
        break;
    case LuaObjectType::String:
        json["type"] << "string";
        json["value"] << object.As<std::string>();
        break;
    case LuaObjectType::Userdata: {
        auto userdata = object.As<sol::userdata>();
        sol::table metatable = userdata[sol::metatable_key];
        sol::function func = userdata["__serialize"];
        if (!func.valid())
        {
            json = Json();
            break;
        }

        std::string full = metatable["__name"].get<std::string>();
        if (full.rfind("sol.", 0) == 0)
            full = full.substr(4);

        size_t pos = full.rfind("::");
        if (pos != std::string::npos)
            full = full.substr(pos + 2);

        Json value = func(userdata);
        json["type"] << full;
        json["value"] << value;
        break;
    }
    default:;
    }

    return json;
}

template <> void Deserialize(const Json &json, LuaObject &object)
{
}

} // namespace Lumen::JsonSerializer