#ifndef LIST
#define LIST

template<class T>
class list
{
private:
    template<typename TNode>
    struct node
    {
        TNode item;
        node *next;

        node(const TNode& item)
        {
            this->item = item;
            this->next = NULL;
        }
    };

    node<T> *head;
    node<T> *tail;
    int size = 0;
public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    ~list() {
        clear();
    }

    void add(const T& item)
    {
        if (is_empty())
        {
            head = new node<T>(item);
            tail = head;
            size++;
            return;
        }

        tail->next = new node<T>(item);
        tail = tail->next;
        size++;
    }

    void remove(const T& item)
    {
        if (is_empty())
        {
            std::cout << "Empty is list." << std::endl;
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
            node<T> *tmp = head;
            head = head->next;
            delete tmp;
            size--;
            return;
        }

        node<T> *previous, *temporary;
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
            std::cout << "Empty is list." << std::endl;
        }

        node<T> *temporary = head;
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
        return head == 0;
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
        node<T> *node;
        while (!is_empty())
        {
            node = head->next;
            delete head;
            head = node;
        }
    }
};

#endif
