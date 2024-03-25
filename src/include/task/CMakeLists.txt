cmake_minimum_required(VERSION 3.10)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(comp_hpp TaskComponent.hpp TaskLeaf.hpp TaskComposite.hpp Date.hpp initializers.hpp all.hpp)
set(comp_cpp TaskComponent.cpp TaskLeaf.cpp TaskComposite.cpp Date.cpp initializers.cpp)
set(comp_files ${comp_hpp} ${comp_cpp})

add_library(comp_lib ${comp_files})
