cmake_minimum_required(VERSION 3.10)

include_directories(../task)

add_library(task_serializer TaskSerializer.hpp TaskSerializer.cpp)
add_library(task_file_parser TaskFileParser.cpp TaskFileParser.cpp)
