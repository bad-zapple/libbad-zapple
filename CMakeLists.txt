#---------------------------------------------------------------------------------------#

cmake_minimum_required(VERSION 3.15)

project(libbad_zapple)
#---------------------------------------------------------------------------------------#

# Search libs in the project and not in normal install

set(CUSTOM_LIB_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-pic")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")

#---------------------------------------------------------------------------------------#

include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

# example usage
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-pedantic")

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
	set(TEST_LIST ${TEST_LIST} ${TEST_FILE})
endforeach()

enable_testing()

#---------------------------------------------------------------------------------------#
