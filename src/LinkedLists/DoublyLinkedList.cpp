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

        this->_head->SerPreviousNode(this->_previous);
        this->_head->SetNextNode(this->_tail);

        this->_tail->SerPreviousNode(this->_head);
        this->_tail->SetNextNode(nullptr);

        this->_previous = nullptr;
        this->_size = 2;
    }

    DoublyLinkedList<T>(T head, T tail)
    {
        this->_head = new Node<T>(head);
        this->_tail = new Node<T>(tail);

        this->_head->SerPreviousNode(this->_previous);
        this->_head->SetNextNode(this->_tail);

        this->_tail->SerPreviousNode(this->_head);
        this->_tail->SetNextNode(nullptr);

        this->_previous = nullptr;
        this->_size = 2;
    }

    unsigned int GetSize() override
    { return this->_size; }

    void PrintAll() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        Node<T> *temp = this->_head;

        while (true)
        {
            if (this->nextIsNull(temp))
            {
                std::cout << temp->GetValue() << std::endl;
                break;
            }

            std::cout << temp->GetValue() << std::endl;
            temp = temp->GetNextNode();
        }
    }

    void Clear() override
    {
        while (!this->isNull(this->_head))
        {
            Node<T> *temp = this->_head;
            this->_head = this->_head->GetNextNode();
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

        this->_head->SetNextNode(temp);
        temp->SerPreviousNode(this->_head);
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
        temp->SetNextNode(newNode);
        this->_tail = temp->GetNextNode();
        this->_tail->SerPreviousNode(temp);

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
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        this->_head = this->_head->GetNextNode();
        this->_size--;

        if(this->isNull(this->_head))
            return;

        this->_head->SerPreviousNode(nullptr);

    }

    void RemoveLast() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        if(this->isNull(this->_head->GetNextNode()))
        {
            this->_head = nullptr;
            this->_size--;
            return;
        }

        this->_tail = this->_tail->GetPreviousNode();
        this->_tail->SetNextNode(nullptr);

        this->_size--;
    }

    bool Contains(T value) override
    {
        Node<T> *temp = this->_head;

        while (!this->isNull(temp))
        {
            if (temp->GetValue() == value)
                return true;

            temp = temp->GetNextNode();
        }

        return false;
    }

    void RemoveByValue(T value) override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        if (this->_head->GetValue() == value)
        {
            RemoveFirst();
            return;
        }

        if (this->_tail->GetValue() == value)
        {
            RemoveLast();
            return;
        }

        Node<T> *previous = this->_head;
        Node<T> *current = this->_head->GetNextNode();

        while (!this->isNull(current))
        {
            if (current->GetValue() == value)
            {
                previous->SetNextNode(current->GetNextNode());
                current->GetNextNode()->SerPreviousNode(previous);
                this->_size--;
                break;
            }

            previous = current;
            current = current->GetNextNode();
        }
    }

    T GetHeadValue() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        return this->_head->GetValue();
    }

    T GetTailValue() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        return this->_tail->GetValue();
    }
};