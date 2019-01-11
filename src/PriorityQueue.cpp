//
// Created by amer on 1/11/19.
//

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

        auto *current = this->linkedList->GetHeadPointer();

        if(item > current->GetValue())
        {
            this->linkedList->AddFirst(item);
            return;
        }

        while(current->GetNextNode() != nullptr &&
              item < current->GetNextNode()->GetValue())
            current = current->GetNextNode();

        auto *temp = current;
        current = new Node<T>(item);
        current->SetNextNode(temp->GetNextNode());
        temp->SetNextNode(current);

        this->linkedList->IncreaseSize();
    }

    void Dequeue() override
    { this->linkedList->RemoveFirst(); }

    T GetNextItem() override
    { return this->linkedList->GetHeadValue(); }

    void Clear() override
    { this->linkedList->Clear(); }

    void PrintAll()
    { this->linkedList->PrintAll(); }

};