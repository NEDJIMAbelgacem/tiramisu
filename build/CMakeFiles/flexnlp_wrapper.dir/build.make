# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build

# Include any dependencies generated for this target.
include CMakeFiles/flexnlp_wrapper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flexnlp_wrapper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flexnlp_wrapper.dir/flags.make

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o: CMakeFiles/flexnlp_wrapper.dir/flags.make
CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o: ../src/tiramisu_flexnlp_wrappers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/src/tiramisu_flexnlp_wrappers.cpp

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/src/tiramisu_flexnlp_wrappers.cpp > CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.i

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/src/tiramisu_flexnlp_wrappers.cpp -o CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.s

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.requires:

.PHONY : CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.requires

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.provides: CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.requires
	$(MAKE) -f CMakeFiles/flexnlp_wrapper.dir/build.make CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.provides.build
.PHONY : CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.provides

CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.provides.build: CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o


# Object files for target flexnlp_wrapper
flexnlp_wrapper_OBJECTS = \
"CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o"

# External object files for target flexnlp_wrapper
flexnlp_wrapper_EXTERNAL_OBJECTS =

libflexnlp_wrapper.a: CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o
libflexnlp_wrapper.a: CMakeFiles/flexnlp_wrapper.dir/build.make
libflexnlp_wrapper.a: CMakeFiles/flexnlp_wrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libflexnlp_wrapper.a"
	$(CMAKE_COMMAND) -P CMakeFiles/flexnlp_wrapper.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flexnlp_wrapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flexnlp_wrapper.dir/build: libflexnlp_wrapper.a

.PHONY : CMakeFiles/flexnlp_wrapper.dir/build

CMakeFiles/flexnlp_wrapper.dir/requires: CMakeFiles/flexnlp_wrapper.dir/src/tiramisu_flexnlp_wrappers.cpp.o.requires

.PHONY : CMakeFiles/flexnlp_wrapper.dir/requires

CMakeFiles/flexnlp_wrapper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flexnlp_wrapper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flexnlp_wrapper.dir/clean

CMakeFiles/flexnlp_wrapper.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles/flexnlp_wrapper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flexnlp_wrapper.dir/depend

