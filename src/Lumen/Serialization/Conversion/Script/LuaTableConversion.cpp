#include "Lumen/Script/ScriptEngine.hpp"
#include "Lumen/Serialization/Conversion/Script/ScriptConversion.hpp"

#include "sol/sol.hpp"
#include <stack>

namespace Lumen::JsonSerializer
{

template <> Json Serialize(const LuaTable &rootTable)
{
    Json rootJson;

    // struct Frame
    // {
    //     LuaTable table;
    //     Json *parent;
    //     std::string key;
    //     Json node;
    // };

    // std::stack<Frame> stack;

    // Frame rootFrame;
    // rootFrame.table = rootTable;
    // rootFrame.parent = nullptr;
    // rootFrame.key = "";
    // stack.push(std::move(rootFrame));

    // while (!stack.empty())
    // {
    //     Frame frame = std::move(stack.top());
    //     stack.pop();

    //     for (auto &pair : frame.table)
    //     {
    //         LuaObject key = pair.first;
    //         LuaObject value = pair.second;
    //         auto keyStr = key.As<std::string>();

    //         if (value.IsTable())
    //         {
    //             Frame childFrame;
    //             childFrame.table = value.As<sol::table>();
    //             childFrame.parent = &frame.node;
    //             childFrame.key = keyStr;
    //             stack.push(std::move(childFrame));
    //         }
    //         else
    //         {
    //             frame.node[keyStr] << value;
    //         }
    //     }

    //     if (frame.parent)
    //         (*frame.parent)[frame.key] << frame.node;
    //     else
    //         rootJson = std::move(frame.node);
    // }

    return rootJson;
}

template <> void Deserialize(const Json &json, LuaTable &rootTable)
{
    // struct Frame
    // {
    //     const Json *json;
    //     LuaTable table;
    // };

    // std::stack<Frame> stack;
    // stack.push({&json, rootTable});

    // while (!stack.empty())
    // {
    //     Frame frame = stack.top();
    //     stack.pop();

    //     const Json &jsonMap = *frame.json;
    //     LuaTable &table = frame.table;

    //     for (const auto &[key, valueNode] : jsonMap.GetKeyValues())
    //     {
    //         if (valueNode.IsObject())
    //         {
    //             auto udObj = ScriptEngine::GetInstance()->Get<sol::object>(key);

    //             if (udObj.valid())
    //             {
    //                 sol::userdata ud = udObj.as<sol::userdata>();
    //                 sol::table mt = ud[sol::metatable_key];
    //                 sol::function deserializeFn = mt["__deserialize"];
    //                 if (deserializeFn.valid())
    //                 {
    //                     LuaObject luaObj(udObj);
    //                     deserializeFn(valueNode, key, luaObj);
    //                 }
    //                 table.Set(key, udObj);
    //             }
    //             else
    //             {
    //                 LuaTable childTable = table.CreateSubObject();
    //                 table.Set(key, childTable);
    //                 stack.push({&valueNode, childTable});
    //             }
    //             continue;
    //         }

    //         sol::object obj = sol::nil;
    //         sol::state_view lua((lua_State *)*ScriptEngine::GetInstance());

    //         if (valueNode.IsNumber() || valueNode.IsBoolean())
    //         {
    //             auto s = valueNode.Get<std::string>();

    //             if (s == "true" || s == "false")
    //             {
    //                 obj = sol::make_object(lua, s == "true");
    //             }
    //             else
    //             {
    //                 try
    //                 {
    //                     long long i = std::stoll(s);
    //                     obj = sol::make_object(lua, i);
    //                 }
    //                 catch (...)
    //                 {
    //                     try
    //                     {
    //                         double d = std::stod(s);
    //                         obj = sol::make_object(lua, d);
    //                     }
    //                     catch (...)
    //                     {
    //                         obj = sol::make_object(lua, s);
    //                     }
    //                 }
    //             }
    //         }

    //         table.Set(key, obj);
    //     }
    // }
}

} // namespace Lumen::JsonSerializer