cmake_minimum_required(VERSION 3.16)

project(math VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp)
