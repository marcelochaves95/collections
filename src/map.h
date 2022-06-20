#pragma once
#include <iostream>

template <typename TKey, typename TValue>
struct KeyValuePair
{
private:
    TKey key;
    TValue value;
    KeyValuePair *next;
    KeyValuePair(const KeyValuePair&);
    KeyValuePair & operator=(const KeyValuePair&);
public:
    KeyValuePair(const TKey &key, const TValue &value) : key(key), value(value), next(NULL)
    {
    }

    TKey get_key() const {
        return this->key;
    }

    TValue get_value() const {
        return this->value;
    }

    void set_value(TValue value)
    {
        this->value = value;
    }

    KeyValuePair *get_next() const {
        return this->next;
    }

    void set_next(KeyValuePair *next) {
        this->next = next;
    }
};

template <typename TKey, std::size_t tableSize>
struct KeyHash {
    unsigned long operator()(const TKey &key) const
    {
        return reinterpret_cast<unsigned long>(key) % tableSize;
    }
};

template <typename TKey, typename TValue, std::size_t tableSize, typename F = KeyHash<TKey, tableSize>>
class Map
{
private:
    Map(const Map &other);
    const Map & operator=(const Map &other);
    KeyValuePair<TKey, TValue> *table[tableSize];
    F hashFunc;
public:
    Map() : table(), hashFunc()
    {
    }

    ~Map()
    {
        for (size_t i = 0; i < tableSize; ++i)
        {
            KeyValuePair<TKey, TValue> *entry = table[i];
            while (entry != NULL)
            {
                KeyValuePair<TKey, TValue> *prev = entry;
                entry = entry->get_next();
                delete prev;
            }

            table[i] = NULL;
        }
    }

    void add(const TKey &key, const TValue &value)
    {
        unsigned long hashValue = hashFunc(key);
        KeyValuePair<TKey, TValue> *prev = NULL;
        KeyValuePair<TKey, TValue> *entry = table[hashValue];

        while (entry != NULL && entry->get_key() != key)
        {
            prev = entry;
            entry = entry->get_next();
        }

        if (entry == NULL)
        {
            entry = new KeyValuePair<TKey, TValue>(key, value);
            if (prev == NULL)
            {
                table[hashValue] = entry;
                return;
            }
            
            prev->set_next(entry);
            return;
        }

        entry->set_value(value);
    }

    void remove(const TKey &key)
    {
        unsigned long hashValue = hashFunc(key);
        KeyValuePair<TKey, TValue> *prev = NULL;
        KeyValuePair<TKey, TValue> *entry = table[hashValue];

        while (entry != NULL && entry->get_key() != key)
        {
            prev = entry;
            entry = entry->get_next();
        }

        if (entry == NULL)
        {
            return;
        }

        if (prev == NULL)
        {
            table[hashValue] = entry->get_next();
            return;
        }

        prev->set_next(entry->get_next());
        delete entry;
    }

    bool get(const TKey &key, TValue &value)
    {
        unsigned long hashValue = hashFunc(key);
        KeyValuePair<TKey, TValue> *entry = table[hashValue];
        while (entry != NULL)
        {
            if (entry->get_key() == key)
            {
                value = entry->get_value();
                return true;
            }

            entry = entry->get_next();
        }

        return false;
    }

    bool contains_key(const TKey &key)
    {
        unsigned long hashValue = hashFunc(key);
        KeyValuePair<TKey, TValue> *entry = table[hashValue];
        while (entry != NULL)
        {
            if (entry->get_key() == key)
            {
                return true;
            }

            entry = entry->get_next();
        }

        return false;
    }
};
