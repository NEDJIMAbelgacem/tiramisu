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
include benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/depend.make

# Include the progress variables for this target.
include benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/progress.make

# Include the compile flags for this target's objects.
include benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flags.make

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flags.make
benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o: ../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator.cpp

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.i"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator.cpp > CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.i

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.s"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator.cpp -o CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.s

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.requires:

.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.requires

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.provides: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.requires
	$(MAKE) -f benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/build.make benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.provides.build
.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.provides

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.provides.build: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o


# Object files for target flexnlp_tiramisu_generator
flexnlp_tiramisu_generator_OBJECTS = \
"CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o"

# External object files for target flexnlp_tiramisu_generator
flexnlp_tiramisu_generator_EXTERNAL_OBJECTS =

../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o
../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/build.make
../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: libtiramisu.so
../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: ../3rdParty/Halide/lib/libHalide.a
../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: ../3rdParty/isl/build/lib/libisl.so
../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flexnlp_tiramisu_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/build: ../benchmarks/FlexNLP/LSTM/flexnlp_tiramisu_generator

.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/build

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/requires: benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/flexnlp_tiramisu_generator.cpp.o.requires

.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/requires

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM && $(CMAKE_COMMAND) -P CMakeFiles/flexnlp_tiramisu_generator.dir/cmake_clean.cmake
.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/clean

benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/FlexNLP/LSTM/CMakeFiles/flexnlp_tiramisu_generator.dir/depend

