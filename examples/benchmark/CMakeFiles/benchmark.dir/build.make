# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniel/code/entity_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/code/entity_system

# Include any dependencies generated for this target.
include examples/benchmark/CMakeFiles/benchmark.dir/depend.make

# Include the progress variables for this target.
include examples/benchmark/CMakeFiles/benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include examples/benchmark/CMakeFiles/benchmark.dir/flags.make

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o: examples/benchmark/CMakeFiles/benchmark.dir/flags.make
examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o: examples/benchmark/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/daniel/code/entity_system/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o"
	cd /home/daniel/code/entity_system/examples/benchmark && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/main.cpp.o -c /home/daniel/code/entity_system/examples/benchmark/main.cpp

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/main.cpp.i"
	cd /home/daniel/code/entity_system/examples/benchmark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/daniel/code/entity_system/examples/benchmark/main.cpp > CMakeFiles/benchmark.dir/main.cpp.i

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/main.cpp.s"
	cd /home/daniel/code/entity_system/examples/benchmark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/daniel/code/entity_system/examples/benchmark/main.cpp -o CMakeFiles/benchmark.dir/main.cpp.s

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.requires:
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.requires

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.provides: examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.requires
	$(MAKE) -f examples/benchmark/CMakeFiles/benchmark.dir/build.make examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.provides.build
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.provides

examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.provides.build: examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.provides.build

# Object files for target benchmark
benchmark_OBJECTS = \
"CMakeFiles/benchmark.dir/main.cpp.o"

# External object files for target benchmark
benchmark_EXTERNAL_OBJECTS =

bin/benchmark: examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o
bin/benchmark: lib/libentity_system.so
bin/benchmark: examples/benchmark/CMakeFiles/benchmark.dir/build.make
bin/benchmark: examples/benchmark/CMakeFiles/benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/benchmark"
	cd /home/daniel/code/entity_system/examples/benchmark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/benchmark/CMakeFiles/benchmark.dir/build: bin/benchmark
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/build

examples/benchmark/CMakeFiles/benchmark.dir/requires: examples/benchmark/CMakeFiles/benchmark.dir/main.cpp.o.requires
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/requires

examples/benchmark/CMakeFiles/benchmark.dir/clean:
	cd /home/daniel/code/entity_system/examples/benchmark && $(CMAKE_COMMAND) -P CMakeFiles/benchmark.dir/cmake_clean.cmake
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/clean

examples/benchmark/CMakeFiles/benchmark.dir/depend:
	cd /home/daniel/code/entity_system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/code/entity_system /home/daniel/code/entity_system/examples/benchmark /home/daniel/code/entity_system /home/daniel/code/entity_system/examples/benchmark /home/daniel/code/entity_system/examples/benchmark/CMakeFiles/benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/benchmark/CMakeFiles/benchmark.dir/depend

