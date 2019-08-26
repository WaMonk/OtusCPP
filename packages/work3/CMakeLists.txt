cmake_minimum_required(VERSION 3.2) 

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    SET(P_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    SET(P_VERSION 0.0.1)
ENDIF()

project(Otus1 VERSION "${P_VERSION}")

include_directories("include")

IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


set(CMAKE_BUILD_TYPE "Debug")
set(sources3)

add_executable(main3 src/main.cc ${sources3})

add_executable(test3 test/test.cc ${sources3})

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(test3 test3)
