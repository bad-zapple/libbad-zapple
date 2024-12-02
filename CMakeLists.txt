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

add_library(bad-zapple SHARED ${SOURCES})

target_include_directories(bad-zapple PUBLIC ${INC})

#---------------------------------------------------------------------------------------#

# Install Catch2
set(CMAKE_PREFIX_PATH ${CUSTOM_LIB_PATH}/lib/cmake/Catch2 ${CMAKE_PREFIX_PATH})
include(CheckIncludeFile)
CHECK_INCLUDE_FILE("inc/catch.hpp" CATCH_FOUND)
if (NOT CATCH_FOUND)
	execute_process(
		COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "Curling catch.hpp"
		COMMAND mkdir lib
		COMMAND curl https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -o lib/catch.hpp
		RESULT_VARIABLE install_result
	)
endif()

include(build/tests_sources.cmake)
message("here \n\n\n\n")

message("tests_sources : " ${TEST_SOURCES})

include(CTest)

foreach(TEST_FILE IN LISTS TEST_SOURCES)
	cmake_path(GET TEST_FILE STEM TEST_FILE_NO_EXT)
	add_executable(${TEST_FILE_NO_EXT} ${TEST_FILE})
	target_link_libraries(${TEST_FILE_NO_EXT} PUBLIC bad-zapple)
	target_include_directories(${TEST_FILE_NO_EXT} PRIVATE lib)
	target_include_directories(${TEST_FILE_NO_EXT} PUBLIC ${INC})
	add_test(NAME ${TEST_FILE_NO_EXT} COMMAND ${TEST_FILE_NO_EXT})
	set(TEST_LIST ${TEST_LIST} ${TEST_FILE})
endforeach()

enable_testing()

#message("here \n\n\n\n")


#add_executable(tests ${TEST_SOURCES})

#---------------------------------------------------------------------------------------#

# Use the library in the test project

#include(build/tests_sources.cmake)
#add_executable(tests ${TEST_SOURCES} inc/catch.hpp)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
#target_link_libraries(tests PUBLIC bad-zapple)

#---------------------------------------------------------------------------------------#
