//
// Created by amer on 1/11/19.
//
// TODO: In Enqueue method. Exposes Head pointer of node.
// TODO In Enqueue method. Exposes LinkedList IncreaseSize method.

#include <stdexcept>
#include <iostream>
#include "ILinkedList.h"
#include "IQueue.h"

template <class T>
class PriorityQueue : IQueue<T>
{
public:
    PriorityQueue(ILinkedList<T> *linkedList)
    { this->linkedList = linkedList; }

    void Enqueue(T item) override
    {
        if(this->linkedList->IsEmpty())
        {
            this->linkedList->AddLast(item);
            return;
        }

        auto *current = this->linkedList->GetHeadPointer(); //Don't like this

        if(item > current->GetValue())
        {
            this->linkedList->AddFirst(item);
            return;
        }

        while(current->GetNextNode() != nullptr &&
              item < current->GetNextNode()->GetValue())
            current = current->GetNextNode();

        auto *temp = current;
        current = new LinkedNode<T>(item);
        current->SetNextNode(temp->GetNextNode());
        temp->SetNextNode(current);

        this->linkedList->IncreaseSize(); //Don't like this
    }

    void Dequeue() override
    {
        try
        {
            this->linkedList->RemoveFirst();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    T GetNextItem() override
    {
        try
        {
            return this->linkedList->GetHeadValue();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    void Clear() override
    {this->linkedList->Clear();}

    bool Empty() override
    {return this->linkedList->IsEmpty();}

    void PrintAll()
    { this->linkedList->PrintAll(); }

};