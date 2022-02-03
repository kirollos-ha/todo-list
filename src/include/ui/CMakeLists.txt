cmake_minimum_required(VERSION 3.10)

include_directories(../task)

add_subdirectory(../task)

add_library(task_client_lib Task_client.h Task_client.cpp)
