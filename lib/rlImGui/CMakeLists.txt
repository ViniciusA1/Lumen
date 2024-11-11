cmake_minimum_required(VERSION 3.20)

project(rlImGui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    imgui_impl_raylib.h
    rlImGui.cpp
    rlImGui.h
    rlImGuiColors.h
)

add_library(rlImGui SHARED ${SOURCES})

target_include_directories(rlImGui PUBLIC .)
target_link_libraries(rlImGui PUBLIC raylib imgui)