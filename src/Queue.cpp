//
// Created by amer on 12/30/18.
//

#include "IQueue.h"
#include "ILinkedList.h"

template <class T>
class Queue : public IQueue<T>
{
public:
    Queue(ILinkedList<T> *linkedList)
    {this->linkedList = linkedList;}

    void enqueue(T item) override
    { this->linkedList->add_first(item); }

    void dequeue() override
    {this->linkedList->remove_first();}

    T get_next_item() override
    { return this->linkedList->get_head_value(); }

    void clear() override
    { this->linkedList->clear_all(); }

};