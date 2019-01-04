
#ifndef AMER_DELIC_IQUEUE_H
#define AMER_DELIC_IQUEUE_H


#include "ILinkedList.h"

template <class T>
class IQueue
{
protected:
    ILinkedList<T> *linkedList = nullptr;

public:

    virtual void enqueue(T item) = 0;

    virtual void dequeue() = 0;

    virtual T get_next_item() = 0;

    virtual void clear() = 0;

};


#endif //AMER_DELIC_IQUEUE_H
