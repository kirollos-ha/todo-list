cmake_minimum_required(VERSION 3.10)

add_library(components_lib Task_components.h Task_components.cpp)

#target_link_libraries(client_lib components_lib)
#client_lib dipende da components_lib e non viceversa, quindi questa roba si gestisce in ../ui
