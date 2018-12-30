#ifndef AMER_DELIC_ILINKEDLIST_H
#define AMER_DELIC_ILINKEDLIST_H

#include "Node.h"

template <class T> class ILinkedList
{
protected:
    Node<T> *_head = nullptr,
            *_tail = nullptr,
            *_previous = nullptr;

    unsigned int number_of_nodes;

    virtual bool is_null(Node<T> *temp) = 0;

    virtual bool next_is_null(Node<T> *temp) = 0;

    virtual bool empty() = 0;

public:
    virtual unsigned int get_number_of_nodes() = 0;

    virtual void print_all() = 0;

    virtual void clear_all() = 0;

    virtual void add_first(Node<T> *newNode) = 0;

    virtual void add_last(Node<T> *newNode) = 0;

    virtual void remove_first() = 0;

    virtual void remove_last() = 0;

    virtual bool contains(T value) = 0;

    virtual void remove_by_value(T value) = 0;
};

#endif //AMER_DELIC_ILINKEDLIST_H
