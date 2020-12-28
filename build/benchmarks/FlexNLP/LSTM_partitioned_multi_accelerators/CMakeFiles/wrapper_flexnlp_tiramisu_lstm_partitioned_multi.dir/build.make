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
include benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/depend.make

# Include the progress variables for this target.
include benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/progress.make

# Include the compile flags for this target's objects.
include benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flags.make

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flags.make
benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o: ../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/flexnlp_tiramisu_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o -c /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/flexnlp_tiramisu_wrapper.cpp

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.i"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/flexnlp_tiramisu_wrapper.cpp > CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.i

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.s"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/flexnlp_tiramisu_wrapper.cpp -o CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.s

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.requires:

.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.requires

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.provides: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.requires
	$(MAKE) -f benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/build.make benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.provides.build
.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.provides

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.provides.build: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o


# Object files for target wrapper_flexnlp_tiramisu_lstm_partitioned_multi
wrapper_flexnlp_tiramisu_lstm_partitioned_multi_OBJECTS = \
"CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o"

# External object files for target wrapper_flexnlp_tiramisu_lstm_partitioned_multi
wrapper_flexnlp_tiramisu_lstm_partitioned_multi_EXTERNAL_OBJECTS =

../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/build.make
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: ../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/generated_flexnlp_test.o
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: libtiramisu.so
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: ../3rdParty/Halide/lib/libHalide.a
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: ../3rdParty/isl/build/lib/libisl.so
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: libflexnlp_wrapper.a
../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi"
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/build: ../benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/wrapper_flexnlp_tiramisu_lstm_partitioned_multi

.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/build

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/requires: benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/flexnlp_tiramisu_wrapper.cpp.o.requires

.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/requires

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/clean:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators && $(CMAKE_COMMAND) -P CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/cmake_clean.cmake
.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/clean

benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/depend:
	cd /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators /data/scratch/belgacem_nedjima/tiramisu_fork/tiramisu/build/benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/FlexNLP/LSTM_partitioned_multi_accelerators/CMakeFiles/wrapper_flexnlp_tiramisu_lstm_partitioned_multi.dir/depend

