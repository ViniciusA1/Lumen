#pragma once

#include "Lumen/Script/Lua/LuaType.hpp"
#include <sol/property.hpp>
#include <utility>

namespace Lumen
{

template <typename T>
LuaType<T>::LuaType(sol::usertype<T> userType) : m_UserType(std::move(userType))
{
}

template <typename T> template <class... Args> LuaType<T> &LuaType<T>::Constructors()
{
    m_UserType[sol::meta_function::construct] = sol::constructors<Args...>();
    return *this;
}

template <typename T> template <typename Base> LuaType<T> &LuaType<T>::Base()
{
    m_UserType.set(sol::base_classes, sol::bases<Base>());
    return *this;
}

template <typename T>
template <typename M>
LuaType<T> &LuaType<T>::Property(const std::string &name, M T::*member)
{
    m_UserType[name] =
        sol::property([member](T &self) -> M & { return self.*member; },
                      [member](T &self, const M &value) { self.*member = value; });
    return *this;
}

template <typename T>
template <typename R, typename... GetterArgs, typename S, typename... SetterArgs>
LuaType<T> &LuaType<T>::Property(const std::string &name,
                                 R (T::*getter)(GetterArgs...) const,
                                 S (T::*setter)(SetterArgs...))
{
    m_UserType[name] = sol::property(
        [getter](const T &self, GetterArgs... args) {
            return (self.*getter)(std::forward<GetterArgs>(args)...);
        },
        [setter](T &self, SetterArgs... args) {
            (self.*setter)(std::forward<SetterArgs>(args)...);
        });

    return *this;
}

template <typename T>
template <typename R, typename... Args>
LuaType<T> &LuaType<T>::Property(const std::string &name, R (T::*getter)(Args...) const)
{
    m_UserType[name] = sol::property([getter](const T &self, Args... args) {
        return (self.*getter)(std::forward<Args>(args)...);
    });
    return *this;
}

template <typename T>
template <typename U>
LuaType<T> &LuaType<T>::StaticProperty(const std::string &name, const U &value)
{
    m_UserType[name] = sol::var(value);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::Method(const std::string &name, Func function,
                               Funcs &&...functions)
{
    m_UserType.set_function(name,
                            sol::overload(function, std::forward<Funcs>(functions)...));
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::StaticMethod(const std::string &name, Func function,
                                     Funcs &&...functions)
{
    m_UserType.set(name, sol::overload(function, std::forward<Funcs>(functions)...));
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorAdd(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::addition] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorSub(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::subtraction] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorMul(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::multiplication] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorDiv(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::division] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorMod(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::modulus] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorPow(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::power_of] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func>
LuaType<T> &LuaType<T>::OperatorUnaryMinus(Func function)
{
    m_UserType[sol::meta_function::unary_minus] = function;
    return *this;
}

template <typename T>
template <typename Func>
LuaType<T> &LuaType<T>::OperatorIndex(Func function)
{
    m_UserType[sol::meta_function::index] = function;
    return *this;
}

template <typename T>
template <typename Func>
LuaType<T> &LuaType<T>::OperatorNewIndex(Func function)
{
    m_UserType[sol::meta_function::new_index] = function;
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorEq(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::equal_to] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorLt(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::less_than] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorLe(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::less_than_or_equal_to] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorCall(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::call_function] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorNext(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::next] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorPairs(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::pairs] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorIPairs(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::ipairs] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func, typename... Funcs>
LuaType<T> &LuaType<T>::OperatorConcat(Func function, Funcs &&...functions)
{
    m_UserType[sol::meta_function::concatenation] =
        sol::overload(function, std::forward<Funcs>(functions)...);
    return *this;
}

template <typename T>
template <typename Func>
LuaType<T> &LuaType<T>::OperatorToString(Func function)
{
    m_UserType[sol::meta_function::to_string] = function;
    return *this;
}

} // namespace Lumen