cmake_minimum_required(VERSION 3.20)

project(
  math
  VERSION 0.1
  LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(DOWNLOAD
     https://raw.githubusercontent.com/doctest/doctest/v2.4.11/doctest/doctest.h
     ${CMAKE_SOURCE_DIR}/doctest.h)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG ae50bfa2cc569c0f8d5bc4315d39db64005b1b08 # v5.0
)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE TEST_SRC "${CMAKE_SOURCE_DIR}/test/*.cpp")
file(GLOB_RECURSE ENGINE_SRC "${CMAKE_SOURCE_DIR}/engine/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(test ${TEST_SRC})

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(test PRIVATE ${PROJECT_NAME})

add_executable(engine ${ENGINE_SRC})

target_include_directories(engine PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(engine PRIVATE raylib)
