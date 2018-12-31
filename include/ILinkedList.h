#ifndef AMER_DELIC_ILINKEDLIST_H
#define AMER_DELIC_ILINKEDLIST_H

#include "Node.h"
#include "NoStoredValuesException.h"

template <class T> class ILinkedList
{
protected:
    Node<T> *_head = nullptr,
            *_tail = nullptr,
            *_previous = nullptr;

    unsigned int number_of_nodes;
    NoStoredValuesException _noStoredValuesException;

    bool is_null(Node<T> *temp)
    { return temp == nullptr; }

    bool next_is_null(Node<T> *temp)
    { return temp->get_next_node() == nullptr; }

    bool empty()
    { return this->number_of_nodes == 0; }

public:
    virtual unsigned int get_number_of_nodes() = 0;

    virtual void print_all() = 0;

    virtual void clear_all() = 0;

    virtual void add_first(Node<T> *newNode) = 0;

    virtual void add_last(Node<T> *newNode) = 0;

    virtual void add_last(T item) = 0;

    virtual void add_first(T item) = 0;

    virtual void remove_first() = 0;

    virtual void remove_last() = 0;

    virtual bool contains(T value) = 0;

    virtual void remove_by_value(T value) = 0;

    virtual T get_head_value() = 0;

    virtual T get_tail_value() = 0;
};

#endif //AMER_DELIC_ILINKEDLIST_H
