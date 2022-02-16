cmake_minimum_required(VERSION 3.10)

project(todo_test)

include_directories(../src/include/file_io)
include_directories(../src/include/task)
include_directories(../src/include/ui)

add_subdirectory(../src/include test_lib_build)

#set files for testing
set(testing_files test_ui.h test_fileio.h test_task_components.h minitest.hpp)

#add_executable(testexe test_main.cpp ${testing_files} ${tested_files})

add_executable(testexe test_main.cpp ${testing_files})
target_link_libraries(testexe all_libs)
