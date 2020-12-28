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

# Utility rule file for run_spconv_relu_maxpool_3_16_224.

# Include the progress variables for this target.
include benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/progress.make

benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated tiramisu executable in /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224 && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/spconv_relu_maxpool_generator_3_16_224

run_spconv_relu_maxpool_3_16_224: benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224
run_spconv_relu_maxpool_3_16_224: benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/build.make

.PHONY : run_spconv_relu_maxpool_3_16_224

# Rule to build all files generated by this target.
benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/build: run_spconv_relu_maxpool_3_16_224

.PHONY : benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/build

benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224 && $(CMAKE_COMMAND) -P CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/clean

benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224 /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224 /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/blocks/Conv-ReLU-MaxPool/cpu/sparse_3_16_224/CMakeFiles/run_spconv_relu_maxpool_3_16_224.dir/depend

