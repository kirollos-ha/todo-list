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

# Utility rule file for task_file_parser_autogen.

# Include any custom commands dependencies for this target.
include src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/progress.make

src/include/serializers/CMakeFiles/task_file_parser_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/nil/Projects/todo-list/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target task_file_parser"
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && /usr/bin/cmake -E cmake_autogen /home/nil/Projects/todo-list/test/build/src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/AutogenInfo.json ""

task_file_parser_autogen: src/include/serializers/CMakeFiles/task_file_parser_autogen
task_file_parser_autogen: src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/build.make
.PHONY : task_file_parser_autogen

# Rule to build all files generated by this target.
src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/build: task_file_parser_autogen
.PHONY : src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/build

src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/clean:
	cd /home/nil/Projects/todo-list/test/build/src/include/serializers && $(CMAKE_COMMAND) -P CMakeFiles/task_file_parser_autogen.dir/cmake_clean.cmake
.PHONY : src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/clean

src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/depend:
	cd /home/nil/Projects/todo-list/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nil/Projects/todo-list /home/nil/Projects/todo-list/src/include/serializers /home/nil/Projects/todo-list/test/build /home/nil/Projects/todo-list/test/build/src/include/serializers /home/nil/Projects/todo-list/test/build/src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/include/serializers/CMakeFiles/task_file_parser_autogen.dir/depend

