# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_SOURCE_DIR = /home/booboo/Documents/Code/CIS023/Lab1/L1-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/booboo/Documents/Code/CIS023/Lab1/L1-1

# Include any dependencies generated for this target.
include CMakeFiles/dieProgram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dieProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dieProgram.dir/flags.make

CMakeFiles/dieProgram.dir/die.cpp.o: CMakeFiles/dieProgram.dir/flags.make
CMakeFiles/dieProgram.dir/die.cpp.o: die.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/booboo/Documents/Code/CIS023/Lab1/L1-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dieProgram.dir/die.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dieProgram.dir/die.cpp.o -c /home/booboo/Documents/Code/CIS023/Lab1/L1-1/die.cpp

CMakeFiles/dieProgram.dir/die.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dieProgram.dir/die.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/booboo/Documents/Code/CIS023/Lab1/L1-1/die.cpp > CMakeFiles/dieProgram.dir/die.cpp.i

CMakeFiles/dieProgram.dir/die.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dieProgram.dir/die.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/booboo/Documents/Code/CIS023/Lab1/L1-1/die.cpp -o CMakeFiles/dieProgram.dir/die.cpp.s

CMakeFiles/dieProgram.dir/main.cpp.o: CMakeFiles/dieProgram.dir/flags.make
CMakeFiles/dieProgram.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/booboo/Documents/Code/CIS023/Lab1/L1-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dieProgram.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dieProgram.dir/main.cpp.o -c /home/booboo/Documents/Code/CIS023/Lab1/L1-1/main.cpp

CMakeFiles/dieProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dieProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/booboo/Documents/Code/CIS023/Lab1/L1-1/main.cpp > CMakeFiles/dieProgram.dir/main.cpp.i

CMakeFiles/dieProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dieProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/booboo/Documents/Code/CIS023/Lab1/L1-1/main.cpp -o CMakeFiles/dieProgram.dir/main.cpp.s

# Object files for target dieProgram
dieProgram_OBJECTS = \
"CMakeFiles/dieProgram.dir/die.cpp.o" \
"CMakeFiles/dieProgram.dir/main.cpp.o"

# External object files for target dieProgram
dieProgram_EXTERNAL_OBJECTS =

dieProgram: CMakeFiles/dieProgram.dir/die.cpp.o
dieProgram: CMakeFiles/dieProgram.dir/main.cpp.o
dieProgram: CMakeFiles/dieProgram.dir/build.make
dieProgram: CMakeFiles/dieProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/booboo/Documents/Code/CIS023/Lab1/L1-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable dieProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dieProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dieProgram.dir/build: dieProgram

.PHONY : CMakeFiles/dieProgram.dir/build

CMakeFiles/dieProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dieProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dieProgram.dir/clean

CMakeFiles/dieProgram.dir/depend:
	cd /home/booboo/Documents/Code/CIS023/Lab1/L1-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/booboo/Documents/Code/CIS023/Lab1/L1-1 /home/booboo/Documents/Code/CIS023/Lab1/L1-1 /home/booboo/Documents/Code/CIS023/Lab1/L1-1 /home/booboo/Documents/Code/CIS023/Lab1/L1-1 /home/booboo/Documents/Code/CIS023/Lab1/L1-1/CMakeFiles/dieProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dieProgram.dir/depend

