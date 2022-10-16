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
        this->list.add(item);
    }

    T& dequeue()
    {
        if (is_empty())
        {
            std::cout << "The queue is empty." << std::endl;
        }

        T item = this->list.first();
        this->list.remove_at(0);
        return item;
    }

    T& peek()
    {
        if (is_empty())
        {
            std::cout << "The queue is empty." << std::endl;
        }

        return this->list.first();
    }

    bool contains(const T& item)
    {
        return this->list.contains(item);
    }

    bool is_empty() const
    {
        return this->list.is_empty();
    }

    int count() const
    {
        return this->list.count();
    }

    void clear()
    {
        this->list.clear();
    }
};
