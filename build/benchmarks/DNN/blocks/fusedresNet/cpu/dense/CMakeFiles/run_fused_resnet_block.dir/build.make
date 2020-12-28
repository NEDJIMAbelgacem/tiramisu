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

# Utility rule file for run_fused_resnet_block.

# Include the progress variables for this target.
include benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/progress.make

benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated tiramisu executable in /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/fusedresNet/cpu/dense"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/fusedresNet/cpu/dense && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/fusedresNet/cpu/dense/fused_resnet_block_generator_tiramisu

run_fused_resnet_block: benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block
run_fused_resnet_block: benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/build.make

.PHONY : run_fused_resnet_block

# Rule to build all files generated by this target.
benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/build: run_fused_resnet_block

.PHONY : benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/build

benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/fusedresNet/cpu/dense && $(CMAKE_COMMAND) -P CMakeFiles/run_fused_resnet_block.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/clean

benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/fusedresNet/cpu/dense /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/fusedresNet/cpu/dense /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/blocks/fusedresNet/cpu/dense/CMakeFiles/run_fused_resnet_block.dir/depend

