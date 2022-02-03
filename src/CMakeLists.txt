cmake_minimum_required(VERSION 3.10)

project(todolist)

include_directories(include/task)

add_subdirectory(include/task)#libraries from here: components_lib

add_executable(mainexe main.cpp)

target_link_libraries(mainexe components_lib)
