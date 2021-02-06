set(incs assembler.h)

set(srcs assembler.cpp)

find_package(Qt5 COMPONENTS Core REQUIRED)
add_library(assembler ${incs} ${srcs})
target_link_libraries(assembler file_collector Qt5::Core)

