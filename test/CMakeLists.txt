cmake_minimum_required(VERSION 3.10)

project(todo_test)

include_directories(../src/include/file_io)
include_directories(../src/include/task)

add_subdirectory(../src/include test_lib_build)

#include_directories(../src/include/ui)

#set files to be tested
#set(taskcomp_dir ../src/include/task)
#set(taskcomp_files ${taskcomp_dir}/Task_components.h ${taskcomp_dir}/Task_components.cpp)

#set(fileio_dir ../src/include/file_io)
#set(filei_files ${fileio_dir}/File_parser.h ${fileio_dir}/File_parser.cpp)
#set(fileo_files ${fileio_dir}/File_writer.h ${fileio_dir}/File_writer.cpp)
#set(fileio_files ${filei_files} ${fileo_files})

#set(tested_files ${taskcomp_files} ${fileio_files})

#set files for testing
set(testing_files test_client.h test_fileio.h test_task_components.h minitest.hpp)

#add_executable(testexe test_main.cpp ${testing_files} ${tested_files})

add_executable(testexe test_main.cpp ${testing_files})
target_link_libraries(testexe all_libs)
