#define CATCH_CONFIG_MAIN
#include <catch.h>
#include <memory>
#include <iostream>

#include <ip.h>
#include <utils.h>


using namespace std;
using namespace otus::ip;
using namespace otus::utils;

TEST_CASE("CustomIP") {
	try {
        auto ip1 = make_shared<CustomIP>("");
    }
    catch(std::exception& ex){
        REQUIRE(strcmp(ex.what(),"Ip Format is broken: size") == 0);
    }

    try {
        auto ip2 = make_shared<CustomIP>("114124141414141414");
    }
    catch(std::exception& ex){
        REQUIRE(strcmp(ex.what(), "Ip Format is broken: points") == 0);
    }

    try {
        auto ip1 = make_shared<CustomIP>("1.1.1.1.1.1.1");
    }
    catch(std::exception& ex){
        REQUIRE(strcmp(ex.what(),"Ip Format is broken: size") == 0);
    }

    auto ip = make_shared<CustomIP>("10.10.10.10");
    REQUIRE(ip->as_string().compare("10.10.10.10") == 0);

    try {
        ip->check_byte(5,35);
    }
    catch(std::exception& ex){
        REQUIRE(strcmp(ex.what(),"Check is broken: wrong position: 5") == 0);
    }

      try {
        ip->check_byte(0,35);
    }
    catch(std::exception& ex){
        REQUIRE(strcmp(ex.what(),"Check is broken: wrong position: 0") == 0);
    }
    catch(...){
        std::cerr<<"Unhandled exception"<<std::endl;
        REQUIRE(true == false);
    }

    REQUIRE(ip->check_byte(1,10));
    REQUIRE(ip->check_byte(2,35) == false);
    REQUIRE(ip->check_byte(3,35) == false);
    REQUIRE(ip->check_byte(3,10));
    REQUIRE(ip->check_byte(4,10));
}

TEST_CASE("Utils") {
    auto temp = split("a\tbb\tccc\tdddd", '\t');
  
    REQUIRE(temp.size() == 4);
    REQUIRE(temp.at(0).compare("a") == 0);
    REQUIRE(temp.at(1).compare("bb") == 0);
    REQUIRE(temp.at(2).compare("ccc") == 0);
    REQUIRE(temp.at(3).compare("dddd") == 0);
}