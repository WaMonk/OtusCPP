cmake_minimum_required(VERSION 3.2) 

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
	SET(P_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()
	SET(P_VERSION 0.0.1)
ENDIF()

project(Otus1 VERSION "${P_VERSION}")

include_directories("include")

set(sources2 src/ip.cc src/utils.cc)

add_executable(main2 src/main.cc ${sources2})

add_executable(test2 test/test.cc ${sources2})

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(test2 test2)
