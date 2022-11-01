cmake_minimum_required(VERSION 3.10)

include_directories(../task)

set(client_files Task_client.h Task_client.cpp)

set(client_CLI_files Command_line_parser.h Client_CLI.h)

add_library(ui_lib ${client_CLI_files} ${task_client_files})
