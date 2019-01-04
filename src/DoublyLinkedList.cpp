#include <iostream>
#include "ILinkedList.h"
#include "Node.h"

template <class T>
class DoublyLinkedList: public ILinkedList<T>
{

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
        this->_size = 2;
    }

    DoublyLinkedList<T>(T head, T tail)
    {
        this->_head = new Node<T>(head);
        this->_tail = new Node<T>(tail);

        this->_head->set_previous_node(this->_previous);
        this->_head->set_next_node(this->_tail);

        this->_tail->set_previous_node(this->_head);
        this->_tail->set_next_node(nullptr);

        this->_previous = nullptr;
        this->_size = 2;
    }

    unsigned int GetSize() override
    { return this->_size; }

    void PrintAll() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        Node<T> *temp = this->_head;

        while (true)
        {
            if (this->nextIsNull(temp))
            {
                std::cout << temp->get_value() << std::endl;
                break;
            }

            std::cout << temp->get_value() << std::endl;
            temp = temp->get_next_node();
        }
    }

    void Clear() override
    {
        while (!this->isNull(this->_head))
        {
            Node<T> *temp = this->_head;
            this->_head = this->_head->get_next_node();
            temp = nullptr;
            delete (temp);
        }

        this->_size = 0;
    }

    void AddFirst(Node<T> *newNode) override
    {
        Node<T> *temp = this->_head;
        this->_head = newNode;

        if(this->isNull(temp)){
            this->_tail = this->_head;
            delete(temp);
            this->_size++;
            return;
        }

        this->_head->set_next_node(temp);
        temp->set_previous_node(this->_head);
        this->_size++;

    }

    void AddFirst(T item) override
    {
        auto *newNode = new Node<T>(item);
        AddFirst(newNode);
    }


    void AddLast(Node<T> *newNode) override
    {

        Node<T> *temp = this->_tail;
        temp->set_next_node(newNode);
        this->_tail = temp->get_next_node();
        this->_tail->set_previous_node(temp);

        temp = nullptr;
        delete (temp);

        this->_size++;
    }

    void AddLast(T item) override
    {
        auto *newNode = new Node<T>(item);
        AddLast(newNode);
    }

    void RemoveFirst() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        this->_head = this->_head->get_next_node();
        this->_size--;

        if(this->isNull(this->_head))
            return;

        this->_head->set_previous_node(nullptr);

    }

    void RemoveLast() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        if(this->isNull(this->_head->get_next_node()))
        {
            this->_head = nullptr;
            this->_size--;
            return;
        }

        this->_tail = this->_tail->get_previous_node();
        this->_tail->set_next_node(nullptr);

        this->_size--;
    }

    bool Contains(T value) override
    {
        Node<T> *temp = this->_head;

        while (!this->isNull(temp))
        {
            if (temp->get_value() == value)
                return true;

            temp = temp->get_next_node();
        }

        return false;
    }

    void RemoveByValue(T value) override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        if (this->_head->get_value() == value)
        {
            RemoveFirst();
            return;
        }

        if (this->_tail->get_value() == value)
        {
            RemoveLast();
            return;
        }

        Node<T> *previous = this->_head;
        Node<T> *current = this->_head->get_next_node();

        while (!this->isNull(current))
        {
            if (current->get_value() == value)
            {
                previous->set_next_node(current->get_next_node());
                current->get_next_node()->set_previous_node(previous);
                this->_size--;
                break;
            }

            previous = current;
            current = current->get_next_node();
        }
    }

    T GetHeadValue() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        return this->_head->get_value();
    }

    T GetTailValue() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        return this->_tail->get_value();
    }
};