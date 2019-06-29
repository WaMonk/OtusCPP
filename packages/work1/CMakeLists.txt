cmake_minimum_required(VERSION 3.2) 

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
	SET(P_VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()
	SET(P_VERSION 0.0.1)
ENDIF()

project(Otus1 VERSION "${P_VERSION}")

include_directories("include")
configure_file(cfg/version.h.in include/version.h)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

add_executable(main1 src/main.cc)

add_executable(test_google1 test/test_google.cc)

include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(test_google1 ${GTEST_LIBRARIES}) 
target_link_libraries(test_google1 pthread)


add_executable(test_boost1 test/test_boost.cc)
target_link_libraries(test_boost1 ${Boost_LIBRARIES})
set_target_properties(test_boost1 PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

add_executable(test_catch1 test/test_catch.cc)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_google1 test_google1)
add_test(test_catch1 test_catch1)
add_test(test_boost1 test_boost1)
