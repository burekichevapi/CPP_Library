#include <iostream>
#include "ILinkedList.h"
#include "Node.h"

template <class T>
class LinkedList : public ILinkedList<T>
{

public:
    LinkedList(Node<T> *head)
    {
        this->_head = head;
        this->_tail = head;
        this->number_of_nodes = 1;
    }

    LinkedList(T item)
    {
        auto *head = new Node<T>(item);
        this->_head = head;
        this->_tail = head;
        this->number_of_nodes = 1;
    }

    unsigned int get_number_of_nodes() override
    { return this->number_of_nodes; }

    void print_all() override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

        Node<T> *temp = this->_head;

        while (true)
        {
            if (this->next_is_null(temp))
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
        while(!this->is_null(this->_head))
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

    void add_first(T item) override
    {
        auto *newNode = new Node<T>(item);
        add_first(newNode);
    }

    void add_last(Node<T> *newNode) override
    {
        if(this->empty())
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

    void add_last(T item) override
    {
        auto *newNode = new Node<T>(item);
        add_last(newNode);
    }

    void remove_first() override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

        this->_head = this->_head->get_next_node();
        this->number_of_nodes--;
    }

    void remove_last() override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

        Node<T> *temp = this->_head;

        while(temp != this->_tail && temp->get_next_node() != this->_tail)
            temp = temp->get_next_node();

        temp->set_next_node(nullptr);

        this->_tail = temp;

        this->number_of_nodes--;
    }

    bool contains(T value) override
    {
        if(this->empty())
            return false;

        Node<T> *temp = this->_head;

        while(!this->is_null(temp))
        {
            if(temp->get_value() == value)
                return true;

            temp = temp->get_next_node();
        }

        return false;
    }

    void remove_by_value(T value) override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

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

        while(!this->next_is_null(current))
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

    T get_head_value() override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

        return this->_head->get_value();
    }

    T get_tail_value() override
    {
        if (this->empty())
            throw std::out_of_range("List is Empty.");

        return this->_tail->get_value();
    }
};