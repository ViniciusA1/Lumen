cmake_minimum_required(VERSION 3.25)

project(lumen)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_SHARED_LIBS OFF)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(lib/box2d)
add_subdirectory(lib/enet)
add_subdirectory(lib/entt)
add_subdirectory(lib/imgui)
add_subdirectory(lib/ImGuizmo)
add_subdirectory(lib/Jolt/Build)
add_subdirectory(lib/json)
add_subdirectory(lib/lua)
add_subdirectory(lib/nativefiledialog)
add_subdirectory(lib/raylib)
add_subdirectory(lib/rlImGui)
add_subdirectory(lib/sol2)
add_subdirectory(lib/spdlog)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC
	box2d
	enet_static
	EnTT
	imgui
	ImGuizmo
	Jolt
	nlohmann_json::nlohmann_json
	lua
	nfd
	raylib
	rlImGui
	sol2
	spdlog::spdlog
)