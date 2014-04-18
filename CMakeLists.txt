cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -g -Wall -std=c++0x -pthread -D_DEBUG")

project(galaxy)

set(LIB_NAME galaxy)
set(PROJECT_NAME GALAXY)
set(PROJECT_name galaxy)

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

set(INSTALL_LIB_DIR ${CMAKE_INSTALL_PREFIX})
set(INSTALL_BIN_DIR ${CMAKE_INSTALL_PREFIX})
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/math)
set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIB_NAME})

set(PROJECT_BINARY_DIR lib)
set(PROJECT_SOURCE_DIR src)


add_library(galaxy ${src})

include_directories("${PROJECT_SOURCE_DIR}" ../math/src)

# common methods for statis library
# =================================
include(../static_library.cmake)


#project(test_map)
#add_executable(test_map test/map/main.cpp)
#target_link_libraries(test_map galaxy)

#project(test_asio)
#add_executable(test_asio test/asio/main.cpp)
#target_link_libraries(test_asio galaxy tinyxml2)

#project(test_sig)
#add_executable(test_sig test/sig/main.cpp)
#target_link_libraries(test_sig galaxy)

#project(test_timer)
#add_executable(test_timer test/timer/main.cpp)
#target_link_libraries(test_timer galaxy)


