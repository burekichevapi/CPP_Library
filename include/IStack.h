#ifndef AMER_DELIC_ISTACK_H
#define AMER_DELIC_ISTACK_H

#include "ILinkedList.h"

template <class T>
class IStack
{
protected:
    ILinkedList<T> *_linkedList = nullptr;

public:
    virtual unsigned int GetDepth() = 0;

    virtual bool IsEmpty() = 0;

    virtual void Push(Node<T> *node) = 0;

    virtual void Push(T item) = 0;

    virtual void Pop() = 0;

    virtual void Clear() = 0;

    virtual T Peek() = 0;

};

#endif //AMER_DELIC_ISTACK_H
