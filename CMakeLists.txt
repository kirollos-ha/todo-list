cmake_minimum_required(VERSION 3.27)
project(mvc)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(mvc_SRC src/main.cpp)

add_executable(mvc ${mvc_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(mvc Qt5::Widgets)

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

target_link_libraries(mvc view)
target_link_libraries(mvc ui_lib)
target_link_libraries(mvc task_serializer)
target_link_libraries(mvc task_file_parser)

# Install the executable
install(TARGETS mvc DESTINATION bin)
