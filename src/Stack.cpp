#include <iostream>
#include "IStack.h"

template <class T>
class Stack : public IStack<T>
{
public:
    Stack(ILinkedList<T> *linkedList)
    { this->_linkedList = linkedList; }

    unsigned int get_depth() override
    { return this->_linkedList->GetSize(); }

    bool is_empty() override
    { return get_depth() == 0; }

    void print_all() override
    {
        try {
            this->_linkedList->PrintAll();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    void push(Node<T> *node) override
    { this->_linkedList->AddFirst(node); }

    void push(T item)
    {
        Node<T> *newNode = new Node<T>(item);
        push(newNode);
    };

    void pop() override
    {
        try {
            this->_linkedList->RemoveFirst();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }

    }

    void clear() override
    {
        try {
            this->_linkedList->Clear();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    T peek() override
    {
        try{
            return this->_linkedList->GetHeadValue();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

};