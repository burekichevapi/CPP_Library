#include <iostream>
#include "ILinkedList.h"
#include "Node.h"

template <class T> class DoublyLinkedList: public ILinkedList<T>
{
private:
    bool is_null(Node<T> *temp) override
    { return temp == nullptr; }

    bool next_is_null(Node<T> *temp) override
    { return temp->get_next_node() == nullptr; }

    bool empty()
    { return this->number_of_nodes == 0; }
public:
    DoublyLinkedList<T>(Node<T> *head, Node<T> *tail)
    {
        this->_head = head;
        this->_tail = tail;

        this->_head->set_previous_node(this->_previous);
        this->_head->set_next_node(this->_tail);

        this->_tail->set_previous_node(this->_head);
        this->_tail->set_next_node(nullptr);

        this->_previous = nullptr;
        this->number_of_nodes = 2;
    }

    unsigned int get_number_of_nodes() override
    {
        return this->number_of_nodes;
    }

    void print_all() override
    {
        if (is_null(this->_head))
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
        while (!is_null(this->_head))
        {
            Node<T> *temp = this->_head;
            this->_head = this->_head->get_next_node();
            temp = nullptr;
            delete (temp);
        }

        this->number_of_nodes = 0;
    }

    void add_first(Node<T> *newNode) override
    {
        Node<T> *temp = this->_head;
        this->_head = newNode;

        if(is_null(temp)){
            this->_tail = this->_head;
            delete(temp);
            this->number_of_nodes++;
            return;
        }

        this->_head->set_next_node(temp);
        temp->set_previous_node(this->_head);
        this->number_of_nodes++;

    }

    void add_first(T item) override
    {
        auto *newNode = new Node<T>(item);
        add_first(newNode);
    }

    void add_last(Node<T> *newNode) override
    {

        Node<T> *temp = this->_tail;
        temp->set_next_node(newNode);
        this->_tail = temp->get_next_node();
        this->_tail->set_previous_node(temp);

        temp = nullptr;
        delete (temp);

        this->number_of_nodes++;
    }

    void add_last(T item) override
    {
        auto *newNode = new Node<T>(item);
        add_last(newNode);
    }

    void remove_first() override
    {
        if(is_null(this->_head))
            return;

        this->_head = this->_head->get_next_node();
        this->number_of_nodes--;

        if(is_null(this->_head))
            return;

        this->_head->set_previous_node(nullptr);

    }

    void remove_last() override
    {
        if(is_null(this->_head))
            return;

        if(is_null(this->_head->get_next_node()))
        {
            this->_head = nullptr;
            this->number_of_nodes--;
            return;
        }

        this->_tail = this->_tail->get_previous_node();
        this->_tail->set_next_node(nullptr);

        this->number_of_nodes--;
    }

    bool contains(T value) override
    {
        Node<T> *temp = this->_head;

        while (!is_null(temp))
        {
            if (temp->get_value() == value)
                return true;

            temp = temp->get_next_node();
        }

        return false;
    }

    void remove_by_value(T value) override
    {
        if (this->_head->get_value() == value)
        {
            remove_first();
            return;
        }

        if (this->_tail->get_value() == value)
        {
            remove_last();
            return;
        }

        Node<T> *previous = this->_head;
        Node<T> *current = this->_head->get_next_node();

        while (!is_null(current))
        {
            if (current->get_value() == value)
            {
                previous->set_next_node(current->get_next_node());
                current->get_next_node()->set_previous_node(previous);
                this->number_of_nodes--;
                break;
            }

            previous = current;
            current = current->get_next_node();
        }
    }

    T get_head_value() override
    {
        return this->_head->get_value();
    }

    T get_tail_value() override
    {
        return this->_tail->get_value();
    }
};