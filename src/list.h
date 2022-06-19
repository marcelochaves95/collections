#ifndef LIST
#define LIST

template <typename T>
struct listNode { 
  T item;
  int index;
  listNode *next;

  listNode()
  {
    next = 0;
  }

  listNode(const T& item, int index, listNode *next = 0)
  {
    this->item = item;
    this->index;
    this->next = next;
  }
};

template<class T>
class list
{
protected:
    listNode<T> *first;
    listNode<T> *last;
public:
    list()
    {
      first = 0;
      last = 0;
    }

    ~list() {
      clear();
    }

    void add(const T& item)
    {
      if (empty())
      {
        first->next = new listNode<T>(item, 0);
        return;
      }

      last->next = new listNode<T>(item, last->index);
      last = last->next;
    }

    // TODO: This needs to be implemented
    void insert(const int& index, const T& item)
    {
      if (index < 0 || index > last->index)
      {
        throw("Index out of range of list.");
      }

      if (index < first->index)
      {
        first = new listNode<T>(item, 0);
        if (last == 0)
        {
          last = first;
        }
        return;
      }
      
    }

    void remove(const T& item)
    {
      if (empty())
      {
        throw("Empty is list.");
      }

      if (first == last && item == first->item)
      {
        delete first;
        first = 0;
        last = 0;
        return;
      }

      if (item == first->item)
      {
        listNode<T> *tmp = first;
        first = first->next;
        delete tmp;
        return;
      }

      listNode<T> *previous, *tmp;
      previous = first;
      tmp = first->next;
      while (tmp != 0 && tmp->item != item)
      {
        previous = previous->next;
        tmp = tmp->next;
      }
      
      if (tmp != 0) {
          previous->next = tmp->next;
          if (tmp == last)
          {
            last = previous;
          }
      }
      delete tmp;
    }

    void remove_at(const int& index)
    {
      if (empty())
      {
        throw("Empty is list.");
      }

      if (index < first->index || index > last->index)
      {
        throw("Index out of range of list.");
      }

      if (first == last)
      {
        delete first;
        first = 0;
        last = 0;
        return;
      }

      if (index == first->index)
      {
        listNode<T> *tmp = first;
        first = first->next;
        delete tmp;
        return;
      }

      listNode<T> *previous, *tmp;
      previous = first;
      tmp = first->next;
      while (tmp != 0 && tmp->index != index)
      {
        previous = previous->next;
        tmp = tmp->next;
      }
      
      if (tmp != 0) {
          previous->next = tmp->next;
          if (tmp == last)
          {
            last = previous;
          }
      }
      delete tmp;
    }

    void clear()
    {
      listNode<T> *node;
      while (!empty())
      {
        node = first->next;
        delete first;
        first = node;
      }
    }

    T& find(const int& index)
    {
      if (empty())
      {
        throw("Empty is list.");
      }

      listNode<T> *tmp = first;
      while(tmp != 0)
      {
        if (tmp->index == index)
        {
          return tmp->item;
        }
        tmp = tmp->next;
      }

      return 0;
    }

    T& begin() const
    {
      return first;
    }

    T& end() const
    {
      return last;
    }

    bool contains(const T& item)
    {
      if (empty())
      {
        throw("Empty is list.");
      }

      listNode<T> *tmp = first;
      while (tmp != 0)
      {
        if (tmp->item == item)
        {
          return true;
        }

        tmp = tmp->next;
      }

      return false;
    }

    int index_of(const T& item)
    {
      if (empty())
      {
        throw("Empty is list.");
      }

      listNode<T> *tmp = first;
      while (tmp != 0)
      {
        if (tmp->item == item)
        {
          return tmp->index;
        }

        tmp = tmp->next;
      }
    }

    int count() const
    {
      if (empty())
      {
        return 0;
      }

      return last->index;
    }

    bool empty() const
    {
      return first == 0;
    }
};

#endif
