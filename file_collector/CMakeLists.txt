set(incs file_collector.h 
         video_file_collector.h 
         subtitle_file_collector.h)

set(srcs file_collector.cpp 
         video_file_collector.cpp
         subtitle_file_collector.cpp)

find_package(Qt5 COMPONENTS Core REQUIRED)
add_library(file_collector ${incs} ${srcs})
target_link_libraries(file_collector Qt5::Core)

