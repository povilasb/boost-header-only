cmake_minimum_required(VERSION 2.6)

project(boost-1.57.0-header-only CXX)

option(BOOST_HEADER_ONLY_ENABLE_TESTS
	"Enables or disables tests. Disabled by default." OFF)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(BOOST_HEADER_ONLY_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${BOOST_HEADER_ONLY_INCLUDE_DIRS})

if (BOOST_HEADER_ONLY_ENBALE_TESTS)
	add_subdirectory(test)
endif()
