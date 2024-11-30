#---------------------------------------------------------------------------------------#

cmake_minimum_required(VERSION 3.15)

project(libbad_zapple)

#---------------------------------------------------------------------------------------#

set(CUSTOM_LIB_PATH $ENV{HOME}/lib/)

#---------------------------------------------------------------------------------------#

# Build bad-zapple lib

if (NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "This project has a top-level one called [${CMAKE_PROJECT_NAME}]")
else()
    message(STATUS "This project is a top-level one")
endif()

include(build/lib_sources.cmake)

set (INC inc)

add_library(bad-zapple ${SOURCES})

target_include_directories(bad-zapple PUBLIC ${INC})

#---------------------------------------------------------------------------------------#

# Install Catch2
set(CMAKE_PREFIX_PATH ${CUSTOM_LIB_PATH}/lib/cmake/Catch2 ${CMAKE_PREFIX_PATH})
find_package(Catch2 QUIET)
if (NOT Ccatch2_FOUND)
	message(STATUS "YourLibrary not found. Attempting to install...")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "Running installation script..."
	COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/install_catch.sh
        RESULT_VARIABLE install_result
    )
    if(NOT install_result EQUAL 0)
        message(FATAL_ERROR "Failed to install YourLibrary. Please install it manually.")
    endif()
endif()

#---------------------------------------------------------------------------------------#

# Use the library in the test project

find_package(Catch2 REQUIRED)
include(build/tests_sources.cmake)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PUBLIC bad-zapple)

#---------------------------------------------------------------------------------------#
