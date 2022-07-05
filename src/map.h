#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

template<class TKey, class TValue>
class Map {
 private:
    struct KeyValuePair {
        int index;
        TKey key;
        TValue value;
    };

    unsigned int entries = 0;
    static const int MAX_SIZE = 100;
    struct KeyValuePair DEFAULT_VALUE;
    struct KeyValuePair table[MAX_SIZE];

    int randon_number()
    {
        return (rand() % MAX_SIZE);
    }

    int hash(TKey key)
    {
        if (this->is_table_full())
        {
           return this->DEFAULT_VALUE.index;
        }

        int counter = 0;
        int i = 1;
        for (char& c : key)
        {
            counter += i++ * int(c);
        }

        return this->probe(counter, key);
    }

    int probe(const int counter, const TKey key)
    {
        int index = static_cast<int>(counter % MAX_SIZE);
        while (this->table[index].index != this->DEFAULT_VALUE.index)
        {
            if (this->table[index].key == key)
            {
                return index;
            }

            index = ++index % MAX_SIZE;
        }

        return index;
    }

    bool is_table_full()
    {
        if (this->entries == MAX_SIZE)
        {
            return true;
        }

        return false;
    }

 public:
    Map()
    {
        this->DEFAULT_VALUE.index = -1;
        srand(time(NULL));
        for (auto& e : this->table)
        {
            e.index = this->DEFAULT_VALUE.index;
        }
    }

    bool add(TKey key, TValue value)
    {
        if (this->is_table_full())
        {
            std::cout << "Table full." << std::endl;
            return false;
        }

        int index = this->hash(key);
        if (this->table[index].key == key)
        {
            std::cout << "Key " << key << " already exist." << std::endl;
            return false;
        }

        struct KeyValuePair* pair = new KeyValuePair();
        pair->index = index;
        pair->key = key;
        pair->value = value;

        this->table[index] = *pair;
        this->entries++;
        return true;
    }

    bool update(TKey key, TValue value)
    {
        int index = this->hash(key);
        if (index == this->DEFAULT_VALUE.index)
        {
            return false;
        }

        this->table[index].value = value;
        return true;
    }

    bool remove(TKey key)
    {
        int index = this->hash(key);
        if (index == this->DEFAULT_VALUE.index)
        {
            return false;
        }

        this->table[index] = this->DEFAULT_VALUE;
        this->entries--;
        return true;
    }

    TValue* get_value(TKey key)
    {
        int index = this->hash(key);
        if (index == this->DEFAULT_VALUE.index)
        {
            return new TValue();
        }

        return &this->table[index].value;
    }
    
    bool contains(TKey key)
    {
        int index = this->hash(key);
        if (index == this->DEFAULT_VALUE.index)
        {
            return false;
        }

        return true;
    }
};
