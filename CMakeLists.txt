#---------------------------------------------------------------------------------------#

cmake_minimum_required(VERSION 3.15)

project(libbad_zapple)

#---------------------------------------------------------------------------------------#

# Search libs in the project and not in normal install

set(CUSTOM_LIB_PATH ${PROJECT_SOURCE_DIR}/lib)

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

include(build/tests_sources.cmake)

set(CMAKE_PREFIX_PATH ${CUSTOM_LIB_PATH}/lib/cmake/Catch2 ${CMAKE_PREFIX_PATH})
message("tests_sources : " ${TEST_SOURCES})
message("CMAKE_PREFIX_PATH : " ${CMAKE_PREFIX_PATH})

include(CTest)

find_package(Catch2 REQUIRED)

foreach(TEST_FILE IN LISTS TEST_SOURCES)
	cmake_path(GET TEST_FILE STEM TEST_FILE_NO_EXT)
	add_executable(${TEST_FILE_NO_EXT} ${TEST_FILE})
	target_link_libraries(${TEST_FILE_NO_EXT} PUBLIC bad-zapple)
	target_link_libraries(${TEST_FILE_NO_EXT} PRIVATE Catch2::Catch2)
	add_test(NAME ${TEST_FILE_NO_EXT} COMMAND ${TEST_FILE_NO_EXT})
	set(TEST_LIST ${TEST_LIST} ${TEST_FILE})https://meta.intra.42.fr/issues
endforeach()

enable_testing()

#---------------------------------------------------------------------------------------#
