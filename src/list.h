#pragma once

#include <iostream>

template<class T>
class List
{
private:
    template<typename TNode>
    struct Node
    {
        TNode item;
        Node *next;

        Node(const TNode& item)
        {
            this->item = item;
            this->next = NULL;
        }
    };

    Node<T> *head;
    Node<T> *tail;
    int size = 0;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        clear();
    }

    void add(const T& item)
    {
        if (is_empty())
        {
            head = new Node<T>(item);
            tail = head;
            size++;
            return;
        }

        tail->next = new Node<T>(item);
        tail = tail->next;
        size++;
    }

    void remove(const T& item)
    {
        if (is_empty())
        {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        if (head == tail && item == head->item)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return;
        }

        if (item == head->item)
        {
            Node<T> *temporary = head;
            head = head->next;
            delete temporary;
            size--;
            return;
        }

        Node<T> *previous, *temporary;
        previous = head;
        temporary = head->next;
        while (temporary != NULL && temporary->item != item)
        {
            previous = previous->next;
            temporary = temporary->next;
        }

        if (temporary != NULL) {
            previous->next = temporary->next;
            if (temporary == tail)
            {
                tail = previous;
            }
            size--;
        }

        delete temporary;
    }

    bool contains(const T& item)
    {
        if (is_empty())
        {
            std::cout << "The list is empty." << std::endl;
            return false;
        }

        Node<T> *temporary = head;
        while (temporary != NULL)
        {
            if (temporary->item == item)
            {
                return true;
            }

            temporary = temporary->next;
        }

        return false;
    }

    bool is_empty() const
    {
        return head == NULL;
    }

    T& first()
    {
        return head->item;
    }

    T& last()
    {
        return tail->item;
    }

    int count() const
    {
        if (is_empty())
        {
            return 0;
        }

        return size;
    }

    void clear()
    {
        Node<T> *node;
        while (!is_empty())
        {
            node = head->next;
            delete head;
            head = node;
        }
    }
};
