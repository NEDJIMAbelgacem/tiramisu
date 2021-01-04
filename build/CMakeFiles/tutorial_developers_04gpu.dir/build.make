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
include CMakeFiles/tutorial_developers_04gpu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial_developers_04gpu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial_developers_04gpu.dir/flags.make

generated_fct_developers_tutorial_04gpu.o: developers_tutorial_04gpu_fct_generator
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating generated_fct_developers_tutorial_04gpu.o, generated_fct_developers_tutorial_04gpu.o_gpu.o, generated_fct_developers_tutorial_04gpu.o_cpu.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu && /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/developers_tutorial_04gpu_fct_generator

generated_fct_developers_tutorial_04gpu.o_gpu.o: generated_fct_developers_tutorial_04gpu.o
	@$(CMAKE_COMMAND) -E touch_nocreate generated_fct_developers_tutorial_04gpu.o_gpu.o

generated_fct_developers_tutorial_04gpu.o_cpu.o: generated_fct_developers_tutorial_04gpu.o
	@$(CMAKE_COMMAND) -E touch_nocreate generated_fct_developers_tutorial_04gpu.o_cpu.o

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o: CMakeFiles/tutorial_developers_04gpu.dir/flags.make
CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o: ../tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp > CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.i

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp -o CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.s

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.requires:

.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.requires

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.provides: CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.requires
	$(MAKE) -f CMakeFiles/tutorial_developers_04gpu.dir/build.make CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.provides.build
.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.provides

CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.provides.build: CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o


# Object files for target tutorial_developers_04gpu
tutorial_developers_04gpu_OBJECTS = \
"CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o"

# External object files for target tutorial_developers_04gpu
tutorial_developers_04gpu_EXTERNAL_OBJECTS = \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_developers_tutorial_04gpu.o" \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_developers_tutorial_04gpu.o_gpu.o" \
"/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/generated_fct_developers_tutorial_04gpu.o_cpu.o"

tutorial_developers_04gpu: CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o
tutorial_developers_04gpu: generated_fct_developers_tutorial_04gpu.o
tutorial_developers_04gpu: generated_fct_developers_tutorial_04gpu.o_gpu.o
tutorial_developers_04gpu: generated_fct_developers_tutorial_04gpu.o_cpu.o
tutorial_developers_04gpu: CMakeFiles/tutorial_developers_04gpu.dir/build.make
tutorial_developers_04gpu: libtiramisu.so
tutorial_developers_04gpu: ../3rdParty/Halide/lib/libHalide.a
tutorial_developers_04gpu: ../3rdParty/isl/build/lib/libisl.so
tutorial_developers_04gpu: libcuda_wrapper.a
tutorial_developers_04gpu: /usr/local/cuda/lib64/libcudart_static.a
tutorial_developers_04gpu: /usr/lib/x86_64-linux-gnu/librt.so
tutorial_developers_04gpu: /usr/local/cuda/lib64/libcublas.so
tutorial_developers_04gpu: CMakeFiles/tutorial_developers_04gpu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tutorial_developers_04gpu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial_developers_04gpu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tutorial_developers_04gpu.dir/build: tutorial_developers_04gpu

.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/build

CMakeFiles/tutorial_developers_04gpu.dir/requires: CMakeFiles/tutorial_developers_04gpu.dir/tutorials/developers/tutorial_04gpu/wrapper_tutorial_04gpu.cpp.o.requires

.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/requires

CMakeFiles/tutorial_developers_04gpu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial_developers_04gpu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/clean

CMakeFiles/tutorial_developers_04gpu.dir/depend: generated_fct_developers_tutorial_04gpu.o
CMakeFiles/tutorial_developers_04gpu.dir/depend: generated_fct_developers_tutorial_04gpu.o_gpu.o
CMakeFiles/tutorial_developers_04gpu.dir/depend: generated_fct_developers_tutorial_04gpu.o_cpu.o
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles/tutorial_developers_04gpu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial_developers_04gpu.dir/depend
