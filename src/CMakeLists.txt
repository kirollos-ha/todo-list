cmake_minimum_required(VERSION 3.10)

project(todolist)

include_directories(include)

add_subdirectory(include main_lib_build)

add_executable(mainexe main.cpp)

target_link_libraries(mainexe all_libs)
