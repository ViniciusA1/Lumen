cmake_minimum_required(VERSION 3.25)

project(Lumen)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/lib/IconsFontCpp"
)

add_subdirectory(lib/box2d)
add_subdirectory(lib/entt)
add_subdirectory(lib/imgui)
add_subdirectory(lib/ImGuiFileDialog)
add_subdirectory(lib/ImGuizmo)
add_subdirectory(lib/Jolt/Build)
add_subdirectory(lib/json)
add_subdirectory(lib/raylib)
add_subdirectory(lib/rlImGui)
add_subdirectory(lib/yaml)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/IconsFontCpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
	box2d
	EnTT
	imgui
	ImGuiFileDialog
	ImGuizmo
	Jolt
	raylib
	rlImGui
	nlohmann_json::nlohmann_json
	yaml-cpp::yaml-cpp
)