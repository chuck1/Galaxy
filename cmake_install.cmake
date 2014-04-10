# Install script for directory: /nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/nfs/stak/students/r/rymalc/usr")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/libgalaxy.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal" TYPE FILE FILES
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/config.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/util.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/gal.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/flag.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/map.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/except.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/stack_trace.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal/timer" TYPE FILE FILES
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/timer/timer.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/timer/timer_set.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal/sig" TYPE FILE FILES "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/sig/signal.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal/sig" TYPE FILE FILES "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/sig/connection.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal/control" TYPE FILE FILES "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/control/control.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gal/network" TYPE FILE FILES
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/message.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/communicating.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/server.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/client.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/vector.h"
    "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/src/gal/network/serial.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/nfs/stak/students/r/rymalc/Documents/Programming/C++/galaxy/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
