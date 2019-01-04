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

    void Enqueue(T item) override
    { this->linkedList->AddFirst(item); }

    void Dequeue() override
    {

        try {
            this->linkedList->RemoveFirst();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    T GetNextItem() override
    {

        try {
            auto next = this->linkedList->GetHeadValue();

            return next;
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
            return 0;
        }


    }

    void Clear() override
    {

        try {
            this->linkedList->Clear();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

};