#pragma once

#include <iostream>

template<class T>
class List
{
private:
    int size;
    int maxSize;
    T *arrayholder;

public:
    List()
    {
        this->size = 0;
        this->maxSize = 30;
        this->arrayholder = new T[this->maxSize];
    }

    ~List()
    {
        delete[] this->arrayholder;
    }

    int& operator[](int i)
    {
        return this->arrayholder[i];
    }

    void add(const T& item)
    {
        if (this->maxSize < this->size + 1)
        {
            this->maxSize *= 2;
            T *temporaryArray = new T[this->maxSize];

            for (std::size_t i = 0; i < this->size; i++)
            {
                temporaryArray[i] = this->arrayholder[i];
            }

            delete[] this->arrayholder;
            this->arrayholder = temporaryArray;
            this->arrayholder[this->size] = item;
            this->size += 1;
            return;
        }

        this->arrayholder[this->size] = item;
        this->size += 1;
    }

    void remove(const T& item)
    {
        int indexToRemove = this->index_of(item);
        if (indexToRemove == -1)
        {
            return;
        }

        for (std::size_t i = indexToRemove; i < this->size; i++)
        {
            this->arrayholder[i] = this->arrayholder[i + 1];
        }

        this->size -= 1;
    }

    void remove_at(const int index)
    {
        T& item = this->arrayholder[index];
        this->remove(item);
    }

    bool contains(const T& item)
    {
        int index = this->index_of(item);
        return index == -1 ? false : true;
    }

    int index_of(const T& item) const
    {
        for (std::size_t i = 0; i < this->size; i++)
        {
            if (this->arrayholder[i] == item)
            {
                return i;
            }
        }

        return -1;
    }

    bool is_empty() const
    {
        return this->size == 0;
    }

    T& first() const
    {
        return this->arrayholder[0];
    }

    T& last() const
    {
        return this->arrayholder[this->size - 1];
    }

    int count() const
    {
        return this->size;
    }

    void clear()
    {
        std::fill_n(this->arrayholder, this->size, 0);
        this->size = 0;
        this->arrayholder = new T[maxSize];
    }
};
