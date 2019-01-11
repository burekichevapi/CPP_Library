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

    void Push(Node<T> *node) override
    { this->_linkedList->AddFirst(node); }

    void Push(T item)
    {
        Node<T> *newNode = new Node<T>(item);
        Push(newNode);
    };

    void Pop() override
    {
        try
        {
            this->_linkedList->RemoveFirst();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }

    }

    void Clear() override
    {
        try
        {
            this->_linkedList->Clear();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

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