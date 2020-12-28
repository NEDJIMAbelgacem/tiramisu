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
include benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/depend.make

# Include the progress variables for this target.
include benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/progress.make

# Include the compile flags for this target's objects.
include benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/flags.make

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/flags.make
benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o: ../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_layer_generator_tiramisu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_layer_generator_tiramisu.cpp

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.i"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_layer_generator_tiramisu.cpp > CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.i

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.s"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_layer_generator_tiramisu.cpp -o CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.s

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.requires:

.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.requires

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.provides: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.requires
	$(MAKE) -f benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/build.make benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.provides.build
.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.provides

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.provides.build: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o


# Object files for target conv_sparse_with_dense_layer_generator
conv_sparse_with_dense_layer_generator_OBJECTS = \
"CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o"

# External object files for target conv_sparse_with_dense_layer_generator
conv_sparse_with_dense_layer_generator_EXTERNAL_OBJECTS =

../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o
../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/build.make
../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: libtiramisu.so
../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: ../3rdParty/Halide/lib/libHalide.a
../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: ../3rdParty/isl/build/lib/libisl.so
../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../../../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conv_sparse_with_dense_layer_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/build: ../benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/conv_sparse_with_dense_layer_generator

.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/build

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/requires: benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/conv_layer_generator_tiramisu.cpp.o.requires

.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/requires

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense && $(CMAKE_COMMAND) -P CMakeFiles/conv_sparse_with_dense_layer_generator.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/clean

benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/layers/convolution/direct/cpu_sparse_with_dense/CMakeFiles/conv_sparse_with_dense_layer_generator.dir/depend

