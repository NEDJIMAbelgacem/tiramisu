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

# Utility rule file for run_benchmark_gaussian.

# Include the progress variables for this target.
include CMakeFiles/run_benchmark_gaussian.dir/progress.make

CMakeFiles/run_benchmark_gaussian:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/bench_gaussian

run_benchmark_gaussian: CMakeFiles/run_benchmark_gaussian
run_benchmark_gaussian: CMakeFiles/run_benchmark_gaussian.dir/build.make

.PHONY : run_benchmark_gaussian

# Rule to build all files generated by this target.
CMakeFiles/run_benchmark_gaussian.dir/build: run_benchmark_gaussian

.PHONY : CMakeFiles/run_benchmark_gaussian.dir/build

CMakeFiles/run_benchmark_gaussian.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_benchmark_gaussian.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_benchmark_gaussian.dir/clean

CMakeFiles/run_benchmark_gaussian.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles/run_benchmark_gaussian.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_benchmark_gaussian.dir/depend
