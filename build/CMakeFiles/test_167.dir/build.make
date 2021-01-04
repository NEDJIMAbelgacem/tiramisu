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
include CMakeFiles/test_167.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_167.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_167.dir/flags.make

generated_fct_test_167.o: test_167_fct_generator
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating generated_fct_test_167.o, generated_fct_test_167.o_gpu.o, generated_fct_test_167.o_cpu.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/test_167_fct_generator

generated_fct_test_167.o_gpu.o: generated_fct_test_167.o
	@$(CMAKE_COMMAND) -E touch_nocreate generated_fct_test_167.o_gpu.o

generated_fct_test_167.o_cpu.o: generated_fct_test_167.o
	@$(CMAKE_COMMAND) -E touch_nocreate generated_fct_test_167.o_cpu.o

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o: CMakeFiles/test_167.dir/flags.make
CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o: ../tests/wrapper_test_167.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tests/wrapper_test_167.cpp

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tests/wrapper_test_167.cpp > CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.i

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tests/wrapper_test_167.cpp -o CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.s

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.requires:

.PHONY : CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.requires

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.provides: CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_167.dir/build.make CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.provides.build
.PHONY : CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.provides

CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.provides.build: CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o


# Object files for target test_167
test_167_OBJECTS = \
"CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o"

# External object files for target test_167
test_167_EXTERNAL_OBJECTS = \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_test_167.o" \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_test_167.o_gpu.o" \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_test_167.o_cpu.o"

test_167: CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o
test_167: generated_fct_test_167.o
test_167: generated_fct_test_167.o_gpu.o
test_167: generated_fct_test_167.o_cpu.o
test_167: CMakeFiles/test_167.dir/build.make
test_167: libtiramisu.so
test_167: ../3rdParty/Halide/lib/libHalide.a
test_167: ../3rdParty/isl/build/lib/libisl.so
test_167: libcuda_wrapper.a
test_167: /usr/local/cuda/lib64/libcudart_static.a
test_167: /usr/lib/x86_64-linux-gnu/librt.so
test_167: /usr/local/cuda/lib64/libcublas.so
test_167: CMakeFiles/test_167.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_167"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_167.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_167.dir/build: test_167

.PHONY : CMakeFiles/test_167.dir/build

CMakeFiles/test_167.dir/requires: CMakeFiles/test_167.dir/tests/wrapper_test_167.cpp.o.requires

.PHONY : CMakeFiles/test_167.dir/requires

CMakeFiles/test_167.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_167.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_167.dir/clean

CMakeFiles/test_167.dir/depend: generated_fct_test_167.o
CMakeFiles/test_167.dir/depend: generated_fct_test_167.o_gpu.o
CMakeFiles/test_167.dir/depend: generated_fct_test_167.o_cpu.o
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles/test_167.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_167.dir/depend
