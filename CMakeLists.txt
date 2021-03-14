cmake_minimum_required(VERSION 3.10)

project(sunshine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(file_collector)
add_subdirectory(assembler)
add_subdirectory(parser)

add_executable(sunshine main.cpp)
target_link_libraries(sunshine Qt5::Widgets file_collector assembler parser)