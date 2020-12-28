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

# Utility rule file for run_benchmark_gpu_gemm_correctness.

# Include the progress variables for this target.
include benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/progress.make

benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness: benchmark_gpu_gemm_wrapper
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/linear_algebra/blas/level3/sgemm/gpu && ../../../../../../benchmark_gpu_gemm_wrapper 0 1

run_benchmark_gpu_gemm_correctness: benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness
run_benchmark_gpu_gemm_correctness: benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/build.make

.PHONY : run_benchmark_gpu_gemm_correctness

# Rule to build all files generated by this target.
benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/build: run_benchmark_gpu_gemm_correctness

.PHONY : benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/build

benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/linear_algebra/blas/level3/sgemm/gpu && $(CMAKE_COMMAND) -P CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/cmake_clean.cmake
.PHONY : benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/clean

benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/linear_algebra/blas/level3/sgemm/gpu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/linear_algebra/blas/level3/sgemm/gpu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/linear_algebra/blas/level3/sgemm/gpu/CMakeFiles/run_benchmark_gpu_gemm_correctness.dir/depend

