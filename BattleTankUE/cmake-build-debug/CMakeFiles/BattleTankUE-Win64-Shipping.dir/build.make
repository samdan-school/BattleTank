# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/lesam/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/lesam/.CLion2019.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/cmake-build-debug"

# Utility rule file for BattleTankUE-Win64-Shipping.

# Include the progress variables for this target.
include CMakeFiles/BattleTankUE-Win64-Shipping.dir/progress.make

CMakeFiles/BattleTankUE-Win64-Shipping:
	call C:/Program_Files_D/UE_4.22/Engine/Build/BatchFiles/Build.bat BattleTankUE Win64 Shipping "-project=C:/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/BattleTankUE.uproject" -game -progress -buildscw

BattleTankUE-Win64-Shipping: CMakeFiles/BattleTankUE-Win64-Shipping
BattleTankUE-Win64-Shipping: CMakeFiles/BattleTankUE-Win64-Shipping.dir/build.make

.PHONY : BattleTankUE-Win64-Shipping

# Rule to build all files generated by this target.
CMakeFiles/BattleTankUE-Win64-Shipping.dir/build: BattleTankUE-Win64-Shipping

.PHONY : CMakeFiles/BattleTankUE-Win64-Shipping.dir/build

CMakeFiles/BattleTankUE-Win64-Shipping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BattleTankUE-Win64-Shipping.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BattleTankUE-Win64-Shipping.dir/clean

CMakeFiles/BattleTankUE-Win64-Shipping.dir/depend:
	cd "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE" "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE" "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/cmake-build-debug" "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/cmake-build-debug" "/cygdrive/c/Users/lesam/OneDrive/Documents/Unreal Projects/BattleTank/BattleTankUE/cmake-build-debug/CMakeFiles/BattleTankUE-Win64-Shipping.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BattleTankUE-Win64-Shipping.dir/depend

