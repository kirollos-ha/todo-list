# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nil/Projects/todo-list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nil/Projects/todo-list/test/build

# Include any dependencies generated for this target.
include src/include/serializers/CMakeFiles/task_serializer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/include/serializers/CMakeFiles/task_serializer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/include/serializers/CMakeFiles/task_serializer.dir/progress.make

# Include the compile flags for this target's objects.
include src/include/serializers/CMakeFiles/task_serializer.dir/flags.make

src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o: src/include/serializers/CMakeFiles/task_serializer.dir/flags.make
src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o: src/include/serializers/task_serializer_autogen/mocs_compilation.cpp
src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o: src/include/serializers/CMakeFiles/task_serializer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nil/Projects/todo-list/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o -MF CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o -c /home/nil/Projects/todo-list/test/build/src/include/serializers/task_serializer_autogen/mocs_compilation.cpp

src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.i"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nil/Projects/todo-list/test/build/src/include/serializers/task_serializer_autogen/mocs_compilation.cpp > CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.i

src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.s"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nil/Projects/todo-list/test/build/src/include/serializers/task_serializer_autogen/mocs_compilation.cpp -o CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.s

src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o: src/include/serializers/CMakeFiles/task_serializer.dir/flags.make
src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o: /home/nil/Projects/todo-list/src/include/serializers/TaskSerializer.cpp
src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o: src/include/serializers/CMakeFiles/task_serializer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nil/Projects/todo-list/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o -MF CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o.d -o CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o -c /home/nil/Projects/todo-list/src/include/serializers/TaskSerializer.cpp

src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/task_serializer.dir/TaskSerializer.cpp.i"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nil/Projects/todo-list/src/include/serializers/TaskSerializer.cpp > CMakeFiles/task_serializer.dir/TaskSerializer.cpp.i

src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/task_serializer.dir/TaskSerializer.cpp.s"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nil/Projects/todo-list/src/include/serializers/TaskSerializer.cpp -o CMakeFiles/task_serializer.dir/TaskSerializer.cpp.s

# Object files for target task_serializer
task_serializer_OBJECTS = \
"CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o"

# External object files for target task_serializer
task_serializer_EXTERNAL_OBJECTS =

src/include/serializers/libtask_serializer.a: src/include/serializers/CMakeFiles/task_serializer.dir/task_serializer_autogen/mocs_compilation.cpp.o
src/include/serializers/libtask_serializer.a: src/include/serializers/CMakeFiles/task_serializer.dir/TaskSerializer.cpp.o
src/include/serializers/libtask_serializer.a: src/include/serializers/CMakeFiles/task_serializer.dir/build.make
src/include/serializers/libtask_serializer.a: src/include/serializers/CMakeFiles/task_serializer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nil/Projects/todo-list/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtask_serializer.a"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && $(CMAKE_COMMAND) -P CMakeFiles/task_serializer.dir/cmake_clean_target.cmake
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_serializer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/include/serializers/CMakeFiles/task_serializer.dir/build: src/include/serializers/libtask_serializer.a
.PHONY : src/include/serializers/CMakeFiles/task_serializer.dir/build

src/include/serializers/CMakeFiles/task_serializer.dir/clean:
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && $(CMAKE_COMMAND) -P CMakeFiles/task_serializer.dir/cmake_clean.cmake
.PHONY : src/include/serializers/CMakeFiles/task_serializer.dir/clean

src/include/serializers/CMakeFiles/task_serializer.dir/depend:
	cd /home/nil/Projects/todo-list/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nil/Projects/todo-list /home/nil/Projects/todo-list/src/include/serializers /home/nil/Projects/todo-list/test/build /home/nil/Projects/todo-list/test/build/src/include/serializers /home/nil/Projects/todo-list/test/build/src/include/serializers/CMakeFiles/task_serializer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/include/serializers/CMakeFiles/task_serializer.dir/depend
