#define CATCH_CONFIG_MAIN
#include <catch.h>
#include <memory>
#include <iostream>

TEST_CASE("mt") {
    REQUIRE(1 == 1);
}