# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/8_Add_a_word.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/8_Add_a_word.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/8_Add_a_word.dir/flags.make

CMakeFiles/8_Add_a_word.dir/main.c.obj: CMakeFiles/8_Add_a_word.dir/flags.make
CMakeFiles/8_Add_a_word.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/8_Add_a_word.dir/main.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\8_Add_a_word.dir\main.c.obj   -c F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\main.c

CMakeFiles/8_Add_a_word.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/8_Add_a_word.dir/main.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\main.c > CMakeFiles\8_Add_a_word.dir\main.c.i

CMakeFiles/8_Add_a_word.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/8_Add_a_word.dir/main.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\main.c -o CMakeFiles\8_Add_a_word.dir\main.c.s

CMakeFiles/8_Add_a_word.dir/main.c.obj.requires:

.PHONY : CMakeFiles/8_Add_a_word.dir/main.c.obj.requires

CMakeFiles/8_Add_a_word.dir/main.c.obj.provides: CMakeFiles/8_Add_a_word.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\8_Add_a_word.dir\build.make CMakeFiles/8_Add_a_word.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/8_Add_a_word.dir/main.c.obj.provides

CMakeFiles/8_Add_a_word.dir/main.c.obj.provides.build: CMakeFiles/8_Add_a_word.dir/main.c.obj


# Object files for target 8_Add_a_word
8_Add_a_word_OBJECTS = \
"CMakeFiles/8_Add_a_word.dir/main.c.obj"

# External object files for target 8_Add_a_word
8_Add_a_word_EXTERNAL_OBJECTS =

8_Add_a_word.exe: CMakeFiles/8_Add_a_word.dir/main.c.obj
8_Add_a_word.exe: CMakeFiles/8_Add_a_word.dir/build.make
8_Add_a_word.exe: CMakeFiles/8_Add_a_word.dir/linklibs.rsp
8_Add_a_word.exe: CMakeFiles/8_Add_a_word.dir/objects1.rsp
8_Add_a_word.exe: CMakeFiles/8_Add_a_word.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 8_Add_a_word.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\8_Add_a_word.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/8_Add_a_word.dir/build: 8_Add_a_word.exe

.PHONY : CMakeFiles/8_Add_a_word.dir/build

CMakeFiles/8_Add_a_word.dir/requires: CMakeFiles/8_Add_a_word.dir/main.c.obj.requires

.PHONY : CMakeFiles/8_Add_a_word.dir/requires

CMakeFiles/8_Add_a_word.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\8_Add_a_word.dir\cmake_clean.cmake
.PHONY : CMakeFiles/8_Add_a_word.dir/clean

CMakeFiles/8_Add_a_word.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug F:\Public\CppAppDev\C.FileProcessing\8-Add_a_word\cmake-build-debug\CMakeFiles\8_Add_a_word.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/8_Add_a_word.dir/depend

