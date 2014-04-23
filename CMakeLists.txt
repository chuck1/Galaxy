cmake_minimum_required (VERSION 2.6)

project(galaxy)

find_package(math)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -g -Wall -std=c++0x -pthread -D_DEBUG")

# common methods for statis library
# =================================
include($ENV{HOME}/usr/lib/cmake/CMakeHelper/static_library.cmake)

add_subdirectory(test)


