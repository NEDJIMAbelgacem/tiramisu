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
include benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/depend.make

# Include the progress variables for this target.
include benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/progress.make

# Include the compile flags for this target's objects.
include benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/flags.make

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/flags.make
benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o: ../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/conv_relu_conv_relu_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/conv_relu_conv_relu_wrapper.cpp

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.i"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/conv_relu_conv_relu_wrapper.cpp > CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.i

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.s"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/conv_relu_conv_relu_wrapper.cpp -o CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.s

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.requires:

.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.requires

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.provides: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.requires
	$(MAKE) -f benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/build.make benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.provides.build
.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.provides

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.provides.build: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o


# Object files for target wrapper_sparse_conv_relu_conv_relu
wrapper_sparse_conv_relu_conv_relu_OBJECTS = \
"CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o"

# External object files for target wrapper_sparse_conv_relu_conv_relu
wrapper_sparse_conv_relu_conv_relu_EXTERNAL_OBJECTS =

../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/build.make
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: ../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/generated_sparse_conv_relu_conv_relu_512_512_14_tiramisu.o
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: libtiramisu.so
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: ../3rdParty/Halide/lib/libHalide.a
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: ../3rdParty/isl/build/lib/libisl.so
../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../../../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/build: ../benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/wrapper_sparse_conv_relu_conv_relu

.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/build

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/requires: benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/conv_relu_conv_relu_wrapper.cpp.o.requires

.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/requires

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 && $(CMAKE_COMMAND) -P CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/clean

benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14 /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/blocks/Conv-ReLU-Conv-ReLU/cpu/sparse_32channels_512_512_14/CMakeFiles/wrapper_sparse_conv_relu_conv_relu.dir/depend

