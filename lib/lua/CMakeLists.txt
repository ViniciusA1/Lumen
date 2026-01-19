cmake_minimum_required(VERSION 3.25)

project(lua C)

file(GLOB LUA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
list(REMOVE_ITEM LUA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/lua.c")
list(REMOVE_ITEM LUA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/luac.c")

add_library(lua STATIC ${LUA_SOURCES})

target_include_directories(lua PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# if(UNIX AND NOT APPLE)
# target_compile_definitions(lua PRIVATE LUA_USE_POSIX)
# target_link_libraries(lua PRIVATE m)
# elseif(APPLE)
# target_compile_definitions(lua PRIVATE LUA_USE_MACOSX)
# elseif(WIN32)
# target_compile_definitions(lua PRIVATE LUA_USE_WINDOWS)
# endif()
set_property(TARGET lua PROPERTY C_STANDARD 99)