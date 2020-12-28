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

# Utility rule file for run_maxpool_layer.

# Include the progress variables for this target.
include benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/progress.make

benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated tiramisu executable in /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/maxpool/cpu"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/maxpool/cpu && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/maxpool/cpu/maxpool_layer_generator_tiramisu

run_maxpool_layer: benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer
run_maxpool_layer: benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/build.make

.PHONY : run_maxpool_layer

# Rule to build all files generated by this target.
benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/build: run_maxpool_layer

.PHONY : benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/build

benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/maxpool/cpu && $(CMAKE_COMMAND) -P CMakeFiles/run_maxpool_layer.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/clean

benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/layers/maxpool/cpu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/maxpool/cpu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/layers/maxpool/cpu/CMakeFiles/run_maxpool_layer.dir/depend
