//
// Created by amer on 12/30/18.
//

#include <iostream>
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
    {

        try {
            this->linkedList->remove_first();
        }
        catch(NoStoredValuesException& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    T get_next_item() override
    {

        try {
            auto next = this->linkedList->get_head_value();

            return next;
        }
        catch(NoStoredValuesException& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
            return 0;
        }


    }

    void clear() override
    {

        try {
            this->linkedList->clear_all();
        }
        catch(NoStoredValuesException& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

};