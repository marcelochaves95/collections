#define CATCH_CONFIG_MAIN

#include<iostream>
#include "../include/catch.hpp"
#include "map.h"

TEST_CASE("add")
{
    Map<std::string, std::string> map;

    map.add("Country", "Brazil");
    map.add("State", "Minas Gerais");
    map.add("City", "Belo Horizonte");

    bool contains = map.contains_key("Country");
    REQUIRE(contains);
};

TEST_CASE("update")
{
    Map<std::string, std::string> map;

    map.add("Country", "Brazil");
    map.add("State", "Minas Gerais");
    map.add("City", "Belo Horizonte");
    map.update("City", "London");

    std::string* value = map.get_value("City");
    REQUIRE(*value == "London");
};

TEST_CASE("remove")
{
    Map<std::string, std::string> map;

    map.add("Country", "Brazil");
    map.add("State", "Minas Gerais");
    map.add("City", "Belo Horizonte");

    bool remove = map.remove("Country");
    REQUIRE(remove);
};

TEST_CASE("get_value")
{
    Map<std::string, std::string> map;

    map.add("Country", "Brazil");
    map.add("State", "Minas Gerais");
    map.add("City", "Belo Horizonte");

    std::string* value = map.get_value("City");
    REQUIRE(*value == "Belo Horizonte");
};

TEST_CASE("contains")
{
    Map<std::string, std::string> map;

    map.add("Country", "Brazil");
    map.add("State", "Minas Gerais");
    map.add("City", "Belo Horizonte");

    bool contains = map.contains_key("Country");
    REQUIRE(contains);
};
