#include <iostream>
#include "IStack.h"

template <class T>
class Stack : public IStack<T>
{
public:
    Stack(ILinkedList<T> *linkedList)
    { this->_linkedList = linkedList; }

    unsigned int get_depth() override
    { return this->_linkedList->get_number_of_nodes(); }

    bool is_empty() override
    { return get_depth() == 0; }

    void print_all() override
    {
        try {
            this->_linkedList->print_all();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    void push(Node<T> *node) override
    { this->_linkedList->add_first(node); }

    void push(T item)
    {
        Node<T> *newNode = new Node<T>(item);
        push(newNode);
    };

    void pop() override
    {
        try {
            this->_linkedList->remove_first();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }

    }

    void clear() override
    {
        try {
            this->_linkedList->clear_all();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

    T peek() override
    {
        try{
            return this->_linkedList->get_head_value();
        }
        catch(std::out_of_range& ex)
        {
            std::cout << "\nError: " << ex.what() << "\n";
        }
    }

};