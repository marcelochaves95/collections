#pragma once

#include <iostream>
#include "list.h"

template <class T>
class Queue
{
private:
    List<T> list;
public:
    Queue()
    {
    }

    ~Queue()
    {
        clear();
    }

    void enqueue(const T& item)
    {
        list.add(item);
    }

    T& dequeue()
    {
        if (is_empty())
        {
            std::cout << "The queue is empty." << std::endl;
        }

        T& item = list.first();
        list.remove_first();
        return item;
    }

    T& peek()
    {
        if (is_empty())
        {
            std::cout << "The queue is empty." << std::endl;
        }

        return list.first();
    }

    bool contains(const T& item)
    {
        return list.contains(item);
    }

    bool is_empty() const
    {
        return list.is_empty();
    }

    int count() const
    {
        return list.count();
    }

    void clear()
    {
        list.clear();
    }
};
