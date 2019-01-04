
#ifndef AMER_DELIC_IQUEUE_H
#define AMER_DELIC_IQUEUE_H

#include "ILinkedList.h"

template <class T>
class IQueue
{
protected:
    ILinkedList<T> *linkedList = nullptr;

public:

    virtual void Enqueue(T item) = 0;

    virtual void Dequeue() = 0;

    virtual T GetNextItem() = 0;

    virtual void Clear() = 0;

};


#endif //AMER_DELIC_IQUEUE_H
