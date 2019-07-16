#include <iostream>
#include "ILinkedList.h"
#include "LinkedNode.h"

template <class T>
class LinkedList : public ILinkedList<T>
{
public:
    LinkedList(LinkedNode<T> *head)
    {
        this->_head = head;
        this->_tail = head;
        this->_size = 1;
    }

    LinkedList(T item) : LinkedList(new LinkedNode<T>(item)){}

    unsigned int GetSize() override
    { return this->_size; }

    void PrintAll() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        LinkedNode<T> *temp = this->_head;

        while(true)
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
        while(!this->isNull(this->_head))
        {
            LinkedNode<T> *temp = this->_head;
            this->_head = this->_head->GetNextNode();
            temp = nullptr;
            delete(temp);
        }
        this->_size = 0;
    }

    void AddFirst(LinkedNode<T> *newNode) override
    {
        LinkedNode<T> *temp = this->_head;
        this->_head = newNode;
        this->_head->SetNextNode(temp);

        temp = nullptr;
        delete(temp);

        this->_size++;
    }

    void AddFirst(T item) override
    { AddFirst(new LinkedNode<T>(item)); }

    void AddLast(LinkedNode<T> *newNode) override
    {
        if(this->IsEmpty())
        {
            AddFirst(newNode);
            return;
        }

        LinkedNode<T> *temp = this->_tail;
        temp->SetNextNode(newNode);
        this->_tail = temp->GetNextNode();

        temp = nullptr;
        delete(temp);

        this->_size++;
    }

    void AddLast(T item) override
    { AddLast(new LinkedNode<T>(item)); }

    void RemoveFirst() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        this->_head = this->_head->GetNextNode();
        this->_size--;
    }

    void RemoveLast() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        LinkedNode<T> *temp = this->_head;

        while(temp != this->_tail && temp->GetNextNode() != this->_tail)
            temp = temp->GetNextNode();

        temp->SetNextNode(nullptr);

        this->_tail = temp;

        this->_size--;
    }

    bool Contains(T value) override
    {
        if(this->IsEmpty())
            return false;

        LinkedNode<T> *temp = this->_head;

        while(!this->isNull(temp))
        {
            if(temp->GetValue() == value)
                return true;

            temp = temp->GetNextNode();
        }

        return false;
    }

    void RemoveByValue(T value) override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        if(this->_head->GetValue() == value)
            RemoveFirst();
        else if(this->_tail->GetValue() == value)
            RemoveLast();
        else
        {
            LinkedNode<T> *previous = this->_head;
            LinkedNode<T> *current = this->_head->GetNextNode();

            while(!this->nextIsNull(current))
            {
                if(current->GetValue() == value)
                {
                    previous->SetNextNode(current->GetNextNode());
                    current = nullptr;
                    delete(current);
                    this->_size--;
                    break;
                }

                previous = current;
                current = current->GetNextNode();
            }
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

    void InsertAt(unsigned int index, T item) override
    {
        if(index > this->_size || index < 0)
            throw std::out_of_range("Index is out of range.");

        if(index == 0)
            AddFirst(item);
        else if(index == this->_size)
            AddLast(item);
        else
        {
            auto *current = this->_head;

            for(unsigned int i = 1; i < index; i++)
                current = current->GetNextNode();

            auto *temp = current;
            current = new LinkedNode<T>(item);
            current->SetNextNode(temp->GetNextNode());
            temp->SetNextNode(current);
        }
    }
};