cmake_minimum_required(VERSION 3.20)

project(Lumen)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include_directories("src" "lib/IconsFontCpp")

add_subdirectory(lib/raylib)
add_subdirectory(lib/imgui)
add_subdirectory(lib/rlImGui)
add_subdirectory(lib/ImGuiFileDialog)
add_subdirectory(lib/json)
add_subdirectory(lib/entt)
add_subdirectory(lib/yaml)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib imgui rlImGui ImGuiFileDialog EnTT yaml-cpp::yaml-cpp nlohmann_json::nlohmann_json)