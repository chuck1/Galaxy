cmake_minimum_required (VERSION 2.6)

project(galaxy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -g -Wall -std=c++0x -pthread -D_DEBUG")

# common methods for statis library
# =================================
include(../cmake/static_library.cmake)

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


