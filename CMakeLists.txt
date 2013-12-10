cmake_minimum_required (VERSION 2.6)

project(galaxy)

set(src src/gal/flag.cpp)

add_library(galaxy ${src})

set(PROJECT_BINARY_DIR lib)
set(PROJECT_SOURCE_DIR src)

include_directories("${PROJECT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

install(TARGETS galaxy DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/gal/flag.h DESTINATION include/gal)


