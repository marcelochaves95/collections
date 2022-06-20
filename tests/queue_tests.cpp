#define CATCH_CONFIG_MAIN

#include<iostream>
#include "../include/catch.hpp"
#include "queue.h"

TEST_CASE("enqueue")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);
    queue.enqueue(95);

    bool contains = queue.contains(7);
    REQUIRE(contains);
};

TEST_CASE("dequeue")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);
    queue.enqueue(95);
    int dequeue = queue.dequeue();

    REQUIRE(dequeue == 4);
};

TEST_CASE("peek")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);
    queue.enqueue(95);
    int peek = queue.peek();

    REQUIRE(peek == 4);
};

TEST_CASE("contains")
{
    Queue<std::string> queue;

    queue.enqueue("House");
    queue.enqueue("School");
    queue.enqueue("City");

    bool contains = queue.contains("School");
    REQUIRE(contains);
};

TEST_CASE("is_empty")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(2);
    queue.dequeue();
    queue.dequeue();

    bool isEmpty = queue.is_empty();
    REQUIRE(isEmpty);
};

TEST_CASE("count")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);
    queue.enqueue(95);

    int count = queue.count();
    REQUIRE(count == 3);
};

TEST_CASE("clear")
{
    Queue<int> queue;

    queue.enqueue(4);
    queue.enqueue(7);
    queue.enqueue(95);
    queue.clear();

    bool isEmpty = queue.is_empty();
    REQUIRE(isEmpty);
};
