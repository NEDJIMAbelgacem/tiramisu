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

# Utility rule file for run_flexnlp_tiramisu_test.

# Include the progress variables for this target.
include benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/progress.make

benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated tiramisu executable in /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator

run_flexnlp_tiramisu_test: benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test
run_flexnlp_tiramisu_test: benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/build.make

.PHONY : run_flexnlp_tiramisu_test

# Rule to build all files generated by this target.
benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/build: run_flexnlp_tiramisu_test

.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/build

benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && $(CMAKE_COMMAND) -P CMakeFiles/run_flexnlp_tiramisu_test.dir/cmake_clean.cmake
.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/clean

benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/run_flexnlp_tiramisu_test.dir/depend
