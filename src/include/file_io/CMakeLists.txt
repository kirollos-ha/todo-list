cmake_minimum_required(VERSION 3.10)

#TODO file_read invece di file_parse

add_library(fileio_lib File_parser.h File_parser.cpp File_writer.h File_writer.cpp)
