cmake_minimum_required(VERSION 3.20)

project(Lumen)

include(FetchContent)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(BUILD_SHARED_LIBS ON)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

include_directories("src")

#FetchContent_Declare(
#	raylib
#	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
#	GIT_TAG "master"
#	GIT_PROGRESS TRUE
#)

#FetchContent_MakeAvailable(raylib)

add_subdirectory(lib/raylib)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)