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
    { this->_linkedList->print_all(); }

    void push(Node<T> *node) override
    { this->_linkedList->add_first(node); }

    void pop() override
    { this->_linkedList->remove_first(); }

    void clear() override
    { this->_linkedList->clear_all(); }

};