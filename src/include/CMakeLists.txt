cmake_minimum_required(VERSION 3.10)

include_directories(task file_io ui)
add_subdirectory(task)
add_subdirectory(file_io)
add_subdirectory(ui)

add_library(all_libs all_headers.h)
target_link_libraries(all_libs comp_lib fileio_lib)
