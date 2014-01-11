cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread")

project(galaxy)

set(PROJECT_BINARY_DIR lib)
set(PROJECT_SOURCE_DIR src)

set(src 
	src/gal/map.cpp
	src/gal/except.cpp
	src/gal/stack_trace.cpp
	src/gal/network/message.cpp
	src/gal/network/communicating.cpp
	src/gal/network/server.cpp
	src/gal/network/client.cpp
)

add_library(galaxy ${src})

include_directories("${PROJECT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/usr)

configure_file("${PROJECT_SOURCE_DIR}/gal/config.h.in" "${PROJECT_SOURCE_DIR}/gal/config.h")

install(TARGETS galaxy DESTINATION lib)

set(files
	${PROJECT_SOURCE_DIR}/gal/config.h
	${PROJECT_SOURCE_DIR}/gal/util.h
	${PROJECT_SOURCE_DIR}/gal/gal.h
	${PROJECT_SOURCE_DIR}/gal/flag.h
	${PROJECT_SOURCE_DIR}/gal/map.h
	${PROJECT_SOURCE_DIR}/gal/except.h
	${PROJECT_SOURCE_DIR}/gal/stack_trace.h
)

install(FILES ${files} DESTINATION include/gal)

install(FILES ${PROJECT_SOURCE_DIR}/gal/sig/signal.h DESTINATION include/gal/sig)
install(FILES ${PROJECT_SOURCE_DIR}/gal/sig/connection.h DESTINATION include/gal/sig)

set(files
	${PROJECT_SOURCE_DIR}/gal/network/message.h
	${PROJECT_SOURCE_DIR}/gal/network/communicating.h
	${PROJECT_SOURCE_DIR}/gal/network/server.h
	${PROJECT_SOURCE_DIR}/gal/network/client.h
	${PROJECT_SOURCE_DIR}/gal/network/vector.h
	${PROJECT_SOURCE_DIR}/gal/network/serial.h
)

install(FILES ${files} DESTINATION include/gal/network)

project(test_map)
add_executable(test_map test/map/main.cpp)
target_link_libraries(test_map galaxy)

project(test_asio)
add_executable(test_asio test/asio/main.cpp)
target_link_libraries(test_asio galaxy)

project(test_sig)
add_executable(test_sig test/sig/main.cpp)
target_link_libraries(test_sig galaxy)

