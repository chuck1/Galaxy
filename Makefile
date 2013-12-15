# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charles/Programming/C++/galaxy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/Programming/C++/galaxy

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/charles/Programming/C++/galaxy/CMakeFiles /home/charles/Programming/C++/galaxy/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/charles/Programming/C++/galaxy/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named galaxy

# Build rule for target.
galaxy: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 galaxy
.PHONY : galaxy

# fast build rule for target.
galaxy/fast:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/build
.PHONY : galaxy/fast

#=============================================================================
# Target rules for targets named test_asio

# Build rule for target.
test_asio: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_asio
.PHONY : test_asio

# fast build rule for target.
test_asio/fast:
	$(MAKE) -f CMakeFiles/test_asio.dir/build.make CMakeFiles/test_asio.dir/build
.PHONY : test_asio/fast

#=============================================================================
# Target rules for targets named test_map

# Build rule for target.
test_map: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_map
.PHONY : test_map

# fast build rule for target.
test_map/fast:
	$(MAKE) -f CMakeFiles/test_map.dir/build.make CMakeFiles/test_map.dir/build
.PHONY : test_map/fast

src/gal/asio/message.o: src/gal/asio/message.cpp.o
.PHONY : src/gal/asio/message.o

# target to build an object file
src/gal/asio/message.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/message.cpp.o
.PHONY : src/gal/asio/message.cpp.o

src/gal/asio/message.i: src/gal/asio/message.cpp.i
.PHONY : src/gal/asio/message.i

# target to preprocess a source file
src/gal/asio/message.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/message.cpp.i
.PHONY : src/gal/asio/message.cpp.i

src/gal/asio/message.s: src/gal/asio/message.cpp.s
.PHONY : src/gal/asio/message.s

# target to generate assembly for a file
src/gal/asio/message.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/message.cpp.s
.PHONY : src/gal/asio/message.cpp.s

src/gal/asio/network/client.o: src/gal/asio/network/client.cpp.o
.PHONY : src/gal/asio/network/client.o

# target to build an object file
src/gal/asio/network/client.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/client.cpp.o
.PHONY : src/gal/asio/network/client.cpp.o

src/gal/asio/network/client.i: src/gal/asio/network/client.cpp.i
.PHONY : src/gal/asio/network/client.i

# target to preprocess a source file
src/gal/asio/network/client.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/client.cpp.i
.PHONY : src/gal/asio/network/client.cpp.i

src/gal/asio/network/client.s: src/gal/asio/network/client.cpp.s
.PHONY : src/gal/asio/network/client.s

# target to generate assembly for a file
src/gal/asio/network/client.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/client.cpp.s
.PHONY : src/gal/asio/network/client.cpp.s

src/gal/asio/network/communicating.o: src/gal/asio/network/communicating.cpp.o
.PHONY : src/gal/asio/network/communicating.o

# target to build an object file
src/gal/asio/network/communicating.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/communicating.cpp.o
.PHONY : src/gal/asio/network/communicating.cpp.o

src/gal/asio/network/communicating.i: src/gal/asio/network/communicating.cpp.i
.PHONY : src/gal/asio/network/communicating.i

# target to preprocess a source file
src/gal/asio/network/communicating.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/communicating.cpp.i
.PHONY : src/gal/asio/network/communicating.cpp.i

src/gal/asio/network/communicating.s: src/gal/asio/network/communicating.cpp.s
.PHONY : src/gal/asio/network/communicating.s

# target to generate assembly for a file
src/gal/asio/network/communicating.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/communicating.cpp.s
.PHONY : src/gal/asio/network/communicating.cpp.s

src/gal/asio/network/server.o: src/gal/asio/network/server.cpp.o
.PHONY : src/gal/asio/network/server.o

# target to build an object file
src/gal/asio/network/server.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/server.cpp.o
.PHONY : src/gal/asio/network/server.cpp.o

src/gal/asio/network/server.i: src/gal/asio/network/server.cpp.i
.PHONY : src/gal/asio/network/server.i

# target to preprocess a source file
src/gal/asio/network/server.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/server.cpp.i
.PHONY : src/gal/asio/network/server.cpp.i

src/gal/asio/network/server.s: src/gal/asio/network/server.cpp.s
.PHONY : src/gal/asio/network/server.s

# target to generate assembly for a file
src/gal/asio/network/server.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/asio/network/server.cpp.s
.PHONY : src/gal/asio/network/server.cpp.s

src/gal/except.o: src/gal/except.cpp.o
.PHONY : src/gal/except.o

# target to build an object file
src/gal/except.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/except.cpp.o
.PHONY : src/gal/except.cpp.o

src/gal/except.i: src/gal/except.cpp.i
.PHONY : src/gal/except.i

# target to preprocess a source file
src/gal/except.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/except.cpp.i
.PHONY : src/gal/except.cpp.i

src/gal/except.s: src/gal/except.cpp.s
.PHONY : src/gal/except.s

# target to generate assembly for a file
src/gal/except.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/except.cpp.s
.PHONY : src/gal/except.cpp.s

src/gal/flag.o: src/gal/flag.cpp.o
.PHONY : src/gal/flag.o

# target to build an object file
src/gal/flag.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/flag.cpp.o
.PHONY : src/gal/flag.cpp.o

src/gal/flag.i: src/gal/flag.cpp.i
.PHONY : src/gal/flag.i

# target to preprocess a source file
src/gal/flag.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/flag.cpp.i
.PHONY : src/gal/flag.cpp.i

src/gal/flag.s: src/gal/flag.cpp.s
.PHONY : src/gal/flag.s

# target to generate assembly for a file
src/gal/flag.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/flag.cpp.s
.PHONY : src/gal/flag.cpp.s

src/gal/map.o: src/gal/map.cpp.o
.PHONY : src/gal/map.o

# target to build an object file
src/gal/map.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/map.cpp.o
.PHONY : src/gal/map.cpp.o

src/gal/map.i: src/gal/map.cpp.i
.PHONY : src/gal/map.i

# target to preprocess a source file
src/gal/map.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/map.cpp.i
.PHONY : src/gal/map.cpp.i

src/gal/map.s: src/gal/map.cpp.s
.PHONY : src/gal/map.s

# target to generate assembly for a file
src/gal/map.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/map.cpp.s
.PHONY : src/gal/map.cpp.s

src/gal/stack_trace.o: src/gal/stack_trace.cpp.o
.PHONY : src/gal/stack_trace.o

# target to build an object file
src/gal/stack_trace.cpp.o:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o
.PHONY : src/gal/stack_trace.cpp.o

src/gal/stack_trace.i: src/gal/stack_trace.cpp.i
.PHONY : src/gal/stack_trace.i

# target to preprocess a source file
src/gal/stack_trace.cpp.i:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.i
.PHONY : src/gal/stack_trace.cpp.i

src/gal/stack_trace.s: src/gal/stack_trace.cpp.s
.PHONY : src/gal/stack_trace.s

# target to generate assembly for a file
src/gal/stack_trace.cpp.s:
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.s
.PHONY : src/gal/stack_trace.cpp.s

test/asio/main.o: test/asio/main.cpp.o
.PHONY : test/asio/main.o

# target to build an object file
test/asio/main.cpp.o:
	$(MAKE) -f CMakeFiles/test_asio.dir/build.make CMakeFiles/test_asio.dir/test/asio/main.cpp.o
.PHONY : test/asio/main.cpp.o

test/asio/main.i: test/asio/main.cpp.i
.PHONY : test/asio/main.i

# target to preprocess a source file
test/asio/main.cpp.i:
	$(MAKE) -f CMakeFiles/test_asio.dir/build.make CMakeFiles/test_asio.dir/test/asio/main.cpp.i
.PHONY : test/asio/main.cpp.i

test/asio/main.s: test/asio/main.cpp.s
.PHONY : test/asio/main.s

# target to generate assembly for a file
test/asio/main.cpp.s:
	$(MAKE) -f CMakeFiles/test_asio.dir/build.make CMakeFiles/test_asio.dir/test/asio/main.cpp.s
.PHONY : test/asio/main.cpp.s

test/map/main.o: test/map/main.cpp.o
.PHONY : test/map/main.o

# target to build an object file
test/map/main.cpp.o:
	$(MAKE) -f CMakeFiles/test_map.dir/build.make CMakeFiles/test_map.dir/test/map/main.cpp.o
.PHONY : test/map/main.cpp.o

test/map/main.i: test/map/main.cpp.i
.PHONY : test/map/main.i

# target to preprocess a source file
test/map/main.cpp.i:
	$(MAKE) -f CMakeFiles/test_map.dir/build.make CMakeFiles/test_map.dir/test/map/main.cpp.i
.PHONY : test/map/main.cpp.i

test/map/main.s: test/map/main.cpp.s
.PHONY : test/map/main.s

# target to generate assembly for a file
test/map/main.cpp.s:
	$(MAKE) -f CMakeFiles/test_map.dir/build.make CMakeFiles/test_map.dir/test/map/main.cpp.s
.PHONY : test/map/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... galaxy"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test_asio"
	@echo "... test_map"
	@echo "... src/gal/asio/message.o"
	@echo "... src/gal/asio/message.i"
	@echo "... src/gal/asio/message.s"
	@echo "... src/gal/asio/network/client.o"
	@echo "... src/gal/asio/network/client.i"
	@echo "... src/gal/asio/network/client.s"
	@echo "... src/gal/asio/network/communicating.o"
	@echo "... src/gal/asio/network/communicating.i"
	@echo "... src/gal/asio/network/communicating.s"
	@echo "... src/gal/asio/network/server.o"
	@echo "... src/gal/asio/network/server.i"
	@echo "... src/gal/asio/network/server.s"
	@echo "... src/gal/except.o"
	@echo "... src/gal/except.i"
	@echo "... src/gal/except.s"
	@echo "... src/gal/flag.o"
	@echo "... src/gal/flag.i"
	@echo "... src/gal/flag.s"
	@echo "... src/gal/map.o"
	@echo "... src/gal/map.i"
	@echo "... src/gal/map.s"
	@echo "... src/gal/stack_trace.o"
	@echo "... src/gal/stack_trace.i"
	@echo "... src/gal/stack_trace.s"
	@echo "... test/asio/main.o"
	@echo "... test/asio/main.i"
	@echo "... test/asio/main.s"
	@echo "... test/map/main.o"
	@echo "... test/map/main.i"
	@echo "... test/map/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

