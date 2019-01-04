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
        this->_size = 1;
    }

    LinkedList(T item)
    {
        auto *head = new Node<T>(item);
        this->_head = head;
        this->_tail = head;
        this->_size = 1;
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
        while(!this->isNull(this->_head))
        {
            Node<T> *temp = this->_head;
            this->_head = this->_head->get_next_node();
            temp = nullptr;
            delete(temp);
        }
        this->_size = 0;
    }



    void AddFirst(Node<T> *newNode) override
    {
        Node<T> *temp = this->_head;
        this->_head = newNode;
        this->_head->set_next_node(temp);

        temp = nullptr;
        delete(temp);

        this->_size++;
    }

    void AddFirst(T item) override
    {
        auto *newNode = new Node<T>(item);
        AddFirst(newNode);
    }

    void AddLast(Node<T> *newNode) override
    {
        if(this->isEmpty())
        {
            AddFirst(newNode);
            return;
        }

        Node<T> *temp = this->_tail;
        temp->set_next_node(newNode);
        this->_tail = temp->get_next_node();

        temp = nullptr;
        delete(temp);

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
    }

    void RemoveLast() override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        Node<T> *temp = this->_head;

        while(temp != this->_tail && temp->get_next_node() != this->_tail)
            temp = temp->get_next_node();

        temp->set_next_node(nullptr);

        this->_tail = temp;

        this->_size--;
    }

    bool Contains(T value) override
    {
        if(this->isEmpty())
            return false;

        Node<T> *temp = this->_head;

        while(!this->isNull(temp))
        {
            if(temp->get_value() == value)
                return true;

            temp = temp->get_next_node();
        }

        return false;
    }

    void RemoveByValue(T value) override
    {
        if (this->isEmpty())
            throw std::out_of_range("List is Empty.");

        if(this->_head->get_value() == value)
        {
            RemoveFirst();
            return;
        }

        if(this->_tail->get_value() == value)
        {
            RemoveLast();
            return;
        }

        Node<T> *previous = this->_head;
        Node<T> *current = this->_head->get_next_node();

        while(!this->nextIsNull(current))
        {
            if(current->get_value() == value)
            {
                previous->set_next_node(current->get_next_node());
                current = nullptr;
                delete(current);
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