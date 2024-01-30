cmake_minimum_required(VERSION 3.27)
project(mvc)

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

  set(mvc_SRC src/main.cpp)
  add_executable(mvc ${mvc_SRC})
  
  # Use the Widgets module from Qt 5.
  target_link_libraries(mvc Qt5::Widgets)
  
  target_link_libraries(mvc view)
  target_link_libraries(mvc ui_lib)
  target_link_libraries(mvc task_serializer)
  target_link_libraries(mvc task_file_parser)
  
  # Install the executable
  install(TARGETS mvc DESTINATION bin)
endfunction()

function(test_this)
  common()

  set(test_tools test/minitest.hpp)
  set(test_files test/test_task_components.hpp)

  add_executable(testexe test/test_main.cpp ${test_tools} ${test_files})

  target_link_libraries(testexe comp_lib)

  install(TARGETS testexe DESTINATION bin)
endfunction()

project(todo_test)



# main, kinda
if(${TESTING} STREQUAL "no")
  release_this()
elseif(${TESTING} STREQUAL "yes")
  test_this()
else()
  #default behaviour
  release_this()
endif()
