cmake_minimum_required(VERSION 3.10)

#TODO file_read invece di file_parse

set(fileio_h File_parser.h File_writer.h)
set(fileio_cpp File_parser.cpp File_writer.cpp)
set(fileio_files ${fileio_h} ${fileio_cpp})

add_library(fileio_lib ${fileio_files})
