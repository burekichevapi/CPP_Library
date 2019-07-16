#include <iostream>
#include "IStack.h"

template <class T>
class Stack : public IStack<T>
{
public:
    Stack(ILinkedList<T> *linkedList)
    { this->_linkedList = linkedList; }

    unsigned int GetDepth() override
    { return this->_linkedList->GetSize(); }

    bool IsEmpty() override
    { return GetDepth() == 0; }

    void PrintAll()
    {
        try
        {
            this->_linkedList->PrintAll();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    void Push(LinkedNode<T> *node) override
    { this->_linkedList->AddFirst(node); }

    void Push(T item)
    {Push(new LinkedNode<T>(item));}

    T Pop() override
    {
        try
        {
            T value = this->_linkedList->GetHeadValue();
            this->_linkedList->RemoveFirst();
            return value;
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }

    }

    void Clear() override
    {this->_linkedList->Clear();}

    T Peek() override
    {
        try
        {
            return this->_linkedList->GetHeadValue();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }
};