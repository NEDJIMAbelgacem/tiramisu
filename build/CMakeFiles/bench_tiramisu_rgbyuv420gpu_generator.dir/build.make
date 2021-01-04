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
include CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/flags.make

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/flags.make
CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o: ../benchmarks/halide/rgbyuv420gpu_tiramisu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp > CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.i

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp -o CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.s

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.requires:

.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.requires

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.provides: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.requires
	$(MAKE) -f CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/build.make CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.provides.build
.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.provides

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.provides.build: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o


# Object files for target bench_tiramisu_rgbyuv420gpu_generator
bench_tiramisu_rgbyuv420gpu_generator_OBJECTS = \
"CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o"

# External object files for target bench_tiramisu_rgbyuv420gpu_generator
bench_tiramisu_rgbyuv420gpu_generator_EXTERNAL_OBJECTS =

bench_tiramisu_rgbyuv420gpu_generator: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o
bench_tiramisu_rgbyuv420gpu_generator: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/build.make
bench_tiramisu_rgbyuv420gpu_generator: libtiramisu.so
bench_tiramisu_rgbyuv420gpu_generator: ../3rdParty/Halide/lib/libHalide.a
bench_tiramisu_rgbyuv420gpu_generator: ../3rdParty/isl/build/lib/libisl.so
bench_tiramisu_rgbyuv420gpu_generator: libcuda_wrapper.a
bench_tiramisu_rgbyuv420gpu_generator: /usr/local/cuda/lib64/libcudart_static.a
bench_tiramisu_rgbyuv420gpu_generator: /usr/lib/x86_64-linux-gnu/librt.so
bench_tiramisu_rgbyuv420gpu_generator: /usr/local/cuda/lib64/libcublas.so
bench_tiramisu_rgbyuv420gpu_generator: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bench_tiramisu_rgbyuv420gpu_generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/build: bench_tiramisu_rgbyuv420gpu_generator

.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/build

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/requires: CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/benchmarks/halide/rgbyuv420gpu_tiramisu.cpp.o.requires

.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/requires

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/clean

CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bench_tiramisu_rgbyuv420gpu_generator.dir/depend
