#ifndef AMER_DELIC_ISTACK_H
#define AMER_DELIC_ISTACK_H

#include "ILinkedList.h"

template <class T>
class IStack
{
protected:
    ILinkedList<T> *_linkedList = nullptr;

public:
    virtual unsigned int get_depth() = 0;

    virtual bool is_empty() = 0;

    virtual void print_all() = 0;

    virtual void push(Node<T> *node) = 0;

    virtual void push(T item) = 0;

    virtual void pop() = 0;

    virtual void clear() = 0;

    virtual T peek() = 0;

};

#endif //AMER_DELIC_ISTACK_H
