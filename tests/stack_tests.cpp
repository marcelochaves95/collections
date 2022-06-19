#define CATCH_CONFIG_MAIN

#include<iostream>
#include "../include/catch.hpp"
#include "stack.h"

TEST_CASE("push")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(7);
    stack.push(95);

    bool contains = stack.contains(7);
    REQUIRE(contains);
};

TEST_CASE("pop")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(7);
    stack.push(95);
    int pop = stack.pop();

    REQUIRE(pop == 95);
};

TEST_CASE("peek")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(7);
    stack.push(95);
    int peek = stack.peek();

    REQUIRE(peek == 95);
};

TEST_CASE("contains")
{
    Stack<std::string> stack;

    stack.push("House");
    stack.push("School");
    stack.push("City");

    bool contains = stack.contains("School");
    REQUIRE(contains);
};

TEST_CASE("is_empty")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(2);
    stack.pop();
    stack.pop();

    bool isEmpty = stack.is_empty();
    REQUIRE(isEmpty);
};

TEST_CASE("count")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(7);
    stack.push(95);

    int count = stack.count();
    REQUIRE(count == 3);
};

TEST_CASE("clear")
{
    Stack<int> stack;

    stack.push(4);
    stack.push(7);
    stack.push(95);
    stack.clear();

    bool isEmpty = stack.is_empty();
    REQUIRE(isEmpty);
};
