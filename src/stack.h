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
        this->list.add(item);
    }

    T& pop()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty." << std::endl;
        }

        T item = this->list.last();
        this->list.remove_at(0);
        return item;
    }

    T& peek()
    {
        if (is_empty())
        {
            std::cout << "The stack is empty." << std::endl;
        }

        return this->list.last();
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
