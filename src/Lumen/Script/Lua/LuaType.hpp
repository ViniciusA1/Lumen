#pragma once

#include "sol/table.hpp"

namespace Lumen
{

template <typename T> class LuaType
{
public:
    LuaType(sol::usertype<T> userType);

    template <class... Args> LuaType &Constructors();

    template <typename Base> LuaType &Base();

    template <typename M> LuaType &Property(const std::string &name, M T::*member);
    template <typename R, typename... GetterArgs, typename S, typename... SetterArgs>
    LuaType &Property(const std::string &name, R (T::*getter)(GetterArgs...) const,
                      S (T::*setter)(SetterArgs...));
    template <typename R, typename... Args>
    LuaType &Property(const std::string &name, R (T::*getter)(Args...) const);
    template <typename U>
    LuaType &StaticProperty(const std::string &name, const U &value);

    template <typename Func, typename... Funcs>
    LuaType &Method(const std::string &name, Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &StaticMethod(const std::string &name, Func function, Funcs &&...functions);

    template <typename Func, typename... Funcs>
    LuaType &OperatorAdd(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorSub(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorMul(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorDiv(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorMod(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorPow(Func function, Funcs &&...functions);
    template <typename Func> LuaType &OperatorUnaryMinus(Func function);

    template <typename Func> LuaType &OperatorIndex(Func function);
    template <typename Func> LuaType &OperatorNewIndex(Func function);

    template <typename Func, typename... Funcs>
    LuaType &OperatorEq(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorLt(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorLe(Func function, Funcs &&...functions);

    template <typename Func, typename... Funcs>
    LuaType &OperatorCall(Func function, Funcs &&...functions);

    template <typename Func, typename... Funcs>
    LuaType &OperatorNext(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorPairs(Func function, Funcs &&...functions);
    template <typename Func, typename... Funcs>
    LuaType &OperatorIPairs(Func function, Funcs &&...functions);

    template <typename Func, typename... Funcs>
    LuaType &OperatorConcat(Func function, Funcs &&...functions);
    template <typename Func> LuaType &OperatorToString(Func function);

private:
    sol::usertype<T> m_UserType;
};

} // namespace Lumen

#include "Lumen/Script/Lua/LuaType.inl"