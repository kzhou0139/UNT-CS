# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kellyzhou/CLionProjects/ksz0009Project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ksz0009Project1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ksz0009Project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ksz0009Project1.dir/flags.make

CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o: CMakeFiles/ksz0009Project1.dir/flags.make
CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o: ../ksz0009Project1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o -c /Users/kellyzhou/CLionProjects/ksz0009Project1/ksz0009Project1.cpp

CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kellyzhou/CLionProjects/ksz0009Project1/ksz0009Project1.cpp > CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.i

CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kellyzhou/CLionProjects/ksz0009Project1/ksz0009Project1.cpp -o CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.s

# Object files for target ksz0009Project1
ksz0009Project1_OBJECTS = \
"CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o"

# External object files for target ksz0009Project1
ksz0009Project1_EXTERNAL_OBJECTS =

ksz0009Project1: CMakeFiles/ksz0009Project1.dir/ksz0009Project1.cpp.o
ksz0009Project1: CMakeFiles/ksz0009Project1.dir/build.make
ksz0009Project1: CMakeFiles/ksz0009Project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ksz0009Project1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ksz0009Project1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ksz0009Project1.dir/build: ksz0009Project1
.PHONY : CMakeFiles/ksz0009Project1.dir/build

CMakeFiles/ksz0009Project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ksz0009Project1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ksz0009Project1.dir/clean

CMakeFiles/ksz0009Project1.dir/depend:
	cd /Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kellyzhou/CLionProjects/ksz0009Project1 /Users/kellyzhou/CLionProjects/ksz0009Project1 /Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug /Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug /Users/kellyzhou/CLionProjects/ksz0009Project1/cmake-build-debug/CMakeFiles/ksz0009Project1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ksz0009Project1.dir/depend

