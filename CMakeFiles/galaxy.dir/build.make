# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# Include any dependencies generated for this target.
include CMakeFiles/galaxy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/galaxy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/galaxy.dir/flags.make

CMakeFiles/galaxy.dir/src/gal/map.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/map.cpp.o: src/gal/map.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/map.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/map.cpp

CMakeFiles/galaxy.dir/src/gal/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/map.cpp > CMakeFiles/galaxy.dir/src/gal/map.cpp.i

CMakeFiles/galaxy.dir/src/gal/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/map.cpp -o CMakeFiles/galaxy.dir/src/gal/map.cpp.s

CMakeFiles/galaxy.dir/src/gal/map.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/map.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/map.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/map.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/map.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/map.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/map.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/map.cpp.o

CMakeFiles/galaxy.dir/src/gal/except.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/except.cpp.o: src/gal/except.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/except.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/except.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/except.cpp

CMakeFiles/galaxy.dir/src/gal/except.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/except.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/except.cpp > CMakeFiles/galaxy.dir/src/gal/except.cpp.i

CMakeFiles/galaxy.dir/src/gal/except.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/except.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/except.cpp -o CMakeFiles/galaxy.dir/src/gal/except.cpp.s

CMakeFiles/galaxy.dir/src/gal/except.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/except.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/except.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/except.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/except.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/except.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/except.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/except.cpp.o

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o: src/gal/stack_trace.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/stack_trace.cpp

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/stack_trace.cpp > CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.i

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/stack_trace.cpp -o CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.s

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o: src/gal/network/message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/network/message.cpp

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/network/message.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/network/message.cpp > CMakeFiles/galaxy.dir/src/gal/network/message.cpp.i

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/network/message.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/network/message.cpp -o CMakeFiles/galaxy.dir/src/gal/network/message.cpp.s

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o: src/gal/network/communicating.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/network/communicating.cpp

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/network/communicating.cpp > CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.i

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/network/communicating.cpp -o CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.s

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o: src/gal/network/server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/network/server.cpp

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/network/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/network/server.cpp > CMakeFiles/galaxy.dir/src/gal/network/server.cpp.i

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/network/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/network/server.cpp -o CMakeFiles/galaxy.dir/src/gal/network/server.cpp.s

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o: src/gal/network/client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/network/client.cpp

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/network/client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/network/client.cpp > CMakeFiles/galaxy.dir/src/gal/network/client.cpp.i

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/network/client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/network/client.cpp -o CMakeFiles/galaxy.dir/src/gal/network/client.cpp.s

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o: src/gal/control/control.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/control/control.cpp

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/control/control.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/control/control.cpp > CMakeFiles/galaxy.dir/src/gal/control/control.cpp.i

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/control/control.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/control/control.cpp -o CMakeFiles/galaxy.dir/src/gal/control/control.cpp.s

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o: CMakeFiles/galaxy.dir/flags.make
CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o: src/gal/timer/timer_set.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/charles/Programming/C++/galaxy/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o -c /home/charles/Programming/C++/galaxy/src/gal/timer/timer_set.cpp

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/charles/Programming/C++/galaxy/src/gal/timer/timer_set.cpp > CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.i

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/charles/Programming/C++/galaxy/src/gal/timer/timer_set.cpp -o CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.s

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.requires:
.PHONY : CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.requires

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.provides: CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.requires
	$(MAKE) -f CMakeFiles/galaxy.dir/build.make CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.provides.build
.PHONY : CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.provides

CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.provides.build: CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o

# Object files for target galaxy
galaxy_OBJECTS = \
"CMakeFiles/galaxy.dir/src/gal/map.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/except.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o" \
"CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o"

# External object files for target galaxy
galaxy_EXTERNAL_OBJECTS =

libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/map.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/except.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o
libgalaxy.a: CMakeFiles/galaxy.dir/build.make
libgalaxy.a: CMakeFiles/galaxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgalaxy.a"
	$(CMAKE_COMMAND) -P CMakeFiles/galaxy.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/galaxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/galaxy.dir/build: libgalaxy.a
.PHONY : CMakeFiles/galaxy.dir/build

CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/map.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/except.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/stack_trace.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/network/message.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/network/communicating.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/network/server.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/network/client.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/control/control.cpp.o.requires
CMakeFiles/galaxy.dir/requires: CMakeFiles/galaxy.dir/src/gal/timer/timer_set.cpp.o.requires
.PHONY : CMakeFiles/galaxy.dir/requires

CMakeFiles/galaxy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/galaxy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/galaxy.dir/clean

CMakeFiles/galaxy.dir/depend:
	cd /home/charles/Programming/C++/galaxy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/Programming/C++/galaxy /home/charles/Programming/C++/galaxy /home/charles/Programming/C++/galaxy /home/charles/Programming/C++/galaxy /home/charles/Programming/C++/galaxy/CMakeFiles/galaxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/galaxy.dir/depend

