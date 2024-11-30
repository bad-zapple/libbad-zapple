cmake_minimum_required(VERSION 3.15)

project(libbad_zapple)

if (NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "This project has a top-level one called [${CMAKE_PROJECT_NAME}]")
else()
    message(STATUS "This project is a top-level one")
endif()

include(build/sources.cmake)

set (INC inc)

add_library(bad-zapple ${SOURCES})

target_include_directories(bad-zapple PUBLIC ${INC})
