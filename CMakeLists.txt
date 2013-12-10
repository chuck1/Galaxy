cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

project(galaxy)

set(src 
	src/gal/flag.cpp
	src/gal/map.cpp
)

add_library(galaxy ${src})

set(PROJECT_BINARY_DIR lib)
set(PROJECT_SOURCE_DIR src)

include_directories("${PROJECT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

install(TARGETS galaxy DESTINATION lib)

install(FILES ${PROJECT_SOURCE_DIR}/gal/gal.h DESTINATION include/gal)
install(FILES ${PROJECT_SOURCE_DIR}/gal/flag.h DESTINATION include/gal)
install(FILES ${PROJECT_SOURCE_DIR}/gal/map.h DESTINATION include/gal)
install(FILES ${PROJECT_SOURCE_DIR}/gal/sig/signal.h DESTINATION include/gal/sig)
install(FILES ${PROJECT_SOURCE_DIR}/gal/sig/connection.h DESTINATION include/gal/sig)

project(test_map)
add_executable(test_map test/map/main.cpp)



