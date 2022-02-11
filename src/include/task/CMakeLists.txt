cmake_minimum_required(VERSION 3.10)

set(comp_h Task_components.h)
set(comp_cpp Task_component.cpp Task_composite.cpp Task_leaf.cpp smart_pointer_initializers.cpp)
set(comp_files ${comp_h} ${comp_cpp})

add_library(comp_lib ${comp_files})
