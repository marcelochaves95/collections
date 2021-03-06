#define CATCH_CONFIG_MAIN

#include<iostream>
#include "../include/catch.hpp"
#include "list.h"

TEST_CASE("add")
{
    List<int> list;

    list.add(4);
    list.add(7);
    list.add(95);

    bool contains = list.contains(7);
    REQUIRE(contains);
};

TEST_CASE("remove")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.add(95);
    list.remove(2);

    bool contains = list.contains(2);
    REQUIRE(!contains);
};

TEST_CASE("remove_first")
{
    List<int> list;

    list.add(4);
    list.add(3);
    list.remove_first();

    int first = list.first();
    REQUIRE(first == 3);
};

TEST_CASE("remove_last")
{
    List<int> list;

    list.add(4);
    list.add(3);
    list.remove_last();

    int last = list.last();
    REQUIRE(last == 4);
};

TEST_CASE("contains")
{
    List<std::string> list;

    list.add("House");
    list.add("School");
    list.add("City");

    bool contains = list.contains("School");
    REQUIRE(contains);
};

TEST_CASE("is_empty")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.remove(2);
    list.remove(4);

    bool isEmpty = list.is_empty();
    REQUIRE(isEmpty);
};

TEST_CASE("first")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.add(95);

    int first = list.first();
    REQUIRE(first == 4);
};

TEST_CASE("last")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.add(95);

    int last = list.last();
    REQUIRE(last == 95);
};

TEST_CASE("count")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.add(95);

    int count = list.count();
    REQUIRE(count == 3);
};

TEST_CASE("clear")
{
    List<int> list;

    list.add(4);
    list.add(2);
    list.add(95);
    list.clear();

    bool isEmpty = list.is_empty();
    REQUIRE(isEmpty);
};
