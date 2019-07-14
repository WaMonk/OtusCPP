cmake_minimum_required(VERSION 3.2) 

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
	SET(P_G_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()
	SET(P_G_VERSION 0.0.1)
ENDIF()

project(Otus-All VERSION "${P_G_VERSION}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/build)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_BINARY_DIR}/package)


include_directories(lib)

configure_file(bintray/description.json.in bintray/description.json)

add_subdirectory(packages/work1)
add_subdirectory(packages/work2)
