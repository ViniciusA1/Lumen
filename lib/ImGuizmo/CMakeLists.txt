cmake_minimum_required(VERSION 3.20)

project(ImGuizmo LANGUAGES CXX)

add_library(ImGuizmo STATIC
   ImGuizmo.cpp
   ImGuizmo.h
)

target_include_directories(ImGuizmo PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ImGuizmo PUBLIC imgui)
target_compile_features(ImGuizmo PUBLIC cxx_std_17)
