cmake_minimum_required(VERSION 3.27)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include_directories(../ui)
find_package(Qt5Widgets CONFIG REQUIRED)
add_library(view View.hpp View.cpp)

target_link_libraries(view Qt5::Widgets)
