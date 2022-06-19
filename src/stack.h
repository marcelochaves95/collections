#pragma once

#include <iostream>
#include "list.h"

template<class T>
class Stack
{
private:
    List<T> list;
public:
    Stack()
    {
    }

    ~Stack()
    {
        clear();
    }

    void push(const T& item)
    {
        list.add(item);
    }

    T& pop()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty." << std::endl;
        }

        T& item = list.last();
        list.remove_last();
        return item;
    }

    T& peek()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty." << std::endl;
        }

        return list.last();
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
