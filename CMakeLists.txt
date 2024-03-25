cmake_minimum_required(VERSION 3.27)
project(todo_list)

# simboli di debug e warning per qualisasi cosa, utili per quando esplode tutto
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -pedantic")
# DCMAKE_EXPORT_COMPILE_COMMANDS serve per far creare a cmake
# i file necesari per clangd
# che è il language server (anailisi statica) che sto usando
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# set some initial things
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc (meta object compiler) automatically when needed.
set(CMAKE_AUTOMOC ON)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# encapsulate test and release behaviours
function(common)
  include_directories(
    src/include/view
    src/include/task
    src/include/ui
    src/include/serializers
  )

  add_subdirectory(src/include/view)
  add_subdirectory(src/include/ui)
  add_subdirectory(src/include/task)
  add_subdirectory(src/include/serializers)
  
  target_link_libraries(ui_lib comp_lib)
endfunction()

function(release_this)
  common()

  set(todo_SRC src/main.cpp)
  add_executable(todo ${todo_SRC})
  
  # Use the Widgets module from Qt 5.
  target_link_libraries(todo Qt5::Widgets)
  
  target_link_libraries(todo view)
  target_link_libraries(todo ui_lib)
  target_link_libraries(todo task_serializer)
  target_link_libraries(todo task_file_parser)
  
  # Install the executable
  install(TARGETS todo DESTINATION bin)
endfunction()

function(test_this)
  common()

  set(test_tools test/minitest.hpp)
  set(test_files
    test/test_date.hpp
    test/test_task_components.hpp
    test/test_counting.hpp
    test/test_client.hpp
    test/test_serializer.hpp
  )

  add_executable(testexe test/test_main.cpp ${test_tools} ${test_files})

  target_link_libraries(testexe comp_lib)
  target_link_libraries(testexe ui_lib)
  target_link_libraries(testexe task_serializer)
  target_link_libraries(testexe task_file_parser)

  install(TARGETS testexe DESTINATION bin)
endfunction()

# main, kinda
if(${TESTING} STREQUAL "no")
  release_this()
elseif(${TESTING} STREQUAL "yes")
  test_this()
else()
  #default behaviour
  release_this()
endif()
