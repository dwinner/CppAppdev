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
CMAKE_SOURCE_DIR = F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/10_Standart_IO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/10_Standart_IO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10_Standart_IO.dir/flags.make

CMakeFiles/10_Standart_IO.dir/main.c.obj: CMakeFiles/10_Standart_IO.dir/flags.make
CMakeFiles/10_Standart_IO.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/10_Standart_IO.dir/main.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\10_Standart_IO.dir\main.c.obj   -c F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\main.c

CMakeFiles/10_Standart_IO.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/10_Standart_IO.dir/main.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\main.c > CMakeFiles\10_Standart_IO.dir\main.c.i

CMakeFiles/10_Standart_IO.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/10_Standart_IO.dir/main.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\main.c -o CMakeFiles\10_Standart_IO.dir\main.c.s

CMakeFiles/10_Standart_IO.dir/main.c.obj.requires:

.PHONY : CMakeFiles/10_Standart_IO.dir/main.c.obj.requires

CMakeFiles/10_Standart_IO.dir/main.c.obj.provides: CMakeFiles/10_Standart_IO.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\10_Standart_IO.dir\build.make CMakeFiles/10_Standart_IO.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/10_Standart_IO.dir/main.c.obj.provides

CMakeFiles/10_Standart_IO.dir/main.c.obj.provides.build: CMakeFiles/10_Standart_IO.dir/main.c.obj


# Object files for target 10_Standart_IO
10_Standart_IO_OBJECTS = \
"CMakeFiles/10_Standart_IO.dir/main.c.obj"

# External object files for target 10_Standart_IO
10_Standart_IO_EXTERNAL_OBJECTS =

10_Standart_IO.exe: CMakeFiles/10_Standart_IO.dir/main.c.obj
10_Standart_IO.exe: CMakeFiles/10_Standart_IO.dir/build.make
10_Standart_IO.exe: CMakeFiles/10_Standart_IO.dir/linklibs.rsp
10_Standart_IO.exe: CMakeFiles/10_Standart_IO.dir/objects1.rsp
10_Standart_IO.exe: CMakeFiles/10_Standart_IO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 10_Standart_IO.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\10_Standart_IO.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/10_Standart_IO.dir/build: 10_Standart_IO.exe

.PHONY : CMakeFiles/10_Standart_IO.dir/build

CMakeFiles/10_Standart_IO.dir/requires: CMakeFiles/10_Standart_IO.dir/main.c.obj.requires

.PHONY : CMakeFiles/10_Standart_IO.dir/requires

CMakeFiles/10_Standart_IO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\10_Standart_IO.dir\cmake_clean.cmake
.PHONY : CMakeFiles/10_Standart_IO.dir/clean

CMakeFiles/10_Standart_IO.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug F:\Public\CppAppDev\C.FileProcessing\10-Standart-IO\cmake-build-debug\CMakeFiles\10_Standart_IO.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/10_Standart_IO.dir/depend

