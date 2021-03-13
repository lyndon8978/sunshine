cmake_minimum_required(VERSION 3.10)

project(sunshine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(file_collector)
add_subdirectory(assembler)
add_subdirectory(parser)



#test
add_subdirectory(test)

#main 
add_executable(sunshine main.cpp)
target_link_libraries(sunshine file_collector assembler parser)