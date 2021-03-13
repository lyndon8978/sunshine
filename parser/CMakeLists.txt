set(incs parser.h)

set(srcs parser.cpp)

find_package(Qt5 COMPONENTS Core REQUIRED)
add_library(parser ${incs} ${srcs})
target_link_libraries(parser Qt5::Core)

