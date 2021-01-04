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
include benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/depend.make

# Include the progress variables for this target.
include benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/progress.make

# Include the compile flags for this target's objects.
include benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/flags.make

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/flags.make
benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o: ../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper.cpp

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.i"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper.cpp > CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.i

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.s"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper.cpp -o CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.s

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.requires:

.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.requires

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.provides: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.requires
	$(MAKE) -f benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/build.make benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.provides.build
.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.provides

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.provides.build: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o


# Object files for target sparse_vgg_block_32_wrapper
sparse_vgg_block_32_wrapper_OBJECTS = \
"CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o"

# External object files for target sparse_vgg_block_32_wrapper
sparse_vgg_block_32_wrapper_EXTERNAL_OBJECTS =

../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/build.make
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: ../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/generated_sparse_vgg_block_32.o
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: libtiramisu.so
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: ../3rdParty/Halide/lib/libHalide.a
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: ../3rdParty/isl/build/lib/libisl.so
../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../../../../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sparse_vgg_block_32_wrapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/build: ../benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/sparse_vgg_block_32_wrapper

.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/build

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/requires: benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/sparse_vgg_block_32_wrapper.cpp.o.requires

.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/requires

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels && $(CMAKE_COMMAND) -P CMakeFiles/sparse_vgg_block_32_wrapper.dir/cmake_clean.cmake
.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/clean

benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/DNN/blocks/vggBlock/cpu/sparse_32channels/CMakeFiles/sparse_vgg_block_32_wrapper.dir/depend
