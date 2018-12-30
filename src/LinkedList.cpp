#include <iostream>
#include "ILinkedList.h"
#include "Node.h"

template <class T>
class LinkedList : public ILinkedList<T>
{
private:
    bool is_null(Node<T> *temp) override
    { return temp == nullptr; }

    bool next_is_null(Node<T> *temp) override
    { return temp->get_next_node() == nullptr; }

    bool empty()
    { return this->number_of_nodes == 0; }

public:
    LinkedList(Node<T> *head)
    {
        this->_head = head;
        this->_tail = head;
        this->number_of_nodes = 1;
    }

    unsigned int get_number_of_nodes() override
    { return this->number_of_nodes; }

    void print_all() override
    {
        if (empty())
        {
            std::cout << "List is empty..\n";
            return;
        }

        Node<T> *temp = this->_head;

        while (true)
        {
            if (next_is_null(temp))
            {
                std::cout << temp->get_value() << std::endl;
                break;
            }

            std::cout << temp->get_value() << std::endl;
            temp = temp->get_next_node();
        }
    }

    void clear_all() override
    {
        while(!is_null(this->_head))
        {
            Node<T> *temp = this->_head;
            this->_head = this->_head->get_next_node();
            temp = nullptr;
            delete(temp);
        }
        this->number_of_nodes = 0;
    }

    void add_first(Node<T> *newNode) override
    {
        Node<T> *temp = this->_head;
        this->_head = newNode;
        this->_head->set_next_node(temp);

        temp = nullptr;
        delete(temp);

        this->number_of_nodes++;
    }

    void add_last(Node<T> *newNode) override
    {
        if(empty())
        {
            add_first(newNode);
            return;
        }

        Node<T> *temp = this->_tail;
        temp->set_next_node(newNode);
        this->_tail = temp->get_next_node();

        temp = nullptr;
        delete(temp);

        this->number_of_nodes++;
    }

    void remove_first() override
    {
        if(empty())
            return;

        this->_head = this->_head->get_next_node();
        this->number_of_nodes--;
    }

    void remove_last() override
    {
        if(empty())
            return;

        Node<T> *temp = this->_head;

        while(temp->get_next_node() != this->_tail)
            temp = temp->get_next_node();

        temp->set_next_node(nullptr);

        this->_tail = temp;

        this->number_of_nodes--;
    }

    bool contains(T value) override
    {
        if(empty())
            return false;

        Node<T> *temp = this->_head;

        while(!is_null(temp))
        {
            if(temp->get_value() == value)
                return true;

            temp = temp->get_next_node();
        }

        return false;
    }

    void remove_by_value(T value) override
    {
        if(empty())
            return;

        if(this->_head->get_value() == value)
        {
            remove_first();
            return;
        }

        if(this->_tail->get_value() == value)
        {
            remove_last();
            return;
        }

        Node<T> *previous = this->_head;
        Node<T> *current = this->_head->get_next_node();

        while(!next_is_null(current))
        {
            if(current->get_value() == value)
            {
                previous->set_next_node(current->get_next_node());
                current = nullptr;
                delete(current);
                this->number_of_nodes--;
                break;
            }

            previous = current;
            current = current->get_next_node();
        }
    }
};