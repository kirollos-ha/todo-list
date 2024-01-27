cmake_minimum_required(VERSION 3.10)

include_directories(../task)
include_directories(../serializers)

set(client_files TaskClient.hpp TaskClient.cpp)

add_library(ui_lib ${client_files})
