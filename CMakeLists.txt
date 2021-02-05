cmake_minimum_required(VERSION 3.10)

project(sunshine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(file_collector)



#test
add_subdirectory(test)


add_executable(sunshine main.cpp)

target_link_libraries(sunshine file_collector)